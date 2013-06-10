/* -*- mode: C -*- Time-stamp: "2009-05-29 10:40:56 stevenv"
 *
 *       File:         xyztk-quat.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#include "xyztk-status.h"
#include "xyztk-quat.h"

#include <math.h>

/* copy two quaternions */
xyztk_status_t
xyztk_quat_copy (xyztk_quat_t *q, const xyztk_quat_t *a)
{
  q->w = a->w;
  q->x = a->x;
  q->y = a->y;
  q->z = a->z;
  return XYZTK_OK;
}

/* addition of two quaternions */
xyztk_status_t
xyztk_quat_add (xyztk_quat_t *q, const xyztk_quat_t *a, const xyztk_quat_t *b)
{
  q->w = a->w + b->w;
  q->x = a->x + b->x;
  q->y = a->y + b->y;
  q->z = a->z + b->z;
  return XYZTK_OK;
}

/* multiplication of quaternion and real number
 * q = s q */
xyztk_status_t
xyztk_quat_scal (xyztk_quat_t *q, const double s)
{
  q->w *= s;
  q->x *= s;
  q->y *= s;
  q->z *= s;
  return XYZTK_OK;
}

/* multiplication of two quaternions
 * q = a b */
xyztk_status_t
xyztk_quat_mult (xyztk_quat_t *q, const xyztk_quat_t *a, const xyztk_quat_t *b)
{
  q->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
  q->x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
  q->y = a->w * b->y + a->y * b->w + a->z * b->x - a->x * b->z;
  q->z = a->w * b->z + a->z * b->w + a->x * b->y - a->y * b->x;
  return XYZTK_OK;
}

/* norm of a quaternion */
double
xyztk_quat_norm (const xyztk_quat_t *q)
{
  return sqrt (q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
}

/* conjugate of a quaternion */
xyztk_status_t
xyztk_quat_conj (xyztk_quat_t *q, const xyztk_quat_t *r)
{
  q->w =   r->w;
  q->x = - r->x;
  q->y = - r->y;
  q->z = - r->z;
  return XYZTK_OK;
}

/* inverse of a quaternion */
xyztk_status_t
xyztk_quat_inv (xyztk_quat_t *q, const xyztk_quat_t *r)
{
  double tmp = r->w * r->w + r->x * r->x + r->y * r->y + r->z * r->z;
  q->w =   r->w / tmp;
  q->x = - r->x / tmp;
  q->y = - r->y / tmp;
  q->z = - r->z / tmp;
  return XYZTK_OK;
}

/* convert rotation to quaternion
 * rotation r = (a,x,y,z) with a the angle of rotation in degrees and (x,y,z) the axis of rotation
 * quaternion v = cos(a/2) + u * sin(a/2) where u is the normalized vector along (x,y,z)
 * convert r to q for use in quaternion rotations: q v q^-1 */
xyztk_status_t
xyztk_quat_rf (xyztk_quat_t *q, const xyztk_quat_t *r)
{
  double norm = (r->x * r->x + r->y * r->y + r->z * r->z);
  double angle = r->w * M_PI / 360;
  q->w = cos (angle);
  q->x = sin (angle) * r->x / norm;
  q->y = sin (angle) * r->y / norm;
  q->z = sin (angle) * r->z / norm;
  return XYZTK_OK;
}
