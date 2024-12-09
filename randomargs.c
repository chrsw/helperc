// randomargs:  print command line args in random order
//
// Build:
// $ gcc -o randomargs randomargs.c aalloc.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "aalloc.h"
#include "randomize.h"

// print command line arguments in random order
int main(int argc, char *argv[]) {
    
    int n = 0;
    int *rand_num_list = NULL;     //  list of random numbers from randomize();

    // save arguments to dynamic array
    if (aalloc(argc, argv) != 0) exit(1);

    // print all args in correct order
    for (n; n < argc; n++)
        printf("%s\n", aal_gp[n]); 
    n--;
    printf("n = %d\n", n);

    // randomize args
    rand_num_list = randomize(argc-1);

    for (n = 0; n < argc-1; n++)
        printf("%s\n", argv[rand_num_list[n]+1]);

    free(rand_num_list);
    free(aal_gp);
    return 0;
}
