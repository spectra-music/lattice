#ifndef LTC_TYPE_H
#define LTC_TYPE_H
#include <stdlib.h>


#ifndef LTC_MAX_TYPE_NAME_LEN
#define LTC_MAX_TYPE_NAME_LEN 30
#endif // LTC_MAX_TYPE_NAME_LEN

#ifdef __cplusplus 
extern "C" {
#endif
  
typedef struct ltc_vertex_type_t {
  char name[LTC_MAX_TYPE_NAME_LEN];
  struct ltc_vertex_type_t *parents;    // This is a list of direct parents only
  size_t num_parents;
  char **fields;                         // valid field names are [a-zA-Z0-9_]+
  size_t num_fields;
} ltc_vertex_type_t;


extern ltc_vertex_type_t *ltc_create_vertex_type(const char *name);
extern ltc_vertex_type_t *ltc_create_vertex_type_with_parents(const char *name, const char **parents);
extern ltc_vertex_type_t *ltc_vertex_type_get(const char *name);
extern ltc_
#ifdef __cplusplus
}
#endif

#endif /* LTC_TYPE_H */




