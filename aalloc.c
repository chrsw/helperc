// aalloc: allocate space for command line arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aalloc.h"

char **aal_gp;


// create an array of pointers dynamically allocated 
// number of arguments is known at run time
int main(int argc, char *argv[]) {

    int i;
    int n = argc;
    char *aal_new;

    aal_gp = malloc(argc);

    do {
        aal_gp[argc-1] = malloc(sizeof(argv[argc-1]+1));
        strcpy(aal_gp[argc-1], argv[argc-1]);
    } while (argc-- > 1);

    for (--n; n >= 0; n--)
        printf("%s\n", aal_gp[n]); 

    free(aal_gp);
    return 0;
}
