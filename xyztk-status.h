/* -*- mode: C -*- Time-stamp: "2009-05-29 11:01:05 stevenv"
 *
 *       File:         xyztk-status.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#ifndef XYZTK_H
#define XYZTK_H

/* BEGIN PUBLIC */

#define XYZTK_MAXLABEL 8
#define XYZTK_MAXLINE 256

typedef enum xyztk_status_e xyztk_status_t;

/* END PUBLIC */

enum xyztk_status_e
  {
    XYZTK_OK = 0,
    XYZTK_ERROR,
    XYZTK_EIO,
    XYZTK_EMEM,
    XYZTK_EBADARG
  };

#endif /* XYZTK_H */
