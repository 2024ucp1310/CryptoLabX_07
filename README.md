# CryptoLabX_07


## Project Description

CryptoLabX is a cryptography laboratory project developed to implement
classical and modern encryption algorithms, cryptanalysis techniques,
mathematical utilities, and data analysis tools.

## Team Members

Member 1 - 2024UCP1310 - Udayan Amipara
Member 2 - 2024UCP1453 - Dayal

## Folder Structure

classical/ <br>
attacks/ <br>
math/<br>
modern/<br>
secure_application/<br>
analysis/<br>
datasets/<br>
outputs/<br>
docs/<br>
tests/<br>
utils/<br>

# Assignment 3 — Secure Application & SAST

## Assigned Application

**Student Portal**

The Student Portal is a small console-based application developed in **C**. It provides basic student management functionality and is intentionally used to demonstrate common security vulnerabilities and their detection using a SAST tool.

### Basic Functionalities

* Student Login
* Course Registration
* View Student Profile
* View Grades
* Student Information Lookup
* Grade Modification

## SAST Tool

**Flawfinder**

Flawfinder is used as the Static Application Security Testing (SAST) tool to analyze the C source code and identify potentially dangerous coding practices and security weaknesses.

Basic scan command:

```bash
flawfinder secure_application/src/student_portal.c
```

Save the scan result:

```bash
flawfinder secure_application/src/student_portal.c > secure_application/sast/flawfinder_report.txt
```

## Demonstrated Vulnerabilities

The application demonstrates the following security issues:

1. **Unsafe Input Handling**

   * Unsafe input and string handling functions are used to demonstrate potential memory-related security issues.

2. **Broken Access Control / IDOR**

   * A logged-in student can access another student's information by providing their Student ID.

3. **Missing Authorization**

   * The application does not properly verify whether a user has permission to modify another student's academic information.

## Basic Folder Structure

```text
secure_application/
│
├── src/
│   └── student_portal.c
│
├── reports/
│   └── vulnerability_report.md
│
├── screenshots/
│   └── SAST and application screenshots
│
├── sast/
│   ├── flawfinder_report.txt
│   └── flawfinder_report.html
│
├── crypto/
│
├── outputs/
│   └── student_portal
│
├── testcases/
│   └── testcases.md
│
└── README.md
```

## Tools & Technologies

* **Language:** C
* **Compiler:** GCC
* **Operating System:** Ubuntu Linux
* **SAST Tool:** Flawfinder
* **Version Control:** Git & GitHub


## Current Features

Menu Driven Interface<br>
Dataset Management<br>
File Analysis<br>
Logging<br>
Git Version Control<br>

## Future Modules

• Caesar Cipher<br>
• Vigenere Cipher<br>
• Playfair Cipher<br>
• Hill Cipher<br>
• AES<br>
• DES<br>
• RSA<br>
• SHA<br>
• Frequency Analysis<br>
• Brute Force Attacks<br>

## Requirements

Python 3.10+

## Run

python main.py
