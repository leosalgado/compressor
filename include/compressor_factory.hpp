#pragma once
#include "compression_type.hpp"
#include "compressor.hpp"
#include "rle.hpp"
#include <memory>
#include <stdexcept>

class CompressorFactory {
public:
  static std::unique_ptr<Compressor> create(CompressionType type) {
    switch (type) {
    case CompressionType::RLE:
      return std::make_unique<RLECompressor>();
    default:
      throw std::invalid_argument("Unknown compression_type");
    }
  }
};
