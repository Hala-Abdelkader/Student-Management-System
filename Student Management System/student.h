#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a student
struct Student
{
    int id;
    char name[51];
    char gender;
    int age;
    int studyYear;
    struct Student *next; // Pointer to the next student in the linked list
};

int displayMenu();
void addStudent(struct Student **head);
void deleteStudent(struct Student **head);
void freeStudents(struct Student **head);
void displayStudents(struct Student *head);
void saveToFile(struct Student *head);
struct Student* readFromFile();

#endif // STUDENT_H_INCLUDED


/*
 ******************************************************************************
 User          Date                 Brief
 ******************************************************************************
 All Team     03Dec2023             Put the prototypes for our functions and the needed struct
*/
