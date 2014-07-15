#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "ltc_env.h"


int ltc_env_open(ltc_env_t *env, const char *path, mdb_mode_t mode) {

  /* Try to create the environment */
  int rv = mdb_env_create(&(env->mdb_env));
  if (rv != 0) {
    printf("Error creating database environment.\n"
           "Error message: %s\nExiting now.\n", strerror(rv));
    mdb_env_close(env->mdb_env);
    exit(EXIT_FAILURE);
  }

  /* Try to open the environment */
  rv = mdb_env_open(env->mdb_env, path, 0, mode);
  if (rv != 0) {
    printf("Error opening database environment.\n"
           "Error message: %s\nExiting now.\n", strerror(rv));
    mdb_env_close(env->mdb_env);
    exit(EXIT_FAILURE);
  }
  
  MDB_txn *txn;
  rv = mdb_txn_begin(env->mdb_env, NULL, 0, &txn);
  if (rv != 0) {
    printf("Error opening database: Could not create transaction.\n"
           "Error message: %s\n Exiting now.\n", strerror(rv));
    mdb_env_close(env->mdb_env);
    exit(EXIT_FAILURE);
  }

  rv = mdb_dbi_open(txn, NULL, 0, &(env->dbi));
  if (rv != 0) {
    printf("Error opening database.\n"
           "Error message: %s\n Exiting now.\n", strerror(rv));
    mdb_txn_abort(txn);
    mdb_env_close(env->mdb_env);
    exit(EXIT_FAILURE);
  }

  rv = mdb_txn_commit(txn);
  if (rv != 0) {
    printf("Error opening database: Could not commit transaction.\n"
           "Error message: %s\n Exiting now.\n", strerror(rv));
    mdb_txn_abort(txn);
    mdb_env_close(env->mdb_env);
    exit(EXIT_FAILURE);
  }

  return 0;
}

int ltc_env_close(ltc_env_t env) { 
  mdb_dbi_close(env.mdb_env, env.dbi);
  mdb_env_close(env.mdb_env);
}
