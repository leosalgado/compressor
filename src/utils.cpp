#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::string read_file(const std::string &path) {
  std::ifstream in(path);

  if (!in) {
    std::cerr << "Error opening file: " << path << std::endl;
    return "";
  }

  std::stringstream buffer;
  buffer << in.rdbuf();
  return buffer.str();
}
