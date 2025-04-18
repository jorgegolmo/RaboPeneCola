/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _SET_H_RPCGEN
#define _SET_H_RPCGEN

#include <rpc/rpc.h>
#include "claves.h"


#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct Coord Coord;

typedef struct {
	u_int doubles_array_len;
	double *doubles_array_val;
} doubles_array;

struct set_value_rpc_1_argument {
	int key;
	char *value1;
	doubles_array V_value2;
	struct Coord value3;
};
typedef struct set_value_rpc_1_argument set_value_rpc_1_argument;

#define TUPLAS 11710
#define PRUEBA 1

#if defined(__STDC__) || defined(__cplusplus)
#define set_value_rpc 1
extern  enum clnt_stat set_value_rpc_1(int , char *, doubles_array , struct Coord , int *, CLIENT *);
extern  bool_t set_value_rpc_1_svc(int , char *, doubles_array , struct Coord , int *, struct svc_req *);
#define exist_rpc 2
extern  enum clnt_stat exist_rpc_1(int , int *, CLIENT *);
extern  bool_t exist_rpc_1_svc(int , int *, struct svc_req *);
extern int tuplas_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define set_value_rpc 1
extern  enum clnt_stat set_value_rpc_1();
extern  bool_t set_value_rpc_1_svc();
#define exist_rpc 2
extern  enum clnt_stat exist_rpc_1();
extern  bool_t exist_rpc_1_svc();
extern int tuplas_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_Coord (XDR *, Coord*);
extern  bool_t xdr_doubles_array (XDR *, doubles_array*);
extern  bool_t xdr_set_value_rpc_1_argument (XDR *, set_value_rpc_1_argument*);

#else /* K&R C */
extern bool_t xdr_Coord ();
extern bool_t xdr_doubles_array ();
extern bool_t xdr_set_value_rpc_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SET_H_RPCGEN */
