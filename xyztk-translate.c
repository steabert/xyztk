/* -*- mode: C -*- Time-stamp: "2009-05-29 15:53:15 stevenv"
 *
 *       File:         xyztk-translate.c
 *       Date:         May 2009
 *
 *       xyztk project - toolkit for operations on xyz files
 *
 */

#include "xyztk-status.h"
#include "xyztk-label.h"
#include "xyztk-quat.h"
#include "xyztk-molecule.h"

#include <argtable2.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct arg_lit *help;
    struct arg_file *input, *output;
    struct arg_str *translation;
    struct arg_end *end;

    /* command line parsing through argtable package */
    void* argtable[] = {
        help        = arg_lit0("h", "help", "display this help and exit"),
        input       = arg_file0("i", "input", "filename", "name of the input file (default stdin)"),
        output      = arg_file0("o", "output", "filename", "name of the output file (default stdout)"),
        translation = arg_str1(NULL, NULL, "\"x y z\"", "translate along vector x y z"),
        end         = arg_end(20) };
    const char* progname = "xyztk-translate";
    int rc = 0;
    int nerrors;

    /* verify the argtable[] entries were allocated sucessfully */
    if (arg_nullcheck(argtable) != 0)
        {
        /* NULL entries were detected, some allocations must have failed */
        printf("%s: insufficient memory\n", progname);
        rc=1;
        goto exit;
        }

    /* set default values */

    /* parse the command line flags, overriding default values */
    nerrors = arg_parse(argc,argv,argtable);

    /* special case: '--help' takes precedence over error reporting */
    if (help->count > 0)
        {
        printf("Usage: %s", progname);
        arg_print_syntax(stdout,argtable,"\n");
        printf("\n");
        arg_print_glossary(stdout,argtable,"  %-40s %s\n");
        printf("\n");
        rc=0;
        goto exit;
        }

    /* special case: no command line options induces brief help */
    if (argc==1) {
        printf("Try '%s --help' for more information.\n",progname);
        rc=0;
        goto exit;
    }

    /* If the parser returned any errors then display them and exit */
    if (nerrors > 0)
        {
        /* Display the error details contained in the arg_end struct.*/
        arg_print_errors(stdout,end,progname);
        printf("Try '%s --help' for more information.\n",progname);
        rc=1;
        goto exit;
        }

    /* set global structures */

    /* initialize I/O pointers */
    FILE* in;
    if (input->count) {
      in = fopen(input->filename[0], "r");
    } else {
      in = stdin;
    }

    FILE* out;
    if (output->count) {
      out = fopen(output->filename[0], "w");
    } else {
      out = stdout;
    }

    /* initialize molecule structure */
    xyztk_molecule_t molecule;
    xyztk_molecule_load (&molecule, in);

    /* read rotation from string */
    xyztk_quat_t t;
    sscanf (translation->sval[0], "%lf%lf%lf", &t.x, &t.y, &t.z);
    xyztk_molecule_translate (&molecule, &t);

    /* print output */
    int i;
    fprintf(out, "%d\n", molecule.n_atoms);
    fprintf(out, "%s", molecule.name);
    for (i = 0; i < molecule.n_atoms; ++i)
      {
      fprintf(out, "%-8s %20.14lf %20.14lf %20.14lf \n",
	      molecule.label[i].s, molecule.coord[i].x, molecule.coord[i].y, molecule.coord[i].z);
      }

exit:
    /* deallocate each non-null entry in argtable[] */
    arg_freetable(argtable,sizeof(argtable)/sizeof(argtable[0]));

    return rc;
}
