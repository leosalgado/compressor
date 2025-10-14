#include "rle.hpp"
#include "utils.hpp"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void rle_compress(std::vector<std::filesystem::path> &files) {

  std::vector<uint8_t> output;

  // Header
  uint8_t compression_type = 1;
  output.push_back(compression_type);

  const uint8_t delimiter[2] = {0xFE, 0xED};

  for (size_t file_index = 0; file_index < files.size(); file_index++) {
    auto &file = files[file_index];
    auto bytes = read_bytes(file);

    if (bytes.empty()) {
      std::cerr << "File " << file << " is empty and couldn't be read."
                << std::endl;
      continue;
    }

    // File name and length
    std::string filename_string = file.filename().string();
    output.push_back(static_cast<uint8_t>(filename_string.size()));
    for (auto &character : filename_string) {
      output.push_back(static_cast<uint8_t>(character));
    }

    uint8_t current = bytes[0];
    uint8_t count = 1;

    for (size_t i = 1; i < bytes.size(); i++) {
      if (bytes[i] == current) {
        count++;
      } else {
        output.push_back(current);
        output.push_back(count);
        current = bytes[i];
        count = 1;
      }
    }

    output.push_back(current);
    output.push_back(count);

    // File delimiter
    if (file_index < files.size() - 1) {
      output.push_back(delimiter[0]);
      output.push_back(delimiter[1]);
    }
  }

  files[0].replace_extension(".leo");
  write_bytes(files[0], output);
}

void rle_decompress(std::vector<std::filesystem::path> &files) {
  for (auto &file : files) {
    std::ifstream ifs(file, std::ios::binary);

    if (!ifs) {
      std::cerr << "Unable to open the file: " << file << std::endl;
      continue;
    }

    std::vector<uint8_t> compressed_data((std::istreambuf_iterator<char>(ifs)),
                                         std::istreambuf_iterator<char>());

    size_t index = 1;

    while (index < compressed_data.size()) {
      if (index + 1 >= compressed_data.size()) {
        break;
      }

      uint8_t filename_length = compressed_data[index++];

      std::string filename(reinterpret_cast<char *>(&compressed_data[index]),
                           filename_length);
      index += filename_length;

      std::filesystem::path path = file.parent_path() / filename;
      std::vector<uint8_t> output_data;

      while (index + 1 < compressed_data.size()) {
        // EOF
        if (compressed_data[index] == 0xFE &&
            compressed_data[index + 1] == 0xED) {
          index += 2;
          break;
        }

        uint8_t byte_value = compressed_data[index++];
        if (index >= compressed_data.size()) {
          break;
        }
        uint8_t count = compressed_data[index++];

        output_data.insert(output_data.end(), count, byte_value);
      }

      write_bytes(path, output_data);
    }
  }
}
