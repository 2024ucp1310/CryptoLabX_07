# Student Portal - Secure Application

## 1. Introduction

This project implements a small console-based Student Portal in C.

The application demonstrates common security vulnerabilities and their detection using the Flawfinder Static Application Security Testing (SAST) tool.

The application is developed as part of Lab Assignment 3.

## 2. Functionalities

The Student Portal provides:

1. Student login
2. Profile viewing
3. Grade viewing
4. Course registration
5. Student information lookup
6. Grade modification

## 3. Technologies

- Language: C
- Compiler: GCC
- SAST Tool: Flawfinder
- Operating System: Ubuntu Linux

## 4. Vulnerabilities

### 4.1 Unsafe Input Handling

The application uses unsafe string operations such as strcpy() and an unbounded scanf().

These operations can result in buffer overflow or memory corruption when unexpected input is supplied.

### 4.2 Broken Access Control / IDOR

A logged-in student can provide another student's ID and retrieve their information.

The application does not verify whether the requested student record belongs to the currently authenticated user.

### 4.3 Missing Authorization

The grade update functionality does not verify whether the current user has permission to modify grades.

Therefore, an ordinary student can modify another student's grade.

## 5. SAST Analysis

Flawfinder was used to scan the C source code.

Command used:

    flawfinder secure_application/src/student_portal.c

The complete scan output is stored in:

    sast/flawfinder_report.txt

The HTML report is stored in:

    sast/flawfinder_report.html

## 6. Testing

Test cases are available in:

    testcases/testcases.md

The test cases cover:

- Valid login
- Invalid login
- Profile viewing
- Course registration
- IDOR
- Unauthorized grade modification
- Unsafe input

## 7. Conclusion

The project demonstrates how insecure coding practices and authorization weaknesses can affect a student management application.

Flawfinder helps identify potentially dangerous C functions and provides static analysis findings that can be used to improve the security of the application.
