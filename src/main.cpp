#include "rle.hpp"
#include "utils.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
  const std::string INPUT_FILE = "../data/input.txt";
  const std::string COMPRESSED_OUTPUT = "../data/compressed_output.leo";
  const std::string DECOMPRESSED_OUTPUT = "../data/decompressed_output.txt";

  try {

    std::string file_content = read_file(INPUT_FILE);

    if (file_content.empty()) {
      throw std::runtime_error("Input file is empty: " + INPUT_FILE);
    }

    auto compressed_data = rle_compress(file_content);

    write_file(COMPRESSED_OUTPUT, compressed_data);

    auto compressed_read = read_binary_file(COMPRESSED_OUTPUT);
    auto decompressed = rle_decompress(compressed_read);

    save_text(DECOMPRESSED_OUTPUT, decompressed);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
