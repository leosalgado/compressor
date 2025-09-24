#include "utils.hpp"

#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::string read_file(const std::string &path) {
  std::ifstream in(path);

  if (!in) {
    throw std::runtime_error("Error opening file: " + path);
  }

  std::stringstream buffer;
  buffer << in.rdbuf();
  return buffer.str();
}

void write_file(const std::string &path,
                const std::vector<std::pair<char, int>> &data) {

  std::ofstream out(path, std::ios::binary); // Avoid \r\n

  if (!out) {
    throw std::runtime_error("Error creating file: " + path);
  }

  for (const auto &c : data) {
    out.put(c.first);
    out.write(reinterpret_cast<const char *>(&c.second), sizeof(int));
  }
}

std::vector<std::pair<char, int>> read_binary_file(const std::string &path) {
  std::ifstream in(path, std::ios::binary);

  if (!in) {
    throw std::runtime_error("Error opening file: " + path);
  }

  std::vector<std::pair<char, int>> data;
  while (true) {
    char ch;
    int count;
    if (!in.get(ch))
      break;
    if (!in.read(reinterpret_cast<char *>(&count), sizeof(int)))
      break;
    data.push_back({ch, count});
  }
  return data;
}

void save_text(const std::string &path, const std::string &data) {
  std::ofstream out(path, std::ios::binary);
  if (!out) {
    throw std::runtime_error("Error creating file: " + path);
  }

  out.write(data.data(), data.size());
}
