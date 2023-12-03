#include "student.h"

// Function to add a new student to the linked list
void addStudent(struct Student **head)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    bool invalidInput = false;
    do
        {
            //Asks the user to enter student full name
        printf("Enter student full name (50 characters max): ");
        scanf(" %[^\n]s", newStudent->name);
        if (strlen(newStudent->name) > 50)
        {
                //Check for the maximum length for the student name entered
            printf("Name exceeds maximum length. Please enter a name within 50 characters.\n");
            invalidInput = true;
        } else
        {
            invalidInput = false;
        }
    }
    while (invalidInput);
    do
    {
        //Asks the user to enter the gender
        printf("Enter gender (m/f): ");
        scanf(" %c", &newStudent->gender);
    }
     while (newStudent->gender != 'm' && newStudent->gender != 'f');

    do
    {
        //Asks the user to enter the age
        printf("Enter age (30 max): ");
        scanf("%d", &newStudent->age);
        if (newStudent->age > 30)
        {
            //Check for the age the user entered if it is greater or less than 30
            printf("Age exceeds maximum limit. Please enter an age within 30.\n");
            invalidInput = true;
        } else
        {
            invalidInput = false;
        }
    }
    while (invalidInput);

    do
    {
        //Asks the user to enter the study year
        printf("Enter study year (5 max): ");
        scanf("%d", &newStudent->studyYear);
        if (newStudent->studyYear > 5)
        {
            //Check for the study year the user entered whether it is greater or less than 5
            printf("Study year exceeds maximum limit. Please enter a year within 5.\n");
            invalidInput = true;
        }
    else
        {
            invalidInput = false;
        }
    }
    while (invalidInput);

    newStudent->next = *head;
    *head = newStudent;

    printf("Student added successfully.\n");
}

// Function to delete a student from the linked list using doubly nodes
void deleteStudent(struct Student **head)
{
    int idToDelete;
    //Asks the user to delete the student with his ID
    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);
    //Create pointer for doubly nodes
    struct Student *current = *head;
    struct Student *prev = NULL;

    int currentID = 0;
    while (current != NULL && currentID != idToDelete)
    {
        prev = current;
        current = current->next;
        currentID++;
    }

    if (current != NULL && currentID == idToDelete)
    {
        if (prev == NULL)
        {
            *head = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        free(current);
        printf("Student deleted successfully.\n");
    }
    else
    {
        printf("Invalid student ID.\n");
    }
}


// Function to free memory allocated for the linked list
void freeStudents(struct Student **head)
{
    struct Student *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

/*
 ******************************************************************************
    User              Date                            Brief
 ******************************************************************************
 Roqaia Khalid     03Dec2023           Implemented the function which add new student to the linked list

 Ahmed Hassan      03Dec2023           Implemented the function which free the memory allocated for the linked list

 Ahmed Mohamed     03Dec2023           Implemented the function which delete student from linked list
*/
