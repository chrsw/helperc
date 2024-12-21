// falloc()     read lines of a file in to dynamically allocated arrays
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "falloc.h"


int falloc(FILE *fp);

char **fal_gp;                  // access file contents by line with this pointer
extern char buf[BUFSIZ];        // read file lines into before before copying to array


/* falloc: read a file into dynamically allocated arrays for every line
 *
 *     buf: global buffer for temporary line storage while data is being read
 *  fal_gp: pointer to start of arrays
 * returns: number of lines read in or, -1 for no lines or memory error
 *
 */
int falloc(FILE *fp) {

    char **hap_ln;              // array of pointers
                                // that point to each line read in
    int lines = 0;

    hap_ln = (char **)malloc(sizeof(int *));

    // read input lines into dynamically allocated arrays
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        char **hap_new = (char **)realloc(hap_ln, 
                                          (lines+1)*sizeof(char **));
        if (hap_new == NULL) {
            fprintf(stderr, "%s: memory error\n", __func__);
            return -1;
        }
        
        hap_ln = hap_new;
        hap_ln[lines] = (char *)malloc(sizeof(buf)+1);
        memcpy(hap_ln[lines], buf, sizeof(buf));
        lines++;
	}

    fal_gp = hap_ln;
    return lines;
}


  
