#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "lattice_util.h"

/**
 * Prepends t into s. Assumes s has enough space allocated
 * for the combined string.
 * From http://stackoverflow.com/questions/2328182/prepending-to-a-string
 */
static void prepend_string(char* s, const char* t) {
    size_t len = strlen(t);
    memmove(s + len, s, strlen(s) + 1);
    for (size_t i = 0; i < len; ++i) {
        s[i] = t[i];
    }
}


void get_full_path_nonexistant(char *dest, const char *relative_path) {
  /* This pointer will go to the full path */
  char* full_path;

  /* try to get the full path */
  if ( (full_path = realpath(relative_path, NULL)) != NULL) {
    free(full_path);
    strcpy(dest, relative_path);
    return;
  }

  // If we're root, we exist. duh.
  if (relative_path[0] == '/') {
    strcpy(dest,relative_path);
    return;
  }

  /* We couldn't find the path easily. Time to get our hands dirty. */

  /* Make a copy of relative_path so we can mess around */
  char relpath[strlen(relative_path)];
  strcpy(relpath, relative_path);

  /* Allocate a new string that's the size of the relative path */
  char relpath_tail[strlen(relpath)+2];  /* the '2' is for our "./" prepend */
  relpath_tail[0] = '\0';

  /* First, let's try adding "./" to the front, 
     if we're not already a "./" to make our lives easier */
  if (relative_path[0] != '.' || relative_path[1] != '/') {
    prepend_string(relpath, "./");
  }

  // Travel the relpath backwards, searching for a '/' so we can go up a level
  for (int i = strlen(relpath) - 1; i >= 0; i--) {
    // We hit a new directory!
    if (relpath[i] == '/') {
      prepend_string(relpath_tail, relpath + i); // So copy everything after and including the '/' to a buffer
      relpath[i] = '\0';                         // Set the end of the string to the current location (assign null-term)

      /* if we can successfully find the fullpath */
      if( (full_path = realpath(relpath, NULL)) != NULL) {
        free(full_path);
        strcpy(dest, relpath);
        strcat(dest, relpath_tail);
        return;
      }
    }
  }
  
  /* If we still haven't gotten the full_path, assume the 
     file doesn't exist. Because we tried everything. */
}
