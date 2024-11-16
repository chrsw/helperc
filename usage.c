/* vim:ts=4:sw=4:et:
 *
 * usage.c
 *      Template for a function to report command usage. 
 *
 * Description:
 *      Details
 * Inspired by:
 *      https://github.com/pabr/leansdr/blob/master/src/apps/leandvb.cc
 *      GPL Licenced
 *
 * Parameters:
 *      Command name
 *      Output stream
 *      Error code 
 *      Information string
 *
 * Buiding:
 *	gcc -c -o usage usage.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Example use of this function. Test the command line options for 
 * validity and print command usage if bad options are given.
 * int main(int argc, char *argv[]) {
 *
 *  for ( int i = 1; i < argc; ++i ) {
 *    if     ( !strcmp(argv[i], "-h") )
 *     usage(argv[0], stdout, 0);
 *   else if ( !strcmp(argv[i], "-v") )
 *     verbose = true;
 *   else if ( !strcmp(argv[i], "-d") ) {
 *     debug = true;
 *   }
 *   else if ( !strcmp(argv[i], "--version") ) {
 *     printf("%s\n", VERSION);
 *     return 0;
 *   }
 *   else if ( !strcmp(argv[i], "-f") && i + 1 < argc )
 *     file = atof(argv[++i]);
 *   }
 *   else
 *     usage(argv[0], stderr, 1, argv[i]);
 *  }
 */


void usage(const char *name, FILE *f, int c, const char *info) {

  if (!f || !info || !name) exit(c);

  fprintf(f, "Usage: %s [options]\n", name);
  fprintf(f, "Command summary, input, output, help\n");
  fprintf
    (f,
     "\nInput options:\n"
     "  --i1                Input option #1\n"
     "  --i2                Input option #2\n"
     "  --input=0           Long form input option\n"
     );
  fprintf
    (f,
     "\nOutput options:\n"
     "  --output N          Number of outputs\n"
     );
  fprintf
    (f,
     "\nUI options:\n"
     "  -h                  Display this help message and exit\n"
     "  -v                  Output debugging info at startup and exit\n"
     "  -d                  Output debugging info during operation\n"
     "  --version           Display version and exit\n"
     );
#ifdef GUI
  fprintf
    (f,
     "  --gui               Show GUI (X11)\n"
     );
#endif
  fprintf
    (f, "\nTesting options:\n"
     "  --test 		        Experimental options)\n"
     );
  if (info) fprintf(f, "** Error while processing '%s'\n", info);
  exit(c);
}


// LICENSE
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
