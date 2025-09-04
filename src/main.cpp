#include "rle.hpp"
#include "utils.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  const std::string INPUT_FILE = "../data/input.txt";

  std::string file_content = read_file(INPUT_FILE);

  if (file_content.empty())
    return 1;

  auto compressed_data = rle_compress(file_content);

  for (auto &c : compressed_data) {
    std::cout << c.first << "," << c.second << std::endl;
  }

  return 0;
}
