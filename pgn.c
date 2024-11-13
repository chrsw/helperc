// pgn.c    simple library for program name management
//

#include <stdbool.h>
#include "pgn.h"

const char *pgn_progname;
static bool pgn_b_is_init = false;

// set the program name string of a running program
void pgn_set_name(const char *s) {

    pgn_progname = s;
    pgn_b_is_init = true;
}


// get the program name string
const char *pgn_get_name(void) {

    return pgn_progname;
}

// return init status
bool pgn_is_init(void) {

    return pgn_b_is_init;
}

// reset init status
void pgn_reset(void) {

    pgn_b_is_init = false;
}
