#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_SIZE 100

typedef struct Person {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    char cohort[MAX_SIZE];
    char location[MAX_SIZE];
} Person;

int main(void) {
    MYSQL *conn; 
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (!mysql_real_connect(conn, "localhost", "whyte", "pa55w0rd", "Register", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    Person tregister[MAX_SIZE];
    int num_people = 0;
    char input[MAX_SIZE];
    int quit = 0;

    while (!quit) {
        printf("\nOptions:\n");
        printf("1. Add person to register\n");
        printf("2. Print register\n");
        printf("3. Quit\n\n");

        printf("Enter option number: ");
        scanf("%s", input);

        switch (atoi(input)) {
            case 1:
                if (num_people >= MAX_SIZE) {
                    printf("Error: register is full!\n");
                    break;
                }

                printf("\nEnter name: ");
                scanf("%s", tregister[num_people].name);

                printf("Enter surname: ");
                scanf("%s", tregister[num_people].surname);

                printf("Enter cohort (0-99): ");
                scanf("%s", input);

                if (strlen(input) != 2 || !isdigit(input[0]) || !isdigit(input[1]) || atoi(input) < 0 || atoi(input) > 99) {
                    printf("Error: cohort must be a two-digit number between 0 and 99!\n");
                    break;
                }

                strcpy(tregister[num_people].cohort, input);

                printf("Enter location: ");
                scanf("%s", tregister[num_people].location);

                // Create and execute the SQL query
                char query[500];
                sprintf(query, "INSERT INTO people (name, surname, cohort, location) VALUES ('%s', '%s', '%s', '%s')",
                         tregister[num_people].name, tregister[num_people].surname,
                         tregister[num_people].cohort, tregister[num_people].location);

		if (mysql_query(conn, query)) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    break;
                }

                num_people++;
                break;
            case 2:
                if (mysql_query(conn, "SELECT * FROM people")) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    break;
                }

                res = mysql_use_result(conn);

                while ((row = mysql_fetch_row(res)) != NULL) {
                    printf("%s %s, Cohort %s, Location: %s\n", row[0], row[1], row[2], row[3]);
                }

                mysql_free_result(res);
                break;
            case 3:
                printf("\nGoodbye!\n");
                quit = 1;
                break;
            default:
                printf("\nError: invalid option number!\n");
                break;
        }
    }

    mysql_close(conn);

    return 0;
}
