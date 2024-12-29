/* buildcmd: demonstrate extracting the build command from source
 * _buildcmd: gcc -o buildcmd buildcmd.c
 *
 * Usage:
 *  ./buildcmd <source.c>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) exit (1);

    printf("hello, buildcmd!\n");

    return 0;
}
