/*
  The oRTP library is an RTP (Realtime Transport Protocol - rfc1889) stack.
  Copyright (C) 2001  Simon MORLAT simon.morlat@linphone.org

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef STR_UTILS_H
#define STR_UTILS_H


#include <rtpport.h>


typedef struct msgb
{
	struct msgb *b_prev;
	struct msgb *b_next;
	struct msgb *b_cont;
	struct datab *b_datap;
	char *b_rptr;
	char *b_wptr;
} mblk_t;

typedef struct datab
{
	char *db_base;
	char *db_lim;
	void (*db_freefn)(void*);
	guint ref_count;
} dblk_t;

typedef struct _queue
{
	mblk_t _q_first;
	mblk_t _q_last;
	gint q_mcount;	/*number of packet in the q */
} queue_t;

#ifdef __cplusplus
extern "C" {
#endif

void qinit(queue_t *q);
	
void putq(queue_t *q, mblk_t *m);
mblk_t * getq(queue_t *q);

void insq(queue_t *q,mblk_t *emp, mblk_t *mp);
	
void remq(queue_t *q, mblk_t *mp);

void mblk_init(mblk_t *mp);
	
/* allocates a mblk_t, that points to a datab_t, that points to a buffer of size size. */
mblk_t *allocb(gint size,gint unused);
#define BPRI_MED 0

/* allocates a mblk_t, that points to a datab_t, that points to buf; buf will be freed using freefn */
mblk_t *allocb_with_buf(char *buf, int size, int pri, void (*freefn)(void*) );

/* frees a mblk_t, and if the datab ref_count is 0, frees it and the buffer too */
void freeb(mblk_t *m);

/* frees recursively (follow b_cont) a mblk_t, and if the datab
ref_count is 0, frees it and the buffer too */
void freemsg(mblk_t *mp);

/* duplicates a mblk_t , buffer is not duplicated*/
mblk_t *dupb(mblk_t *m);

/* duplicates a complex mblk_t, buffer is not duplicated */
mblk_t	*dupmsg(mblk_t* m);

/* remove and free all messages in the q */
#define FLUSHALL 0
void flushq(queue_t *q, int how);

/* returns the size of data of a message */
gint msgdsize(mblk_t *mp);

/* concatenates all fragment of a complex message ( a new message is returned, old is untouched*/
mblk_t * msgpullup(mblk_t *mp,int len);

/* duplicates a single message, but with buffer included */
mblk_t *copyb(mblk_t *mp);

/* duplicates a complex message with buffer included */
mblk_t *copymsg(mblk_t *mp);

mblk_t * appendb(mblk_t *mp, const char *data, int size, gboolean pad);
void msgappend(mblk_t *mp, const char *data, int size, gboolean pad);

mblk_t *concatb(mblk_t *mp, mblk_t *newm);

#define qempty(q) (&(q)->_q_last==(q)->_q_first.b_next)
#define qfirst(q) ((q)->_q_first.b_next!=&(q)->_q_last ? (q)->_q_first.b_next : NULL)
#define qbegin(q) ((q)->_q_first.b_next)
#define qlast(q) ((q)->_q_last.b_prev!=&(q)->_q_first ? (q)->_q_last.b_prev : NULL)
#define qend(q,mp)	((mp)==&(q)->_q_first || ((mp)==&(q)->_q_last))
#define qnext(q,mp) ((mp)->b_next)
#ifdef __cplusplus
}
#endif

#endif
