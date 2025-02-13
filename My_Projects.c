#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent an employee
typedef struct Employee {
    int id;
    char name[100];
    char position[100];
    float salary;
    int transport;
    char address[200];
} Employee;

// Define a function to add a new employee to the database
void add_employee(Employee *database, int size) {
    if (size >= 10) {
        printf("Database is full. Cannot add new employee.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[size].name);
    strcpy(database[size].position, "Unknown");
    printf("Enter position: ");
    scanf("%s", database[size].position);

    printf("Enter salary: $");
    scanf("%f", &database[size].salary);

    printf("Enter transport (1 for car, 2 for bus): ");
    scanf("%d", &database[size].transport);

    printf("Enter address: ");
    gets(database[size].address);
}

// Define a function to display all employees in the database
void display_employees(Employee *database, int size) {
    if (size == 0) {
        printf("No employees in the database.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Position: %s\n", database[i].position);
        printf("Salary: $%.2f\n", database[i].salary);
        printf("Transport: ");
        switch (database[i].transport) {
            case 1:
                printf("Car\n");
                break;
            case 2:
                printf("Bus\n");
                break;
            default:
                printf("Unknown\n");
        }
        printf("Address: %s\n", database[i].address);
    }
}

// Define a function to search for an employee in the database
void search_employee(Employee *database, int size) {
    if (size == 0) {
        printf("No employees in the database.\n");
        return;
    }

    int choice;
    printf("Enter ID of the employee you want to search: ");
    scanf("%d", &choice);

    for (int i = 0; i < size; i++) {
        if (database[i].id == choice) {
            printf("Name: %s\n", database[i].name);
            printf("Position: %s\n", database[i].position);
            printf("Salary: $%.2f\n", database[i].salary);
            printf("Transport: ");
            switch (database[i].transport) {
                case 1:
                    printf("Car\n");
                    break;
                case 2:
                    printf("Bus\n");
                    break;
                default:
                    printf("Unknown\n");
            }
            printf("Address: %s\n", database[i].address);
            return;
        }
    }

    printf("Employee not found in the database.\n");
}

// Define a function to delete an employee from the database
void delete_employee(Employee *database, int size) {
    if (size == 0) {
        printf("No employees in the database.\n");
        return;
    }

    int choice;
    printf("Enter ID of the employee you want to delete: ");
    scanf("%d", &choice);

    for (int i = size - 1; i >= 0; i--) {
        if (database[i].id == choice) {
            memmove(&database[i], &database[i + 1], sizeof(Employee));
            size--;
            break;
        }
    }

    printf("Employee deleted successfully.\n");
}

// Main function
int main() {
    const int MAX_SIZE = 10;
    Employee database[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add new employee\n");
        printf("2. Display all employees\n");
        printf("3. Search for an employee\n");
        printf("4. Delete an employee\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee(database, size);
                break;
            case 2:
                display_employees(database, size);
                break;
            case 3:
                search_employee(database, size);
                break;
            case 4:
                delete_employee(database, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
