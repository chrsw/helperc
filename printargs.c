// printargs:  print command and command line args
//
// Build:
// $ gcc -o printargs printargs.c aalloc.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aalloc.h"

// print command line arguments in forward order
int main(int argc, char *argv[]) {

    int n = 0;

    if (aalloc(argc, argv) != 0) exit(1);

    for (n; n < argc; n++)
        printf("%s\n", aal_gp[n]); 

    free(aal_gp);
    return 0;
}
