/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCOPS_H_RPCGEN
#define _RPCOPS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define RPCPROGRAM 0x20000003
#define RPCPROGVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADDNUM 1
extern  int * addnum_1(int *, CLIENT *);
extern  int * addnum_1_svc(int *, struct svc_req *);
#define STRREV 2
extern  char ** strrev_1(char **, CLIENT *);
extern  char ** strrev_1_svc(char **, struct svc_req *);
#define SQNUM 3
extern  int * sqnum_1(int *, CLIENT *);
extern  int * sqnum_1_svc(int *, struct svc_req *);
extern int rpcprogram_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADDNUM 1
extern  int * addnum_1();
extern  int * addnum_1_svc();
#define STRREV 2
extern  char ** strrev_1();
extern  char ** strrev_1_svc();
#define SQNUM 3
extern  int * sqnum_1();
extern  int * sqnum_1_svc();
extern int rpcprogram_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPCOPS_H_RPCGEN */
