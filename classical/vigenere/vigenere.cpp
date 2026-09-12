#include "vigenere.hpp"

std::string vigenere_decrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext = "";
    int k_len = key.length();
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        int c = ciphertext[i] - 'A';
        int k = key[i % k_len] - 'A';
        int p = (c - k + 26) % 26;
        plaintext += static_cast<char>('A' + p);
    }
    return plaintext;
}

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext = "";
    int k_len = key.length();
    for (size_t i = 0; i < plaintext.length(); ++i) {
        int p = plaintext[i] - 'A';
        int k = key[i % k_len] - 'A';
        int c = (p + k) % 26;
        ciphertext += static_cast<char>('A' + c);
    }
    return ciphertext;
}

bool verify(const std::string& original, const std::string& plaintext, const std::string& key) {
    return vigenere_encrypt(plaintext, key) == original;
}
