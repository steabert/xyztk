/* -*- mode: C -*- Time-stamp: "2009-05-29 16:07:41 stevenv"
 *
 *       File:         xyztk-molecule.h
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#ifndef XYZTK_MOLECULE_H
#define XYZTK_MOLECULE_H

#include "xyztk-status.h"
#include "xyztk-label.h"
#include "xyztk-quat.h"

#include <stdio.h>

/* BEGIN PUBLIC */

typedef struct xyztk_molecule_s xyztk_molecule_t;

xyztk_status_t
xyztk_molecule_load (xyztk_molecule_t *molecule, FILE *xyz);

xyztk_status_t
xyztk_molecule_empty (xyztk_molecule_t *molecule);

xyztk_status_t
xyztk_molecule_strip (xyztk_molecule_t *molecule);

xyztk_status_t
xyztk_molecule_scale (xyztk_molecule_t *molecule, const double s);
 
xyztk_status_t
xyztk_molecule_translate (xyztk_molecule_t *molecule, const xyztk_quat_t *q);

xyztk_status_t
xyztk_molecule_rotate (xyztk_molecule_t *molecule, const xyztk_quat_t *q);

/* END PUBLIC */

struct xyztk_molecule_s
{
  unsigned int n_atoms;
  char name[XYZTK_MAXLINE];
  xyztk_label_t *label;
  xyztk_quat_t *coord;
};

#endif /* XYZTK_MOLECULE_H */
