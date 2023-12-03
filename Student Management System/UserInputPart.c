#include "student.h"

int displayMenu()
{
    int choice;
    printf("\nMenu:\n");
    printf("1- Add new student data.\n");
    printf("2- Delete existing student using student id.\n");
    printf("3- Display all students.\n");
    printf("4- Exit program.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

/*
 ******************************************************************************
 User                  Date                        Brief
 ******************************************************************************
 Hala Abdelkader     03Dec2023             Implemented the function which displays the mainMenu for our application
*/
