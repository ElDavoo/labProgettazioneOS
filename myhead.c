//
// Created by Davide on 29/09/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT 10

long int parse(char *line){
    // Parse a line with a "-" and a number, return the number
    char *token = strtok(line, "-");
    return strtol(token, NULL, 10);
}

int main(int argc, char *argv[]) {
    if (argc > 3) {
        fprintf(stderr, "Too many arguments supplied.\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 3){
        long int n = parse(argv[1]);
        // OPen the file and read only the first N files
        FILE *fp;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            printf("Error opening file");
            exit(EXIT_FAILURE);
        }

        while (n > 0 && (read = getline(&line, &len, fp)) != -1 ) {
            printf("%s", line);
            n--;
        }
        fclose(fp);
        if (line)
            free(line);
        exit(EXIT_SUCCESS);
    }
    if (argc == 2){

        // First understand if parameter is "-N" or a file
        if (argv[1][0] == '-'){
            // Parse the number
            long int n = parse(argv[1]);
            // Read from stdin
            int c;
            while (n > 0 && (c = getchar()) != EOF) {
                if (c == '\n'){
                    n--;
                }
                putchar(c);

            }
            exit(EXIT_SUCCESS);
        } else {
            // Open the file and read it
            FILE *fp;
            char *line = NULL;
            size_t len = 0;
            ssize_t read;

            fp = fopen(argv[1], "r");
            if (fp == NULL) {
                printf("Error opening file");
                exit(EXIT_FAILURE);
            }

            int n = DEFAULT;
            // Read only the first 10 lines
            while (n > 0 && (read = getline(&line, &len, fp)) != -1) {
                printf("%s", line);
                n--;

            }

            fclose(fp);
            if (line)
                free(line);
            exit(EXIT_SUCCESS);
        }
    }
    // Read only ten lines from stdin, then exit
    int c;
    int n = DEFAULT;
    while (n > 0 && (c = getchar()) != EOF) {
        if (c == '\n'){
            n--;
        }
        putchar(c);

    }
    exit(EXIT_SUCCESS);
}