/** Print the current local time */
#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    char *time_string;

    // Get the current time as a time_t value
    rawtime = time(NULL);

    // Convert to a string and print it
    time_string = ctime(&rawtime);
    printf("Current local time: %s", time_string);

    return 0;
}