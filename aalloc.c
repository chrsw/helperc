// aalloc: allocate space for command line arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aalloc.h"

// aal_gp[0] is the first argument
// aal_gp[1] is the second argument
// aal_gp[n] is the nth argument 
char **aal_gp;


#ifdef MAIN
// create an array of pointers dynamically allocated 
// number of arguments is known at run time
int main(int argc, char *argv[]) {

    int n = argc;

    if (aalloc(argc, argv) != 0) exit(1);

    for (--n; n >= 0; n--)
        printf("%s\n", aal_gp[n]); 

    free(aal_gp);
    return 0;
}
#endif // MAIN

// allocate an array of pointers, one pointer for each
// command line argument
int aalloc(int argc, char *argv[]) {

    int i;
    int n = argc;
    char *aal_new;

    aal_gp = malloc(argc);

    do {
        aal_gp[argc-1] = malloc(sizeof(argv[argc-1]+1));
        strcpy(aal_gp[argc-1], argv[argc-1]);
    } while (argc-- > 1);

    return 0;
}
