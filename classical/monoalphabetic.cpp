#include<bits/stdc++.h>



using namespace std;

string encryptText(string plaintext, string key)
{
    string ciphertext = "";

    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char upper = toupper(c);

            int index = upper - 'A';

            char encrypted = key[index];

            if (islower(c))
                encrypted = tolower(encrypted);

            ciphertext += encrypted;
        }
        else
        {

            ciphertext += c;
        }
    }

    return ciphertext;
}

void frequency_analysis(string ciphertext)
{
    int frequency[26] = {0};
    int totalLetters = 0;

    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            frequency[c - 'A']++;
            totalLetters++;
        }
    }

    vector<pair<char, int>> letters;

    for (char c = 'A'; c <= 'Z'; c++)
    {
        letters.push_back({c, frequency[c - 'A']});
    }

    sort(letters.begin(), letters.end(),
         [](pair<char, int> a, pair<char, int> b)
         {
             return a.second > b.second;
         });

    cout << "\n===== FREQUENCY ANALYSIS =====\n";

    cout << "Letter\tCount\tPercentage\n";

    for (auto x : letters)
    {
        if (x.second > 0)
        {
            double percentage =
                (double)x.second / totalLetters * 100;

            cout << x.first << "\t"
                 << x.second << "\t"
                 << percentage << "%\n";
        }
    }

    cout << "\nMost frequent letters:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << letters[i].first << " ";
    }

    cout << "\n";
}

int main()
{

    ifstream input("../datasets/plaintext.txt");

    if (!input)
    {
        cout << "Cannot open plaintext.txt" << endl;
        return 1;
    }

    string plaintext;
    string line;

    while (getline(input, line))
    {
        plaintext += line + "\n";
    }

    input.close();


    string key;

    cout << "Enter 26-letter substitution key: ";
    cin >> key;


    for (char &c : key)
        c = toupper(c);


    if (key.length() != 26)
    {
        cout << "Key must contain exactly 26 letters." << endl;
        return 1;
    }


    string ciphertext = encryptText(plaintext, key);


    ofstream output("../outputs/ciphertext.txt");

    if (!output)
    {
        cout << "Cannot create ciphertext.txt" << endl;
        return 1;
    }

    output << ciphertext;

    output.close();

    cout << "\nEncryption successful!" << endl;
    cout << "Ciphertext saved in outputs/ciphertext.txt" << endl;
	
    frequency_analysis(ciphertext);
    return 0;
}
