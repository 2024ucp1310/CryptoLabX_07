#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string encryptText(string text, int key);
string decryptText(string text, int key);

struct Result {
    int score;
    int key;
    string plaintext;
};

vector<Result> dictionaryAttack(
    string ciphertext,
    string dictionaryFile);

struct ChiResult {
    double score;
    int key;
    string plaintext;
};

vector<ChiResult> chiSquareAttack(string ciphertext);


void dictionaryAttackDisplay(string ciphertext) {

    vector<Result> results =
        dictionaryAttack(
            ciphertext,
            "../dictionary/english_words.txt"
        );

    cout << "\nDICTIONARY ATTACK\n";

    for (int i = 0; i < 5 && i < results.size(); i++) {

        cout << "Key: "
             << results[i].key
             << " | Score: "
             << results[i].score
             << " | "
             << results[i].plaintext
             << endl;
    }

    cout << "\nBest Result\n";
    cout << "Key       : "
         << results[0].key << endl;

    cout << "Plaintext : "
         << results[0].plaintext << endl;

    cout << "Score     : "
         << results[0].score << endl;
}


void chiSquareDisplay(string ciphertext) {

    vector<ChiResult> results =
        chiSquareAttack(ciphertext);

    cout << "\nCHI-SQUARE ATTACK\n";

    for (int i = 0; i < 5 && i < results.size(); i++) {

        cout << fixed << setprecision(2);

        cout << "Key: "
             << results[i].key
             << " | Score: "
             << results[i].score
             << " | "
             << results[i].plaintext
             << endl;
    }

    cout << "\nBest Result\n";

    cout << "Key       : "
         << results[0].key << endl;

    cout << "Plaintext : "
         << results[0].plaintext << endl;

    cout << "Score     : "
         << results[0].score << endl;
}


void compareAttacks(string ciphertext) {

    vector<Result> dictionary =
        dictionaryAttack(
            ciphertext,
            "../dictionary/english_words.txt"
        );

    vector<ChiResult> chi =
        chiSquareAttack(ciphertext);

    cout << "\nCOMPARISON\n";

    cout << "\nDictionary Scoring\n";
    cout << "Key       : "
         << dictionary[0].key << endl;

    cout << "Plaintext : "
         << dictionary[0].plaintext << endl;

    cout << "\nChi-Square Analysis\n";
    cout << "Key       : "
         << chi[0].key << endl;

    cout << "Plaintext : "
         << chi[0].plaintext << endl;
}


int main() {

    int choice;

    while (true) {

        cout << "       SHIFT CIPHER CRYPTANALYSIS\n";

        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Dictionary Attack\n";
        cout << "4. Chi-Square Attack\n";
        cout << "5. Compare Both Attacks\n";
        cout << "6. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {

            string text;
            int key;

            cout << "Enter plaintext: ";
            getline(cin, text);

            cout << "Enter key (0-25): ";
            cin >> key;

            cout << "\nCiphertext: "
                 << encryptText(text, key)
                 << endl;
        }

        else if (choice == 2) {

            string text;
            int key;

            cout << "Enter ciphertext: ";
            getline(cin, text);

            cout << "Enter key (0-25): ";
            cin >> key;

            cout << "\nPlaintext: "
                 << decryptText(text, key)
                 << endl;
        }

        else if (choice == 3) {

            string ciphertext;

            cout << "Enter ciphertext: ";
            getline(cin, ciphertext);

            dictionaryAttackDisplay(ciphertext);
        }

        else if (choice == 4) {

            string ciphertext;

            cout << "Enter ciphertext: ";
            getline(cin, ciphertext);

            chiSquareDisplay(ciphertext);
        }

        else if (choice == 5) {

            string ciphertext;

            cout << "Enter ciphertext: ";
            getline(cin, ciphertext);

            compareAttacks(ciphertext);
        }

        else if (choice == 6) {
            break;
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}