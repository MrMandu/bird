/*
 *	BIRD -- Password handling
 *
 *	(c) 1999 Pavel Machek <pavel@ucw.cz>
 *	(c) 2004 Ondrej Filip <feela@network.cz>
 *
 *	Can be freely distributed and used under the terms of the GNU GPL.
 */

#ifndef PASSWORD_H
#define PASSWORD_H
#include "sysdep/unix/timer.h"

struct password_item {
  node n;
  char *password;
  int id;
  bird_clock_t accfrom, accto, genfrom, gento;
};

extern struct password_item *last_password_item;

struct password_item *password_find(list *l, int first_fit);
struct password_item *password_find_by_id(list *l, int id);
struct password_item *password_find_by_value(list *l, char *pass, uint size);

static inline int password_verify(struct password_item *p1, char *p2, uint size)
{
  char buf[size];
  strncpy(buf, p1->password, size);
  return !memcmp(buf, p2, size);
}

#endif
