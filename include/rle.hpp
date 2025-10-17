#pragma once
#include "compressor.hpp"
#include <filesystem>
#include <vector>

class RLECompressor : public Compressor {
public:
  void compress(const std::vector<std::filesystem::path> &files) override;
  void decompress(const std::vector<std::filesystem::path> &files) override;
};
