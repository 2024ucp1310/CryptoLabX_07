#include "frequency.hpp"

const double ENGLISH_FREQ[26] = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074
};

int find_shift(const std::string& group) {
    int n = group.length();
    int counts[26] = {0};
    for (char c : group) counts[c - 'A']++;

    int best_shift = 0;
    double min_chi_sq = 1e9;

    for (int s = 0; s < 26; ++s) {
        double chi_sq = 0.0;
        for (int i = 0; i < 26; ++i) {
            double observed = counts[(i + s) % 26];
            double expected = n * ENGLISH_FREQ[i];
            chi_sq += ((observed - expected) * (observed - expected)) / expected;
        }
        if (chi_sq < min_chi_sq) {
            min_chi_sq = chi_sq;
            best_shift = s;
        }
    }
    return best_shift;
}

std::string find_key(const std::vector<std::string>& groups) {
    std::string key = "";
    for (const auto& group : groups) {
        int shift = find_shift(group);
        key += static_cast<char>('A' + shift);
    }
    return key;
}

double calculate_ic(const std::string& text) {
    int n = text.length();
    if (n <= 1) return 0.0;

    int counts[26] = {0};
    for (char c : text) {
        counts[c - 'A']++;
    }

    double sum = 0.0;
    for (int i = 0; i < 26; ++i) {
        sum += static_cast<double>(counts[i]) * (counts[i] - 1);
    }
    return sum / (static_cast<double>(n) * (n - 1));
}

std::vector<std::string> split_into_groups(const std::string& text, int key_length) {
    std::vector<std::string> groups(key_length, "");
    for (size_t i = 0; i < text.length(); ++i) {
        groups[i % key_length] += text[i];
    }
    return groups;
}

std::vector<double> frequency_analysis(const std::string& group) {
    std::vector<double> freq(26, 0.0);
    if (group.empty()) return freq;
    for (char c : group) freq[c - 'A']++;
    for (int i = 0; i < 26; ++i) freq[i] /= group.length();
    return freq;
}
