#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

int main()
{
    struct Student *head = readFromFile(); // Load data from file if available
    int choice;

    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                addStudent(&head);
                break;
            case 2:
                deleteStudent(&head);
                break;
            case 3:
                displayStudents(head);
                break;
            case 4:
                saveToFile(head); // Save data to file before exiting
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    freeStudents(&head);

    return 0;
}
/*
 ******************************************************************************
 User          Date                 Brief
 ******************************************************************************
 All Team     03Dec2023             Put the logic for our code in the main function
*/
