#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

string decryptText(string text, int key);

double englishFreq[26] = {
    8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507,
    1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974,
    0.074
};

double chiSquare(string text) {

    int frequency[26] = {0};
    int total = 0;

    for (char ch : text) {

        if (isalpha(ch)) {

            ch = tolower(ch);

            frequency[ch - 'a']++;
            total++;
        }
    }

    if (total == 0)
        return 1e9;

    double score = 0.0;

    for (int i = 0; i < 26; i++) {

        double expected =
            total * englishFreq[i] / 100.0;

        if (expected > 0) {

            score +=
                pow(frequency[i] - expected, 2)
                / expected;
        }
    }

    return score;
}

struct ChiResult {
    double score;
    int key;
    string plaintext;
};

vector<ChiResult> chiSquareAttack(string ciphertext) {

    vector<ChiResult> results;

    for (int key = 0; key < 26; key++) {

        string plaintext =
            decryptText(ciphertext, key);

        double score =
            chiSquare(plaintext);

        results.push_back({
            score,
            key,
            plaintext
        });
    }

    sort(results.begin(), results.end(),
        [](const ChiResult& a,
           const ChiResult& b) {

            return a.score < b.score;
        });

    return results;
}