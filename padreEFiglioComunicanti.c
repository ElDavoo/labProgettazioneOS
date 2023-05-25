/* FILE: padreEFiglioComunicanti.c - Il padre consumatore crea un figlio produttore */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MSGSIZE 5 /* Dimensione del messaggio, stabilito dalla specifica */

typedef int pipe_t[2]; /* Definizione del tipo pipe_t (primo int: lettura, secondo int: scrittura */

int main(int argc, char *argv[]){

    char error[BUFSIZ]; /* Buffer utilizzato per scrivere su standard error */
    pipe_t *piped = (pipe_t *) malloc(sizeof(pipe_t)); /* Array di pipe */
    int pid; /* Variabile utilizzata per indicare il process ID del figlio /*

    /* Controllo sul numero di parametri: Un singolo file */
    if (argc != 2) {
        sprintf(error, "Numero parametri non conforme: I parametri passati a %s sono %d", argv[0], argc - 1);
        perror(error);
        exit(1);
    }

    /* Creazione della pipe */
    if (pipe(piped) < 0 ) {
        sprintf(error, "Errore nella creazione della pipe");
        perror(error);
        exit(2);
    }

    /* Creazione del figlio */
    if ((pid = fork()) < 0) {
        sprintf(error, "Errore nella creazione del figlio");
        perror(error);
        exit(3);
    }

    if (pid == 0) { /* Figlio */

        int fd; /* File descriptor del file da leggere */


        /* Chiusura della pipe di lettura (mi classifico come scrittore)*/
        close(piped[0][0]);

        /* Apertura del file */
        if ((fd = open(argv[1], O_RDONLY)) < 0) {
            sprintf(error, "Errore nell'apertura del file %s", argv[1]);
            perror(error);
            exit(-1); /* Ritorno al padre 255, che sarà un errore */
        }

        printf("Il figlio %d sta per iniziare a scrivere messaggi di lunghezza %d dopo averli letti dal file %s", getpid(), MSGSIZE, argv[1]);

        /* Legge al massimo MSGSIZE caratteri dal file e li scrive sulla pipe */
        while (read(fd, &piped[0][1], MSGSIZE) > 0) {
            /* Non faccio nulla, il figlio scrive sulla pipe */
        }

    }



}