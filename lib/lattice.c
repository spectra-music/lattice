#include <stdlib.h>
#include <stdio.h>
#include <lmdb.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "lattice_util.h"

/**
 * Run the main program
 * (just creates a graph for now)
 */
int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("Usage: lattice_demo env/my_db.ltc");
  }

  char dest[sizeof(argv[1])];
  get_full_path_nonexistant(dest, argv[1]);
  MDB_env *env;  /* This is the database environment (directory, etc.) */

  /* Try to initialize the environment */
  int rv = mdb_env_create(&env);
  if ( rv != 0 ) {
    printf("Error creating database environment. Error code: %d\n Exiting now.\n", rv);
    exit(EXIT_FAILURE);
  }
  
  MDB_dbi dbi;

  /* lattice_t *lattice = lattice_create(); */
  return 0;
}
