/* -*- mode: C -*- Time-stamp: "2009-05-29 10:40:56 stevenv"
 *
 *       File:         xyztk-quat.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#include "xyztk-status.h"
#include "xyztk-label.h"

#include <math.h>
#include <ctype.h>
#include <string.h>

/* strip label */
xyztk_status_t
xyztk_label_strip (xyztk_label_t *l)
{
  int i = 0;
  while (!isdigit (l->s[i]) && i < strlen (l->s)) ++i;
  l->s[i] = '\0';
  return XYZTK_OK;
}

