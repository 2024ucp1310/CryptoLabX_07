#include "frequency.hpp"

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
