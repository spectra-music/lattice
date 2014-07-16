#ifndef __LTC_VERTEX_H__
#define __LTC_VERTEX_H__ 1


#include "type.h"


#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif


/**
 * @brief The in-memory
 */
typedef struct ltc_vertex ltc_vertex_t;
struct ltc_vertex {
  char **type; // e.g. ["Color", "RGBColor"]
} ltc_vertex_t;


#ifdef __cplusplus
}
#endif

#endif /* __LTC_VERTEX_H__ */
