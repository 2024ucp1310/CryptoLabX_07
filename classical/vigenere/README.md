# Cryptanalysis of Vigenère Cipher

A modular C++ cryptanalysis suite that breaks Vigenère ciphers using Kasiski examination, Index of Coincidence (IC), and Chi-Square frequency analysis without any prior knowledge of the secret key.

---

## Assigned Responsibilities & Commits

| Step | Member | Module / Files | Functions Implemented |
| :--- | :--- | :--- | :--- |
| 1 | **Udayan** | `kasiski.hpp`, `kasiski.cpp` | `clean_ciphertext()`, `find_repeated_patterns()`, `calculate_distances()`, `find_factors()`, `kasiski_analysis()` |
| 2 | **Dayal** | `frequency.hpp`, `frequency.cpp` | `calculate_ic()`, `split_into_groups()`, `frequency_analysis()` |
| 3 | **Dayal** | `frequency.cpp` | `find_shift()`, `find_key()` |
| 4 | **Udayan** | `vigenere.hpp`, `vigenere.cpp` | `vigenere_decrypt()`, `vigenere_encrypt()`, `verify()` |
| 5 | **Udayan** | `main.cpp`, `README.md` | Console reports, round-trip verification, documentation |

---

## Function Reference

- `clean_ciphertext()`: Strips whitespace and non-alphabetic characters, converting text to uppercase.
- `find_repeated_patterns()`: Detects repeating 3-letter sequences and their indices.
- `calculate_distances()`: Determines intervals between recurring sequences.
- `find_factors()`: Gathers common divisors from identified pattern distances.
- `calculate_ic()`: Computes the Index of Coincidence for candidate analysis.
- `split_into_groups()`: Splits ciphertext into cosets based on candidate period length.
- `kasiski_analysis()`: Predicts probable key lengths using distance common divisors and IC peaks.
- `frequency_analysis()`: Builds normalized letter distribution vectors for each coset.
- `find_shift()`: Determines individual Caesar shifts by minimizing the Chi-Square statistic against standard English letter frequencies.
- `find_key()`: Concatenates recovered group shifts into the full Vigenère keyword.
- `vigenere_decrypt()`: Decrypts the ciphertext using modular subtraction.
- `vigenere_encrypt()`: Re-encrypts the recovered plaintext for verification.
- `verify()`: Verifies that the re-encrypted plaintext matches the original normalized ciphertext.

---

## Build & Run

### Compilation
```bash
g++ -O2 -std=c++17 kasiski.cpp frequency.cpp vigenere.cpp main.cpp -o vigenere_solver
