#include "rle.hpp"
#include "utils.hpp"

#include <fstream>
#include <ios>
#include <iostream>

int main(int argc, char *argv[]) {
  const std::string INPUT_FILE = "../data/input.txt";
  const std::string COMPRESSED_OUTPUT = "../data/compressed_output.leo";

  std::string file_content = read_file(INPUT_FILE);

  if (file_content.empty())
    return 1;

  auto compressed_data = rle_compress(file_content);

  std::ofstream out(COMPRESSED_OUTPUT, std::ios::binary); // Avoid \r\n
  if (!out) {
    std::cerr << "Error creating file: " << COMPRESSED_OUTPUT << std::endl;
    return 1;
  }

  for (auto &c : compressed_data) {
    out << c.first << c.second;
  }

  return 0;
}
