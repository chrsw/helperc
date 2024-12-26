// randomfile:  print file lines in random order
//
// Build:
//  $ gcc -o randomfile randomfile.c falloc.c randomize.c
//  $ gcc -DEBUG -o randomfile randomfile.c falloc.c randomize.c
//
// Run:
//  $ cat rand_test.txt | ./randomfile
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "falloc.h"
#include "randomize.h"


// needed by falloc()
char buf[BUFSIZ]; 


// print file lines in random order
int main(int argc, char *argv[]) {
    
    int n = 0;
    // list of random numbers filled by randomize()
    int *rand_num_list = NULL;                       

    // save file lines to dynamic array
    n = falloc(stdin);
    if (n < 0) exit(1);

#ifdef DEBUG
    // print starting data for debug
    printf("n = %d\n", n);
    for (int i; i < n; i++)
        printf("%s\n", fal_gp[n]); 
#endif

    // randomize file lines and print random order
    rand_num_list = randomize(n);
    for (int i = 0; i < n; i++)
        printf("%s", fal_gp[rand_num_list[i]]);

    // clean up used memory no longer needed, but OS will do this anyway
    free(rand_num_list);
    free(fal_gp);
    return 0;
}
