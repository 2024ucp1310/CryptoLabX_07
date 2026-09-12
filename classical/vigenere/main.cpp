#include <iostream>
#include <iomanip>
#include "kasiski.hpp"
#include "frequency.hpp"
#include "vigenere.hpp"

using namespace std;

int main() {
    string raw_input = 
        "DAZFI SFSPA VQLSN PXYSZ WXALC DAFGQ UISMT PHZGA MKTTF TCCFX "
        "KFCRG GLPFE TZMMM ZOZDE ADWVZ WMWKV GQSOH QSVHP WFKLS LEASE "
        "PWHMJ EGKPU RVSXJ XVBWV POSDE TEQTX OBZIK WCXLW NUOVJ MJCLL "
        "OEOFA ZENVM JILOW ZEKAZ EJAQD ILSWW ESGUG KTZGQ ZVRMN WTQSE "
        "OTKTK PBSTA MQVER MJEGL JQRTL GFJYG SPTZP GTACM OECBX SESCI "
        "YGUFP KVILL TWDKS ZODFW FWEAA PQTFS TQIRG MPMEL RYELH QSVWB "
        "AWMOS DELHM UZGPG YEKZU KWTAM ZJMLS EVJQT GLAWV OVVXH KWQIL "
        "IEUYS ZWXAH HUSZO GMUZQ CIMVZ UVWIF JJHPW VXFSE TZEDF";


    string cleaned = clean_ciphertext(raw_input);
    int key_len = kasiski_analysis(cleaned);
    
    double max_ic = 0.0;
    int refined_len = key_len;
    for (int k = 2; k <= 16; ++k) {
        auto grps = split_into_groups(cleaned, k);
        double total_ic = 0.0;
        for (const auto& g : grps) total_ic += calculate_ic(g);
        double avg_ic = total_ic / k;
        if (avg_ic > max_ic) {
            max_ic = avg_ic;
            refined_len = k;
        }
    }
    key_len = refined_len;


    vector<string> groups = split_into_groups(cleaned, key_len);

    string recovered_key = find_key(groups);

    string plaintext = vigenere_decrypt(cleaned, recovered_key);

    cout << "       CRYPTANALYSIS REPORT             \n";
    cout << "Estimated Key Length: " << key_len << "\n\n";

    cout << "Frequency Table for Each Group (%):\n";
    cout << "       ";
    for (char c = 'A'; c <= 'Z'; ++c) cout << c << "    ";
    cout << "\n" << string(135, '-') << "\n";

    for (int i = 0; i < key_len; ++i) {
        vector<double> freqs = frequency_analysis(groups[i]);
        cout << "Grp " << setw(2) << (i + 1) << ": ";
        for (double f : freqs) {
            cout << fixed << setprecision(1) << setw(4) << (f * 100.0) << " ";
        }
        cout << "\n";
    }

    cout << "\nRecovered Key: " << recovered_key << "\n";
    cout << "\nRecovered Plaintext:\n" << plaintext << "\n\n";

    cout << "             VERIFICATION               \n";
    bool valid = verify(cleaned, plaintext, recovered_key);
    cout << "Verification Status: " << (valid ? "SUCCESS (Matched Original Ciphertext)" : "FAILED") << "\n";

    return 0;
}
