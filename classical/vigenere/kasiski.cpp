#include "kasiski.hpp"
#include <cctype>
#include <algorithm>

std::string clean_ciphertext(const std::string& raw_text) {
    std::string cleaned = "";
    for (char c : raw_text) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            cleaned += std::toupper(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

std::map<std::string, std::vector<int>> find_repeated_patterns(const std::string& text, int seq_len) {
    std::map<std::string, std::vector<int>> all_patterns;
    if (text.length() < static_cast<size_t>(seq_len)) return all_patterns;

    for (size_t i = 0; i <= text.length() - seq_len; ++i) {
        std::string sub = text.substr(i, seq_len);
        all_patterns[sub].push_back(static_cast<int>(i));
    }

    std::map<std::string, std::vector<int>> repeated;
    for (const auto& pair : all_patterns) {
        if (pair.second.size() > 1) {
            repeated[pair.first] = pair.second;
        }
    }
    return repeated;
}

std::vector<int> calculate_distances(const std::map<std::string, std::vector<int>>& patterns) {
    std::vector<int> distances;
    for (const auto& pair : patterns) {
        const auto& pos = pair.second;
        for (size_t i = 0; i < pos.size(); ++i) {
            for (size_t j = i + 1; j < pos.size(); ++j) {
                distances.push_back(pos[j] - pos[i]);
            }
        }
    }
    return distances;
}

std::map<int, int> find_factors(const std::vector<int>& distances, int max_key_len) {
    std::map<int, int> factor_counts;
    for (int d : distances) {
        for (int f = 2; f <= max_key_len; ++f) {
            if (d % f == 0) {
                factor_counts[f]++;
            }
        }
    }
    return factor_counts;
}

int kasiski_analysis(const std::string& text) {
    auto patterns = find_repeated_patterns(text, 3);
    auto distances = calculate_distances(patterns);
    auto factors = find_factors(distances, 16);

    int best_len = 2;
    int max_count = 0;
    for (const auto& pair : factors) {
        if (pair.second > max_count) {
            max_count = pair.second;
            best_len = pair.first;
        }
    }
    return best_len;
}
