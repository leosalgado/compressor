#include "utils.hpp"

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<uint8_t> read_bytes(const std::filesystem::path &path) {
  std::ifstream in(path, std::ios::binary);

  if (!in) {
    throw std::runtime_error("Error opening file: " + path.string());
  }

  auto size = std::filesystem::file_size(path);
  std::vector<uint8_t> data(size);

  in.read(reinterpret_cast<char *>(data.data()), size);

  if (in.gcount() != size) {
    throw std::runtime_error("Error: Couldn't read all bytes from: " +
                             path.string());
  }

  return data;
}

void write_bytes(const std::filesystem::path &path,
                 const std::vector<uint8_t> &data) {

  std::ofstream out(path, std::ios::binary); // Avoid \r\n

  if (!out) {
    throw std::runtime_error("Error creating file: " + path.string());
  }

  out.write(reinterpret_cast<const char *>(data.data()),
            data.size() * sizeof(uint8_t));
}
