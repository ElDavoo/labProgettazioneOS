#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char error[BUFSIZ]; /* Buffer utilizzato per scrivere su standard error */

    /* Controllo sul numero di parametri: almeno due N-file e un carattere Cx */
    if (argc < 4) {
        sprintf(error, "Numero parametri non conforme: I parametri passati a %s sono solo %d", argv[0], argc - 1);
        perror(error);
        exit(1);
    }

    /* Controllo sulla lunghezza dell'ultimo parametro: deve essere un singolo carattere */
    if (strlen(argv[argc - 1]) != 1) {
        sprintf(error, "L'ultimo parametro passato a %s non e' un singolo carattere ma è %s", argv[0], argv[argc - 1]);
        perror(error);
        exit(2);
    }
    printf("ciao");

}
