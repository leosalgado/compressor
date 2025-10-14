#pragma once
#include <filesystem>
#include <vector>

void rle_compress(std::vector<std::filesystem::path> &files);

void rle_decompress(std::vector<std::filesystem::path> &files);
