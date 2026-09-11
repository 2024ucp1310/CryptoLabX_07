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

void word_frequency_analysis(string ciphertext)
{
    map<string, int> frequency;

    string word = "";

    for (int i = 0; i <= ciphertext.length(); i++)
    {
        char c;

        if (i < ciphertext.length())
            c = ciphertext[i];
        else
            c = ' ';

        if (isalpha(c))
        {
            word += toupper(c);
        }
        else
        {
            if (!word.empty())
            {
                frequency[word]++;
                word = "";
            }
        }
    }


    vector<pair<string, int>> words;

    for (auto x : frequency)
    {
        words.push_back(x);
    }

    sort(words.begin(), words.end(),
         [](pair<string, int> a, pair<string, int> b)
         {
             return a.second > b.second;
         });

    cout << "\n===== WORD FREQUENCY ANALYSIS =====\n";

    cout << "\nMost repeated words:\n";

    for (int i = 0; i < words.size() && i < 20; i++)
    {
        cout << words[i].first
             << " -> "
             << words[i].second
             << endl;
    }

    cout << "\nOne-letter words:\n";

    for (auto x : words)
    {
        if (x.first.length() == 1)
        {
            cout << x.first << " -> "
                 << x.second << endl;
        }
    }

    cout << "\nTwo-letter words:\n";

    for (auto x : words)
    {
        if (x.first.length() == 2)
        {
            cout << x.first << " -> "
                 << x.second << endl;
        }
    }

    cout << "\nThree-letter words:\n";

    for (auto x : words)
    {
        if (x.first.length() == 3)
        {
            cout << x.first << " -> "
                 << x.second << endl;
        }
    }
}

string getPattern(string word)
{
    map<char, int> patternNumber;

    string pattern = "";

    int nextNumber = 0;

    for (char c : word)
    {
        if (patternNumber.find(c) == patternNumber.end())
        {
            patternNumber[c] = nextNumber;
            nextNumber++;
        }

        pattern += char('0' + patternNumber[c]);
    }

    return pattern;
}

void pattern_analysis(string ciphertext)
{
    map<string, vector<string>> patterns;

    string word = "";

    for (int i = 0; i <= ciphertext.length(); i++)
    {
        char c;

        if (i < ciphertext.length())
            c = ciphertext[i];
        else
            c = ' ';

        if (isalpha(c))
        {
            word += toupper(c);
        }
        else
        {
            if (!word.empty())
            {
                string pattern = getPattern(word);

                patterns[pattern].push_back(word);

                word = "";
            }
        }
    }

    cout << "\n===== PATTERN ANALYSIS =====\n";

    for (auto x : patterns)
    {
        if (x.second.size() > 1)
        {
            cout << "Pattern " << x.first << " : ";

            for (string word : x.second)
            {
                cout << word << " ";
            }

            cout << "\n";
        }
    }
}

string decryptWithKey(string ciphertext, map<char, char> key)
{
    string plaintext = "";

    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            char upper = toupper(c);

            if (key.find(upper) != key.end())
            {
                char decrypted = key[upper];

                if (islower(c))
                    decrypted = tolower(decrypted);

                plaintext += decrypted;
            }
            else
            {
                plaintext += '_';
            }
        }
        else
        {
            plaintext += c;
        }
    }

    return plaintext;
}

void showWordMappings(string ciphertext, map<char, char> key)
{
    string word = "";

    for (int i = 0; i <= ciphertext.length(); i++)
    {
        char c;

        if (i < ciphertext.length())
            c = ciphertext[i];
        else
            c = ' ';

        if (isalpha(c))
        {
            word += toupper(c);
        }
        else
        {
            if (!word.empty())
            {
                string decrypted = "";

                for (char x : word)
                {
                    if (key.find(x) != key.end())
                        decrypted += key[x];
                    else
                        decrypted += '_';
                }

                if (decrypted.find('_') != string::npos)
                {
                    cout << word << " -> "
                         << decrypted << endl;
                }

                word = "";
            }
        }
    }
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
    word_frequency_analysis(ciphertext);
    pattern_analysis(ciphertext);
    
    map<char, char> key_;

	key_['A'] = 'K';
	key_['B'] = 'X';
	key_['C'] = 'V';
	key_['D'] = 'M';
	key_['E'] = 'C';
	key_['F'] = 'N';
	key_['G'] = 'O';
	key_['H'] = 'P';
	key_['I'] = 'H';
	key_['J'] = 'Q';
	key_['K'] = 'R';
	key_['L'] = 'S';
	key_['N'] = 'Y';
	key_['O'] = 'I';
	key_['Q'] = 'A';
	key_['R'] = 'D';
	key_['S'] = 'L';
	key_['T'] = 'E';
	key_['U'] = 'G';
	key_['V'] = 'W';
	key_['W'] = 'B';
	key_['X'] = 'U';
	key_['Y'] = 'F';
	key_['Z'] = 'T';

	// Test hypothesis
	key_['M'] = 'J';
	key_['P'] = 'Z';


	string partialPlaintext = decryptWithKey(ciphertext, key_);

	cout << "\n===== PARTIAL PLAINTEXT =====\n";
	cout << partialPlaintext << endl;
	
	cout << "\n===== CIPHERTEXT TO PARTIAL PLAINTEXT =====\n";
	showWordMappings(ciphertext, key_);
    
    return 0;
}
