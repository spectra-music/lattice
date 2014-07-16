#ifndef __LTC_ENV_H__
#define __LTC_ENV_H__ 1


#include <lmdb.h>


#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif


typedef struct ltc_env ltc_env_t;
struct ltc_env {
  MDB_env *mdb_env;
  MDB_dbi dbi;
};


extern int ltc_env_open(ltc_env_t *env, const char *path, mdb_mode_t mode);

extern int ltc_env_close(ltc_env_t env);


#ifdef __cplusplus
}
#endif

#endif /* __LTC_ENV_H__ */
