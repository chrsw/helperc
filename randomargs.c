// randomargs:  print command line arguments in random order
//
// Build:
//  $ gcc -o randomargs randomargs.c aalloc.c randomize.c
//  $ gcc -DEBUG -o randomargs randomargs.c aalloc.c randomize.c
//
// Run:
//  $ ./randomargs one two three four five
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "aalloc.h"
#include "randomize.h"

// print command line arguments in random order, excluding program name
int main(int argc, char *argv[]) {
    
    int n = 0;
    // list of random numbers filled by randomize()
    int *rand_num_list = NULL;                       

    // save arguments to dynamic array
    if (aalloc(argc, argv) != 0) exit(1);

#ifdef DEBUG
    // print starting data for debug
    printf("n = %d\n", n);
    for (n; n < argc; n++)
        printf("%s\n", aal_gp[n]); 
#endif

    // randomize args and print random order
    // argc-1: no need to include the command name in the randomized list
    rand_num_list = randomize(argc-1);
    for (n = 0; n < argc-1; n++)
        printf("%s\n", argv[rand_num_list[n]+1]);

    // clean up used memory no longer needed, but OS will do this anyway
    free(rand_num_list);
    free(aal_gp);
    return 0;
}
