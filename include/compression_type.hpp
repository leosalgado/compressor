#pragma once
#include <cstdint>
#include <stdexcept>

enum class CompressionType : uint8_t { RLE = 1 };

inline CompressionType compression_type_from_string(const std::string &name) {
  if (name == "rle")
    return CompressionType::RLE;
  throw std::invalid_argument("Unknown compression algorithm: " + name);
}
