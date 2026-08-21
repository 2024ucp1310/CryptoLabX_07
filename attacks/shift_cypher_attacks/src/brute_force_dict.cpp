#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string decryptText(string text, int key);

unordered_set<string> loadDictionary(string filename) {
    unordered_set<string> dictionary;
    ifstream file(filename);

    string word;

    while (getline(file, word)) {
        for (char &ch : word)
            ch = tolower(ch);

        if (!word.empty())
            dictionary.insert(word);
    }

    return dictionary;
}

int dictionaryScore(string text,
                    const unordered_set<string>& dictionary) {

    stringstream ss(text);
    string word;
    int score = 0;

    while (ss >> word) {

        string cleanWord = "";

        for (char ch : word) {
            if (isalpha(ch))
                cleanWord += tolower(ch);
        }

        if (dictionary.count(cleanWord))
            score++;
    }

    return score;
}

struct Result {
    int score;
    int key;
    string plaintext;
};

vector<Result> dictionaryAttack(
    string ciphertext,
    string dictionaryFile) {

    unordered_set<string> dictionary =
        loadDictionary(dictionaryFile);

    vector<Result> results;

    for (int key = 0; key < 26; key++) {

        string plaintext = decryptText(ciphertext, key);

        int score =
            dictionaryScore(plaintext, dictionary);

        results.push_back({score, key, plaintext});
    }

    sort(results.begin(), results.end(),
        [](const Result& a, const Result& b) {

            if (a.score != b.score)
                return a.score > b.score;

            return a.key < b.key;
        });

    return results;
}