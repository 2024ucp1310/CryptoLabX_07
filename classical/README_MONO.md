# CryptoLabX - Assignment 4
## Monoalphabetic Substitution Cipher Cryptanalysis

## 1. Introduction

This assignment implements a monoalphabetic substitution cipher and performs
cryptanalysis on the generated ciphertext.

The assignment demonstrates how frequency analysis, word-frequency analysis,
pattern analysis, and substitution hypotheses can be combined to recover the
original plaintext.

The implementation is written in C++.

---

## 2. Objectives

The main objectives of this assignment are:

- Generate plaintext from a given cryptography text.
- Encrypt the plaintext using a monoalphabetic substitution cipher.
- Store the encrypted text in `ciphertext.txt`.
- Perform character frequency analysis.
- Perform word-frequency analysis.
- Perform pattern analysis on ciphertext words.
- Use the obtained observations to make substitution hypotheses.
- Generate partial plaintext using the guessed substitutions.
- Recover the complete plaintext.
- Determine the substitution key.
- Verify the recovered plaintext.

---

## 3. Directory Structure

```text
CryptoLabX_07/
│
├── classical/
│   └── monoalphabetic.cpp
|   |_ README_MONO.md
│
├── datasets/
│   ├── plaintext.txt
│   └── ciphertext.txt
│
├── outputs/
│   └── recovered_plaintext.txt
