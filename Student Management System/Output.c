#include "student.h"

// Function to display all students in the linked list
void displayStudents(struct Student *head)
{
    printf("All available students data:\n");
    int studentID = 0;
    //In case the list is not empty, print the student data
    while (head != NULL) {
        printf("Student ID: %d, Name: %s, Gender: %c, Age: %d, Study Year: %d\n",
               studentID, head->name, head->gender, head->age, head->studyYear);
        //Go to the next node in the linked list
        head = head->next;
        studentID++;
    }
}

/*
 ******************************************************************************
 User                                 Date                 Brief
 ******************************************************************************
 Hala Abdelkader & Roqaia Khalid    03Dec2023          Implemented the function which display students' Data
*/

