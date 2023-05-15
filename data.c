#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    char surname[50];
    int cohort;
    char location[50];
} Person;

int main() {
    Person people_register[MAX_SIZE]; // an array to hold up to MAX_SIZE number of people
    int num_people = 0; // keep track of the number of people in the register

    // connect to MySQL database
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error: could not initialize MySQL connection\n");
        exit(1);
    }
    if (mysql_real_connect(conn, "localhost", "whyte", "pa55w0rd", "Register", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error: could not connect to MySQL database\n");
        exit(1);
    }

    // read input from the user and store in the register
    while (num_people < MAX_SIZE) {
        printf("Enter name: ");
        scanf("%s", people_register[num_people].name);

        printf("Enter surname: ");
        scanf("%s", people_register[num_people].surname);

        printf("Enter cohort (0-99): ");
        scanf("%d", &people_register[num_people].cohort);
        while (people_register[num_people].cohort < 0 || people_register[num_people].cohort > 99) {
            printf("Invalid cohort. Enter cohort (0-99): ");
            scanf("%d", &people_register[num_people].cohort);
        }

        printf("Enter location: ");
        scanf("%s", people_register[num_people].location);

        // insert person data into MySQL table
        char query[250];
        snprintf(query, sizeof(query), "INSERT INTO people (name, surname, cohort, location) VALUES ('%s', '%s', %d, '%s')",
                people_register[num_people].name, people_register[num_people].surname,
                people_register[num_people].cohort, people_register[num_people].location);
        if (mysql_query(conn, query) != 0) {
            fprintf(stderr, "Error: could not insert person data into MySQL table\n");
            exit(1);
        }

        num_people++;

        printf("Person added to register.\n");

        printf("Do you want to add another person? (y/n) ");
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, "n") == 0) {
            break;
        }
    }

    // print the contents of the register
    printf("Name\tSurname\tCohort\tLocation\n");
    for (int i = 0; i < num_people; i++) {
	printf("%s\t%s\t%d\t%s\n", people_register[i].name, people_register[i].surname,
	people_register[i].cohort, people_register[i].location);
	}

	// close MySQL connection
	mysql_close(conn);

	return 0;
}
