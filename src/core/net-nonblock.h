#ifndef __NET_NONBLOCK_H
#define __NET_NONBLOCK_H

#include "network.h"

typedef struct {
	IPADDR ip4, ip6; /* resolved ip addresses */
	int error; /* error, 0 = no error, -1 = error: */
	int errlen; /* error text length */
	char *errorstr; /* error string - dynamically allocated, you'll
	                   need to free() it yourself unless it's NULL */
	char *host4, *host6; /* dito */
} RESOLVED_IP_REC;

/* nonblocking gethostbyname(), PID of the resolver child is returned. */
int net_gethostbyname_nonblock(const char *addr, GIOChannel *pipe,
			       int reverse_lookup);
/* get the resolved IP address. returns -1 if some error occurred with read() */
int net_gethostbyname_return(GIOChannel *pipe, RESOLVED_IP_REC *rec);

/* Kill the resolver child */
void net_disconnect_nonblock(int pid);

#endif
