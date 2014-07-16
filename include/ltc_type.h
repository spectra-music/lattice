#ifndef __LTC_TYPE_H__
#define __LTC_TYPE_H__ 1


#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif


#ifndef LTC_MAX_TYPE_NAME_LEN
#define LTC_MAX_TYPE_NAME_LEN 30
#endif // LTC_MAX_TYPE_NAME_LEN


typedef struct ltc_vertex_type ltc_vertex_type_t;
struct ltc_vertex_type {
  char name[LTC_MAX_TYPE_NAME_LEN];
  ltc_vertex_type_t *parents;           // This is a list of direct parents only
  size_t num_parents;
  char **fields;                        // valid field names are [a-zA-Z0-9_]+
  size_t num_fields;
};


extern ltc_vertex_type_t *ltc_create_vertex_type(const char *name);

extern ltc_vertex_type_t *ltc_create_vertex_type_with_parents(const char *name,
                                                              const char **parents);

extern ltc_vertex_type_t *ltc_vertex_type_get(const char *name);


#ifdef __cplusplus
}
#endif

#endif /* __LTC_TYPE_H__ */
