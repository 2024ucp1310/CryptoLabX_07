#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <string>
#include <vector>


double calculate_ic(const std::string& text);

std::vector<std::string> split_into_groups(const std::string& text, int key_length);

std::vector<double> frequency_analysis(const std::string& group);

int find_shift(const std::string& group);

std::string find_key(const std::vector<std::string>& groups);

#endif
