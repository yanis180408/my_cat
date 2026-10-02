#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *filepointer;
    if(argc >= 2){
    filepointer = fopen(argv[1], "r"); //w = écrire, r = lire
    if (filepointer == NULL){
        printf ("Erreur\n");
        exit(1);}
        fclose(filepointer);
        exit(0);
    }
    else{
        printf ("PErreur\n");
        exit(1);
    }

}
