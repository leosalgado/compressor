#pragma once
#include <string>
#include <utility>
#include <vector>

std::vector<std::pair<char, int>> rle_compress(const std::string &input);
std::string rle_decompress(const std::vector<std::pair<char, int>> &input);
