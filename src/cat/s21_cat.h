#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCEED 0
#define ERROR -1

typedef struct {
  int bflag, eflag, nflag, sflag, tflag, vflag;
} FLAGS;

void GetFlags(const int *recieved_flag_ptr, FLAGS *flags_ptr,
              int *flags_parsed_ptr);
void Output(FILE *fileptr, const FLAGS *flags_ptr, int *ptr_numline);
void NumberOutputLineNB(const char *checkltr, const int bflag,
                        int *ptr_numline);
void SqueezeNearBlankLinesS(FILE *fileptr, char *checkltr);
void ScanOneStrETV(FILE *fileptr, char *checkltr, const int eflag,
                   const int tflag, const int vflag);
void OutputOneCharVflagEnabled(char *checkltr);

#endif  // SRC_CAT_S21_CAT_H_