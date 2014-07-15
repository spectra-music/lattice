#ifndef LTC_EDGE_H
#define LTC_EDGE_H
#include <stdbool.h>
#include <stdint.h>
#include "vertex.h"

#ifndef LTC_MAX_EDGE_NAME_LEN
#define LTC_MAX_EDGE_NAME_LEN 300
#endif // LTC_MAX_EDGE_NAME_LEN

#ifndef LTC_EDGE_WEIGHT_T
#define LTC_EDGE_WEIGHT_T uint32_t
#endif // LTC_EDGE_WEIGHT_T


typedef struct {
  char name[LTC_MAX_EDGE_NAME_LEN];
  bool is_directed;
  ltc_vertex_t *vertices[2];
  LTC_EDGE_WEIGHT_T weight;
} ltc_edge_t;


extern ltc_edge_t *ltc_edge_create(const char *name, 
                                   const ltc_vertex_t *vertex1,
                                   const ltc_vertex_t *vertex2);

extern ltc_edge_t *ltc_edge_create_directed(const char *name,
                                            const ltc_vertex_t *from, 
                                            const ltc_vertex_t *to);

extern ltc_edge_t *ltc_edge_create_weighted(const char *name,
                                            LTC_EDGE_WEIGHT_T weight,
                                            const ltc_vertex_t *vertex1,
                                            const ltc_vertex_t *vertex2);

extern ltc_edge_t *ltc_edge_create_directed_and_weighted(const char *name,
                                                         LTC_EDGE_WEIGHT_T weight,
                                                         const ltc_vertex_t *from, 
                                                         const ltc_vertex_t *to);


extern void ltc_edge_reverse(ltc_edge_t *edge);
extern int ltc_edge_save(ltc_env_t *env, ltc_edge_t *edge);
#endif /* LTC_EDGE_H */








