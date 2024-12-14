// randomize: generate a random list of numbers
//
// Details:
//  Store a list of integers in a heap array in random order. Provided so
//  other applications can easily randomize a list. main() provides a simple
//  usage example and doesn't have to be included.
// Build:
//  $ gcc -DRANDOMIZE_MAIN -o randomize randomize.c
//  $ gcc -DDEBUG -DRANDOMIZE_MAIN -o randomize randomize.c
//  $ gcc -c randomize.c
//  $ gcc -DDEBUG -c randomize.c
//
// TODO:
//  Clean up debug output
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "randomize.h"


static bool _check(int *flags, int n, int r);

#ifdef RANDOMIZE_MAIN
int main(int argc, char *argv[]) {

    int *rand_array = NULL;
    int n = 0;

    if (argc == 2 && ((n = atoi(argv[1])) < 1000)) {
        n = atoi(argv[1]);
        rand_array = randomize(n);
    } else
        return 1;
    if (rand_array != NULL) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", rand_array[i]);
        }
    free(rand_array);
    } else
        return 1;
}
#endif  // RANDOMIZE_MAIN


// randomize:  generate random numbers from 0 to n-1, each number used once
//             store list of random numbers in a dynamically allocated array
int *randomize(int n) {

    int *list = NULL;       // for returning to the callee so the app can
                            // use
    bool *flags = NULL;
    int r = 0;

    // set the list value and exit early if
    // max number is 1
    if (n == 1) {
       r = 1; 
        list = malloc(sizeof(r));
        *list = 1;
        return list;
    }

    // don't do anything if max number isn't high enough
    // number is 0
    if (n <= 0) return list;

    // allocate space of n numbers and initialize to negative number
    list = malloc(sizeof(r)*n);
    flags = malloc(sizeof(bool)*n);
    if (list == NULL) return list;
    memset(list, -1, sizeof(list[0]) * n);
    
    // generate n random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        r = rand() % n;
#ifdef DEBUG
        printf("main: \tr = %d\n", r);
        for (int j = 0; j < n; j++)
            printf("main: list[%d] = %d\n", j, list[j]);
#endif
        // generate a new number for every n
        r = rand() % n;
#ifdef DEBUG
        printf("\tr = %d\n", r);
#endif
        do {
            r = rand() % n;
            sleep(1);
        } while (_check(list, n, r) == false);  // number generated already?
        list[i] = r;
#ifdef DEBUG
        printf("main: list[%d] = %d\n", i, list[i]);
#endif
    }

    free(flags);
    return list;
}

// _check:  is a number available?
//          for internal, randomize.c use only
static bool _check(int *list, int n, int r) {

    bool ret = true;
    for (int i = 0; i < n; i++)
        if (list[i] == r)
            ret = false;
    return ret;
}
