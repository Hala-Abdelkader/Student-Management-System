#include "student.h"

// Function to save the linked list to a file
void saveToFile(struct Student *head)
{
    //File open to write the student data in it
    FILE *file = fopen("students.txt", "w");
    //Check if the file opens successfully
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
   //Writes each student's data to the file in a comma-separated format.
    while (head != NULL)
    {
        fprintf(file, "%d,%s,%c,%d,%d\n", head->id, head->name, head->gender, head->age, head->studyYear);
        head = head->next;
    }
   //Closes the file after writing all data.
    fclose(file);
    printf("Student data saved to file.\n");
}

// Function to read from the file and reconstruct the linked list
struct Student* readFromFile()
 {
         //File open to read the student data from it
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist or cannot be opened.\n");
        return NULL;
    }
    //Initialize pointers to keep track of the last student in the list
    struct Student *head = NULL;
    struct Student *current;
   /*This loop:
   1-Reads each line from the file.
   2-Allocates memory for a new student.
   3-Reads data into the new student's fields.
   */
    while (!feof(file))
        {
        struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
        if (newStudent == NULL)
         {
            printf("Memory allocation failed.\n");
            fclose(file);
            return head;
        }

        fscanf(file, "%d,%[^,],%c,%d,%d\n", &newStudent->id, newStudent->name, &newStudent->gender, &newStudent->age, &newStudent->studyYear);

        newStudent->next = NULL;

  //This constructs the linked list.
  //If it's the first student, both head and current point to the new student.
  //For subsequent students, the new student is added to the end of the list.
        if (head == NULL)
        {
            head = newStudent;
            current = newStudent;
        }
        else
        {
            current->next = newStudent;
            current = newStudent;
        }
    }
   //Closes the file after reading all data.
    fclose(file);
    printf("Student data read from file.\n");
    return head;
}


/*
 ******************************************************************************
     User              Date                            Brief
 ******************************************************************************
 Ahmed Hassan        03Dec2023             Implement the function which read/write to file
*/
