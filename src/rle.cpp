#include "rle.hpp"

#include <string>
#include <utility>
#include <vector>

std::vector<std::pair<char, int>> rle_compress(const std::string &input) {

  std::vector<std::pair<char, int>> output;

  if (input.empty())
    return output;

  char current = input[0];
  int count = 1;

  for (size_t i = 1; i < input.size(); i++) {
    if (input[i] == current) {
      count++;
    } else {
      output.push_back({current, count});
      current = input[i];
      count = 1;
    }
  }
  output.push_back({current, count});
  return output;
}

std::string rle_decompress(const std::vector<std::pair<char, int>> &input) {

  std::string output;

  for (const auto &p : input) {
    output.append(p.second, p.first);
  }

  return output;
}
