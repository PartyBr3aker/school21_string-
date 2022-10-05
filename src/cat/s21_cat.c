#include "s21_cat.h"

int main(int argc, char *argv[]) {
  FLAGS flags = {0, 0, 0, 0, 0, 0};
  int recieved_flag = 0, file_exists = SUCCEED, flags_parsed = SUCCEED;
  static struct option long_opt[] = {{"number-nonblank", 0, 0, 'b'},
                                     {"number", 0, 0, 'n'},
                                     {"squeeze-blank", 0, 0, 's'},
                                     {0, 0, 0, 0}};
  int *flag_getopt = NULL;
  while ((recieved_flag = getopt_long(argc, argv, "benstvET", long_opt,
                                      flag_getopt)) != -1) {
    GetFlags(&recieved_flag, &flags, &flags_parsed);
  }
  FILE *fileptr = NULL;
  int current_file = optind;
  while (current_file < argc && flags_parsed == SUCCEED) {
    if (argc > 1) {
      fileptr = fopen(argv[current_file], "rb");
      if (fileptr == NULL) {
        fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
                argv[current_file]);
        file_exists = ERROR;
      }
    }
    if (file_exists == SUCCEED) {
      int linenumber = 1;
      Output(fileptr, &flags, &linenumber);
      fclose(fileptr);
      linenumber = 1;
    }
    current_file++;
    file_exists = SUCCEED;
  }
  return 0;
}

void GetFlags(const int *recieved_flag_ptr, FLAGS *flags_ptr,
              int *flags_parsed_ptr) {
  if (*recieved_flag_ptr == 'b') {
    flags_ptr->bflag = 1;
  } else if (*recieved_flag_ptr == 'e') {
    flags_ptr->eflag = 1;
    flags_ptr->vflag = 1;
  } else if (*recieved_flag_ptr == 'E') {
    flags_ptr->eflag = 1;
  } else if (*recieved_flag_ptr == 'n') {
    flags_ptr->nflag = 1;
  } else if (*recieved_flag_ptr == 's') {
    flags_ptr->sflag = 1;
  } else if (*recieved_flag_ptr == 't') {
    flags_ptr->tflag = 1;
    flags_ptr->vflag = 1;
  } else if (*recieved_flag_ptr == 'T') {
    flags_ptr->tflag = 1;
  } else if (*recieved_flag_ptr == 'v') {
    flags_ptr->vflag = 1;
  } else {
    *flags_parsed_ptr = ERROR;
    fprintf(stderr,
            "usage: s21_cat [-beEnstTv --number --number-nonblank "
            "--squeeze-blank] [file ...]\n");
  }
}

void Output(FILE *fileptr, const FLAGS *flags_ptr, int *ptr_numline) {
  char lettr = 0;
  lettr = fgetc(fileptr);
  while (!feof(fileptr)) {
    if (flags_ptr->sflag) SqueezeNearBlankLinesS(fileptr, &lettr);
    if (flags_ptr->nflag || flags_ptr->bflag)
      NumberOutputLineNB(&lettr, flags_ptr->bflag, ptr_numline);
    ScanOneStrETV(fileptr, &lettr, flags_ptr->eflag, flags_ptr->tflag,
                  flags_ptr->vflag);
  }
}

void NumberOutputLineNB(const char *checkltr, const int bflag,
                        int *ptr_numline) {
  if (*checkltr != '\n' && *checkltr != EOF && bflag) {
    printf("%6d\t", (*ptr_numline)++);
  } else if (!bflag && *checkltr != EOF) {
    printf("%6d\t", (*ptr_numline)++);
  }
}

void SqueezeNearBlankLinesS(FILE *fileptr, char *checkltr) {
  if (*checkltr == '\n') {
    while (*checkltr == '\n') {
      *checkltr = fgetc(fileptr);
    }
    if (*checkltr != EOF) {
      fseek(fileptr, -1, SEEK_CUR);
    }
    *checkltr = '\n';
  }
}

void ScanOneStrETV(FILE *fileptr, char *checkltr, const int eflag,
                   const int tflag, const int vflag) {
  while (*checkltr != '\n' && *checkltr != EOF) {
    if (tflag && *checkltr == '\t') {
      printf("%2s", "^I");
    } else if (vflag) {
      OutputOneCharVflagEnabled(checkltr);
    } else {
      fputc(*checkltr, stdout);
    }
    *checkltr = fgetc(fileptr);
  }
  if (eflag && *checkltr == '\n') {
    printf("%2s", "$\n");
    *checkltr = fgetc(fileptr);
  } else if (*checkltr == '\n') {
    fputc(*checkltr, stdout);
    *checkltr = fgetc(fileptr);
  }
}

void OutputOneCharVflagEnabled(char *checkltr) {
  int nonprintnum = 0;
  char nonprinting[][5] = {
      "^@", "^A", "^B", "^C", "^D", "^E", "^F",  "^G", "^H", "^I", "^J",
      "^K", "^L", "^M", "^N", "^O", "^P", "^Q",  "^R", "^S", "^T", "^U",
      "^V", "^W", "^X", "^Y", "^Z", "^[", "^\\", "^]", "^^", "^_", "^?"};
  for (int i = 0; i <= 31; i++) {
    if (*checkltr == i && i != 9 && i != 10) {
      nonprintnum = i;
    }
  }
  if (*checkltr == nonprintnum) {
    printf("%s", nonprinting[nonprintnum]);
  } else if (*checkltr == 127) {
    printf("%s", nonprinting[32]);
  } else {
    fputc(*checkltr, stdout);
  }
}