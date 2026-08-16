#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 4
#define MAX_COURSES 5

typedef struct {
    int id;
    char name[50];
    char password[30];
    char department[30];
    float cgpa;
    char courses[5][30];
    int course_count;
    char grades[5][5];
} Student;

Student students[MAX_STUDENTS] = {
    {101, "Rahul", "rahul123", "CSE", 8.4,
     {"Operating Systems", "DBMS"}, 2,
     {"A", "B+"}},

    {102, "Priya", "priya123", "CSE", 9.1,
     {"Computer Networks", "DBMS"}, 2,
     {"A+", "A"}},

    {103, "Aman", "aman123", "ECE", 7.8,
     {"Digital Electronics"}, 1,
     {"B"}},

    {104, "Neha", "neha123", "CSE", 8.9,
     {"Data Structures"}, 1,
     {"A+"}}
};

const char *available_courses[MAX_COURSES] = {
    "Operating Systems",
    "Computer Networks",
    "DBMS",
    "Data Structures",
    "Software Engineering"
};

int current_user = -1;


int login() {
    int id;
    char password[30];

    printf("\n========== STUDENT LOGIN ==========\n");

    printf("Enter Student ID: ");
    scanf("%d", &id);

    printf("Enter Password: ");
    scanf("%29s", password);

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].id == id &&
            strcmp(students[i].password, password) == 0) {

            current_user = i;

            printf("\nLogin successful!\n");
            printf("Welcome, %s\n", students[i].name);

            return 1;
        }
    }

    printf("\nInvalid Student ID or password.\n");
    return 0;
}




void view_profile(int student_index) {

    printf("\n========== STUDENT PROFILE ==========\n");

    printf("Student ID : %d\n", students[student_index].id);
    printf("Name       : %s\n", students[student_index].name);
    printf("Department : %s\n", students[student_index].department);
    printf("CGPA       : %.2f\n", students[student_index].cgpa);
}




void view_grades(int student_index) {

    printf("\n========== GRADES ==========\n");

    for (int i = 0; i < students[student_index].course_count; i++) {

        printf("%-25s : %s\n",
               students[student_index].courses[i],
               students[student_index].grades[i]);
    }
}




void register_course(int student_index) {

    int choice;

    printf("\n========== COURSE REGISTRATION ==========\n");

    for (int i = 0; i < MAX_COURSES; i++) {
        printf("%d. %s\n", i + 1, available_courses[i]);
    }

    printf("Select course: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_COURSES) {
        printf("Invalid course selection.\n");
        return;
    }

    if (students[student_index].course_count >= 5) {
        printf("Maximum course limit reached.\n");
        return;
    }

 
	// V1->
    strcpy(
        students[student_index]
            .courses[students[student_index].course_count],
        available_courses[choice - 1]
    );

    strcpy(
        students[student_index]
            .grades[students[student_index].course_count],
        "NA"
    );

    students[student_index].course_count++;

    printf("\nCourse registered successfully.\n");
}




void view_student_by_id() {

    int search_id;

    printf("\nEnter Student ID to view: ");
    scanf("%d", &search_id);

    // V2->

    for (int i = 0; i < MAX_STUDENTS; i++) {

        if (students[i].id == search_id) {

            printf("\n========== STUDENT INFORMATION ==========\n");

            printf("ID         : %d\n", students[i].id);
            printf("Name       : %s\n", students[i].name);
            printf("Department : %s\n", students[i].department);
            printf("CGPA       : %.2f\n", students[i].cgpa);

            return;
        }
    }

    printf("Student not found.\n");
}



void update_grade() {

    int student_id;
    int course_number;
    char new_grade[5];

    // V3->

    printf("\n========== UPDATE GRADE ==========\n");

    printf("Enter Student ID: ");
    scanf("%d", &student_id);

    int index = -1;

    for (int i = 0; i < MAX_STUDENTS; i++) {

        if (students[i].id == student_id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter course number: ");
    scanf("%d", &course_number);

    if (course_number < 1 ||
        course_number > students[index].course_count) {

        printf("Invalid course number.\n");
        return;
    }

    printf("Enter new grade: ");

    

    scanf("%s", new_grade);

    strcpy(
        students[index].grades[course_number - 1],
        new_grade
    );

    printf("Grade updated successfully.\n");
}



void student_menu() {

    int choice;

    while (1) {

        printf("\n========== STUDENT PORTAL ==========\n");

        printf("1. View Profile\n");
        printf("2. View Grades\n");
        printf("3. Register Course\n");
        printf("4. View Student by ID\n");
        printf("5. Update Grade\n");
        printf("6. Logout\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                view_profile(current_user);
                break;

            case 2:
                view_grades(current_user);
                break;

            case 3:
                register_course(current_user);
                break;

            case 4:
                view_student_by_id();
                break;

            case 5:
                update_grade();
                break;

            case 6:
                printf("\nLogged out successfully.\n");
                current_user = -1;
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}



int main() {

   
    printf("       STUDENT MANAGEMENT PORTAL    \n");
    

    if (login()) {
        student_menu();
    }

    return 0;
}
