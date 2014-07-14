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
    printf("Usage: lattice_demo env");
  }

  char dest[_POSIX_PATH_MAX];
  get_full_path_nonexistant(dest, argv[1]);
  MDB_env *env;  /* This is the database environment (directory, etc.) */

  /* Try to create the environment */
  int rv = mdb_env_create(&env);
  if (rv != 0) {
    printf("Error creating database environment.\nError code: %d\n Exiting now.\n", rv);
    mdb_env_close(env);
    exit(EXIT_FAILURE);
  }

  /* Try to open the environment */
  rv = mdb_env_open(env, dest, 0, 755);
  if (rv != 0) {
    printf("Error opening database environment.\nError code: %d\n Exiting now.\n", rv);
    mdb_env_close(env);
    exit(EXIT_FAILURE);
  }

  MDB_dbi dbi;
  MDB_txn *txn;
  rv = mdb_txn_begin(env, NULL, 0, txn);
  if (rv != 0) {
    printf("Error opening database: Could not create transaction.\n"
           "Error code: %d\n Exiting now.\n", rv);
    mdb_env_close(env);
    exit(EXIT_FAILURE);
  }

  rv = mdb_dbi_open(txn, NULL, 0, dbi);
  if (rv != 0) {
    printf("Error opening database.\n"
           "Error code: %d\n Exiting now.\n", rv);
    mdb_txn_abort(txn);
    mdb_env_close(env);
    exit(EXIT_FAILURE);
  }



  mdb_dbi_close(env,dbi);
  mdb_env_close(env);
  /* lattice *lat = lattice_create(); */
  return 0;
}
