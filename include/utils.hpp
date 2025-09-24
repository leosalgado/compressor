#pragma once
#include <string>
#include <vector>

std::string read_file(const std::string &path);

void write_file(const std::string &path,
                const std::vector<std::pair<char, int>> &data);

std::vector<std::pair<char, int>> read_binary_file(const std::string &path);

void save_text(const std::string &path, const std::string &data);
