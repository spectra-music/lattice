#include <stdlib.h>
#include <stdio.h>
#include <lmdb.h>
#include <errno.h>
#include <limits.h>
#include <string.h>


/**
 * Prepends t into s. Assumes s has enough space allocated
 * for the combined string.
 * From http://stackoverflow.com/questions/2328182/prepending-to-a-string
 */
inline static void prepend_string(char* s, const char* t) {
    size_t len = strlen(t);
    memmove(s + len, s, strlen(s) + 1);
    for (size_t i = 0; i < len; ++i) {
        s[i] = t[i];
    }
}


static char *get_full_path_nonexistant(const char *relative_path) {
  /* Make a copy of relative_path so we can mess around */
  char relpath[strlen(relative_path)];
  strcpy(relpath, relative_path);

  /* This pointer will go to the full path */
  char* full_path;

  /* try to get the full path */
  if ( (full_path = realpath(relpath, NULL)) != NULL) {
    return full_path;
  }

  /* We couldn't find the path easily. Time to get our hands dirty. */

  /* Allocate a new string that's the size of the relative path */
  char relpath_tail[strlen(relpath)+2];  /* the '2' is for our "./" prepend */

  /* First, let's try adding "./" to the front, 
     if we're not the root or already a '.' to make our lives easier */
  if (relative_path[0] != '/' || relative_path[0] != '.') {
    prepend_string(relpath, "./");
  }

  /* Travel the relpath backwards, searching for a '/' so we can go up a level */
  for (int i = strlen(relpath) - 1; i >= 0; i--) {
    /* We hit a new directory! */
    if (relpath[i] == '/') {                       
      prepend_string(relpath_tail, (relpath + i)); // So copy everything after and including the '/' to a buffer
      relpath[i] = '\0';                           // Set the end of the string to the current location (assign null-term)
      /* if we can successfully */
      if( (full_path = realpath(relpath, NULL)) != NULL) {
        return full_path;
      }
    }
  }
  
  /* If we still haven't gotten the full_path, assume the 
     file doesn't exist. Because we tried everything. */
  printf("Error: could not resolve file path: %s", relative_path);
  exit(EXIT_FAILURE);
}

/**
 * Run the main program
 * (just creates a graph for now)
 */
int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("Usage: lattice_demo env/my_db.ltc");
  }

  char *full_path = get_or_create_full_path(argv[1]);
  MDB_env *env;  /* This is the database environment (directory, etc.) */

  /* Try to initialize the environment */
  int rv = mdb_env_create(&env);
  if ( rv != 0 ) {
    printf("Error creating database environment. Error code: %d\n Exiting now.\n", rv);
    exit(EXIT_FAILURE);
  }


  
  MDB_dbi dbi;

  /* lattice_t *lattice = lattice_create(); */

  free(full_path);
  return 0;
}
