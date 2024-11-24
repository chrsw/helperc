// progname:  example using pgn lib
//
// $ gcc -o progname progname.c pgn.c

#include <stdio.h>
#include <stdbool.h>
#include "pgn.h"

int main(int argc, char *argv[]) {

    (void)argc;

    pgn_set_name(argv[0]);
    
    printf("The program name is %s\n", pgn_get_name());    

    return 0;
}
