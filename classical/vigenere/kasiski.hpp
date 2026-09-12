#ifndef KASISKI_HPP
#define KASISKI_HPP

#include <string>
#include <vector>
#include <map>


std::string clean_ciphertext(const std::string& raw_text);

std::map<std::string, std::vector<int>> find_repeated_patterns(const std::string& text, int seq_len = 3);

std::vector<int> calculate_distances(const std::map<std::string, std::vector<int>>& patterns);

std::map<int, int> find_factors(const std::vector<int>& distances, int max_key_len = 16);

int kasiski_analysis(const std::string& text);

#endif
