#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "ltc_env.h"
#include "ltc_util.h"

/**
 * Run the main program
 * (just creates a graph for now)
 */
int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("Usage: lattice_demo env");
    exit(-1);
  }

  //char dest[500];
  //get_full_path_nonexistant(dest, argv[1]);
  ltc_env_t env;
  ltc_env_open(&env, argv[1], 0666);

  /* dbi is open here! */
  /* lattice *lat = lattice_create(); */
  ltc_env_close(env);
  return 0;
}
