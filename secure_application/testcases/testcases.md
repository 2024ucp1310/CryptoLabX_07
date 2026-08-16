# Student Portal Test Cases

## TC01 - Valid Login

Input:
- Student ID: 101
- Password: rahul123

Expected Result:
- Login should be successful.

Actual Result:
- Login successful.

Status:
PASS


## TC02 - Invalid Login

Input:
- Student ID: 101
- Password: wrong123

Expected Result:
- Login should fail.

Actual Result:
- Invalid Student ID or password.

Status:
PASS


## TC03 - View Profile

Input:
- Login as student 101.
- Select View Profile.

Expected Result:
- Student 101 profile should be displayed.

Status:
PASS


## TC04 - Course Registration

Input:
- Login as student 101.
- Select Register Course.
- Select DBMS.

Expected Result:
- Course should be added to the student's course list.

Status:
PASS


## TC05 - IDOR Test

Input:
- Login as student 101.
- Select View Student by ID.
- Enter student ID 102.

Expected Result:
- Access should be denied because student 101 should not access another student's private information.

Actual Result:
- Information of student 102 is displayed.

Status:
FAIL - Vulnerability Detected


## TC06 - Unauthorized Grade Modification

Input:
- Login as student 101.
- Select Update Grade.
- Enter student ID 102.
- Change the grade.

Expected Result:
- Operation should be denied because student 101 is not authorized to modify student 102's grade.

Actual Result:
- Grade modification is allowed.

Status:
FAIL - Vulnerability Detected


## TC07 - Unsafe Input Test

Input:
- Login as student 101.
- Select Update Grade.
- Enter an excessively long grade string.

Expected Result:
- Input should be rejected safely.

Actual Result:
- Program accepts unchecked input.

Status:
FAIL - Vulnerability Detected
