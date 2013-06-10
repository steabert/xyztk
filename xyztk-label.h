/* -*- mode: C -*- Time-stamp: "2009-05-29 16:08:11 stevenv"
 *
 *       File:         xyztk-label.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#ifndef XYZTK_LABEL_H
#define XYZTK_LABEL_H

/* BEGIN PUBLIC */

typedef struct xyztk_label_s xyztk_label_t;

/* copy two quaternions */
xyztk_status_t
xyztk_label_strip (xyztk_label_t *l);

/* END PUBLIC */

struct xyztk_label_s
{
  char s[XYZTK_MAXLABEL];
};

#endif /* XYZTK_LABEL_H */
