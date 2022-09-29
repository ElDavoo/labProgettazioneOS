//
// Created by Davide on 29/09/2022.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 2){
        FILE *fp;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Error opening file");
            exit(EXIT_FAILURE);
        }


        while ((read = getline(&line, &len, fp)) != -1) {
            printf("%s", line);
        }

        fclose(fp);
        if (line)
            free(line);
        exit(EXIT_SUCCESS);
    } else if (argc > 2) {
        fprintf(stderr, "Too many arguments supplied.\n");
        exit(EXIT_FAILURE);
    } else {
        int c;
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
        exit(EXIT_SUCCESS);
    }
}