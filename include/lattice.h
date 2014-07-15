#ifndef LATTICE_H
#define LATTICE_H
#ifdef __cplusplus 
extern "C" {
#endif
  
  extern void prepend_string(char *string, const char* prefix);
  extern char *get_full_path_nonexistant(const char *relative_path);
  
#ifdef __cplusplus
}
#endif
#endif /* LATTICE_H */
