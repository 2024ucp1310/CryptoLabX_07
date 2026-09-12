#ifndef VIGENERE_HPP
#define VIGENERE_HPP

#include <string>


std::string vigenere_decrypt(const std::string& ciphertext, const std::string& key);

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key);

bool verify(const std::string& original, const std::string& plaintext, const std::string& key);

#endif
