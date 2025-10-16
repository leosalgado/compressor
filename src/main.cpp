#include "rle.hpp"

#include <cstdint>
#include <cstring>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  std::vector<std::filesystem::path> inputFiles;

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0]
              << " compress|decompress <file1> <file2> ... <fileN>"
              << std::endl;
    return 1;
  }

  for (int i = 2; i < argc; ++i) {
    if (!(std::filesystem::exists(argv[i]))) {
      std::cerr << "\"" << argv[i] << "\"" << " file doesn't exist."
                << std::endl;
      return 1;
    }
    inputFiles.emplace_back(argv[i]);
  }

  std::ifstream ifs(inputFiles[0], std::ios::binary);
  uint8_t firstByte;
  ifs.read(reinterpret_cast<char *>(&firstByte), 1);

  try {
    if (strcmp(argv[1], "compress") == 0) {
      rle_compress(inputFiles);
    } else if (strcmp(argv[1], "decompress") == 0) {
      if (firstByte == 1) {
        rle_decompress(inputFiles);
      } else {
        std::cerr << "File not recognized." << std::endl;
      }
    } else {
      std::cerr << "Invalid: choose a mode between compresss|decompress."
                << std::endl;
      return 1;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
