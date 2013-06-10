/* -*- mode: C -*- Time-stamp: "2009-05-29 16:08:11 stevenv"
 *
 *       File:         xyztk-quat.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#ifndef XYZTK_QUAT_H
#define XYZTK_QUAT_H

/* BEGIN PUBLIC */

typedef struct xyztk_quat_s xyztk_quat_t;

/* copy two quaternions */
xyztk_status_t
xyztk_quat_copy (xyztk_quat_t *q, const xyztk_quat_t *a);

/* addition of two quaternions
 * q = a + b */
xyztk_status_t
xyztk_quat_add (xyztk_quat_t *q, const xyztk_quat_t *a, const xyztk_quat_t *b);

/* scalar multiplication of a quaternion with a number
 * q = s * q */
xyztk_status_t
xyztk_quat_scal (xyztk_quat_t *q, const double s);

/* scalar multiplication of two quaternions
 * q = a * b */
xyztk_status_t
xyztk_quat_mult (xyztk_quat_t *q, const xyztk_quat_t *a, const xyztk_quat_t *b);

/* vector multiplication of two quaternions
 * q = a x b */
xyztk_status_t
xyztk_quat_vect (xyztk_quat_t *q, const xyztk_quat_t *a, const xyztk_quat_t *b);

/* norm of a quaternion */
double
xyztk_quat_norm (const xyztk_quat_t *q);

/* conjugate of a quaternion
 * q = conj(a) */
xyztk_status_t
xyztk_quat_conj (xyztk_quat_t *q, const xyztk_quat_t *a);

/* inverse of a quaternion
 * q = inv(a) (q * a = 1) */
xyztk_status_t
xyztk_quat_inv (xyztk_quat_t *q, const xyztk_quat_t *a);

/* convert rotation to quaternion
 * rotation r = (a,x,y,z) with a the angle of rotation in degrees and (x,y,z) the axis of rotation
 * quaternion v = cos(a/2) + u * sin(a/2) where u is the normalized vector along (x,y,z)
 * convert r to q for use in quaternion rotations: q v q^-1 */
xyztk_status_t
xyztk_quat_rf (xyztk_quat_t *q, const xyztk_quat_t *r);

/* END PUBLIC */

struct xyztk_quat_s
{
  double w;
  double x;
  double y;
  double z;
};

#endif /* XYZTK_QUAT_H */
