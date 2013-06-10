/* -*- mode: C -*- Time-stamp: "2009-05-29 10:59:59 stevenv"
 *
 *       File:         xyztk-molecule.c
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#include "xyztk-molecule.h"

#include <stdio.h>
#include <stdlib.h>

xyztk_status_t
xyztk_molecule_load (xyztk_molecule_t *molecule, FILE *xyz)
{
  int i;
  fscanf (xyz, "%d\n", &(molecule->n_atoms));

  fgets(molecule->name, XYZTK_MAXLINE, xyz);
  
  molecule->label = (xyztk_label_t *) malloc (molecule->n_atoms * sizeof (xyztk_label_t));
  if (molecule->label == NULL) return XYZTK_EMEM;

  molecule->coord = (xyztk_quat_t *) malloc (molecule->n_atoms * sizeof (xyztk_quat_t));
  if (molecule->coord == NULL) return XYZTK_EMEM;

  for (i=0; i<molecule->n_atoms; ++i) {
    fscanf(xyz, "%s %lf %lf %lf", molecule->label[i].s,
	   &(molecule->coord[i].x), &(molecule->coord[i].y), &(molecule->coord[i].z));
  }

  return XYZTK_OK;
}

xyztk_status_t
xyztk_molecule_empty (xyztk_molecule_t *molecule)
{
  free (molecule->coord);
  free (molecule->label);
  return XYZTK_OK;
}

xyztk_status_t
xyztk_molecule_strip (xyztk_molecule_t *molecule)
{
  int i;
  
  for (i = 0; i < molecule->n_atoms; i++)
    {
      xyztk_label_strip (molecule->label+i);
    }
  return XYZTK_OK;
}

xyztk_status_t
xyztk_molecule_scale (xyztk_molecule_t *molecule, const double s)
{
  int i;
  
  for (i = 0; i < molecule->n_atoms; i++)
    {
      xyztk_quat_scal (molecule->coord+i, s);
    }
  return XYZTK_OK;
}

xyztk_status_t
xyztk_molecule_translate (xyztk_molecule_t *molecule, const xyztk_quat_t *t)
{
  int i;
  xyztk_quat_t a;
  
  for (i = 0; i < molecule->n_atoms; i++)
    {
      xyztk_quat_copy (&a, molecule->coord+i);
      xyztk_quat_add (molecule->coord+i, t, &a);
    }
  return XYZTK_OK;
}

xyztk_status_t
xyztk_molecule_rotate (xyztk_molecule_t *molecule, const xyztk_quat_t *r)
{
  int i;
  xyztk_quat_t q;
  xyztk_quat_rf (&q, r);

  xyztk_quat_t q_conj;
  xyztk_quat_conj (&q_conj, &q);
  
  xyztk_quat_t p;
  
  for (i = 0; i < molecule->n_atoms; i++)
    {
      xyztk_quat_mult (&p, &q, molecule->coord+i);
      xyztk_quat_mult (molecule->coord+i, &p, &q_conj);
    }
  return XYZTK_OK;
}
