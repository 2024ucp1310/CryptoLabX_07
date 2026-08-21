#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptText(string text, int key) {
    string result = "";

    key = key % 26;

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += char((ch - base + key) % 26 + base);
        } else {
            result += ch;
        }
    }

    return result;
}

string decryptText(string text, int key) {
    return encryptText(text, 26 - (key % 26));
}