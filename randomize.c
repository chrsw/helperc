// randomize: generate a random list of numbers
//
// $ gcc -o randomize randomize.c
// _buildcmd: gcc -o randomize randomize.c
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>


int *randomize(int n);
static bool _check(int *flags, int n, int r);


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


// randomize:  generate random numbers from 1 to n, each number used once
int *randomize(int n) {

    int *list = NULL;
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

    // allocate space of n numbers
    list = malloc(sizeof(r)*n);
    flags = malloc(sizeof(bool)*n);
    if (list == NULL) return list;
    memset(list, -1, sizeof(list[0]) * n);
    
    // generate n random numbers;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        r = rand() % n;
        printf("main: \tr = %d\n", r);
        for (int j = 0; j < n; j++)
            printf("main: list[%d] = %d\n", j, list[j]);
        // generate a new number for every n
        r = rand() % n;
        printf("\tr = %d\n", r);
        do {
            r = rand() % n;
            sleep(1);
        } while (_check(list, n, r) == false);  // number generated already?
        list[i] = r;
        printf("main: list[%d] = %d\n", i, list[i]);
    }

    free(flags);
    return list;
}

// _check:  is a number available?
static bool _check(int *list, int n, int r) {

    bool ret = true;
    for (int i = 0; i < n; i++)
        if (list[i] == r)
            ret = false;
    return ret;
}
