#include "ltc_edge.h"

ltc_edge_t *ltc_edge_create(const char *name, 
                            const ltc_vertex_t *vertex1, 
                            const ltc_vertex_t *vertex2) {
  ltc_edge_t *edge = (ltc_edge_t*)malloc(sizeof(ltc_edge_t));
  edge->is_directed = false;
  edge->weight = NULL;
  edge->vertices[0] = vertex1;
  edge->vertices[1] = vertex2;
  return edge;
}

ltc_edge_t *ltc_edge_create_weighted(const char *name, 
                                     LTC_EDGE_WEIGHT_T weight,
                                     const ltc_vertex_t *vertex1, 
                                     const ltc_vertex_t *vertex2) {
  ltc_edge_t *edge = (ltc_edge_t*)malloc(sizeof(ltc_edge_t));
  edge->is_directed = false;
  edge->weight = weight;
  edge->vertices[0] = vertex1;
  edge->vertices[1] = vertex2;
  return edge;
}

ltc_edge_t *ltc_edge_create_directed(const char *name, 
                                     const ltc_vertex_t *from, 
                                     const ltc_vertex_t *to) {
  ltc_edge_t *edge = (ltc_edge_t*)malloc(sizeof(ltc_edge_t));
  edge->is_directed = true;
  edge->weight = NULL;
  edge->vertices[0] = from;
  edge->vertices[1] = to;
  return edge;
}


ltc_edge_t *ltc_edge_create_weighted(const char *name, 
                                     LTC_EDGE_WEIGHT_T weight,
                                     const ltc_vertex_t *from, 
                                     const ltc_vertex_t *to) {
  ltc_edge_t *edge = (ltc_edge_t*)malloc(sizeof(ltc_edge_t));
  edge->is_directed = true;
  edge->weight = weight;
  edge->vertices[0] = from;
  edge->vertices[1] = to;
  return edge;
}

/**
 * @brief change the direction of an edge
 */
void ltc_edge_reverse(ltc_edge_t *edge) {
  if (!edge->is_directed) {
    return;
  }
  const ltc_vertex_t *v0 = edge->vertices[0];
  edge->vertices[0] = edge->vertices[1];
  edge->vertices[1] = v0;    
}
