#ifndef LTC_ENV_H
#define LTC_ENV_H
#include <lmdb.h>

#ifdef __cplusplus 
extern "C" {
#endif

typedef struct {
  MDB_env *mdb_env;
  MDB_dbi dbi;
} ltc_env_t;

extern int ltc_env_open(ltc_env_t *env, const char *path, mdb_mode_t mode);
extern int ltc_env_close(ltc_env_t env);
#ifdef __cplusplus
}
#endif

#endif /* LTC_ENV_H */
