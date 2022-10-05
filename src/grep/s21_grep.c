#include "s21_grep.h"

int main(int argc, char *argv[]) {
  FLAGS flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  LinesNode *patterns = Init();
  LinesNode *pat_files = Init();
  LinesNode *files = Init();
  int flags_parsed = SUCCEED, patfile_exists = SUCCEED, file_exists = SUCCEED;
  if (argc > 2) {
    while (optind < argc && flags_parsed == SUCCEED &&
           patfile_exists == SUCCEED) {
      GetOption(argc, argv, &flags, &flags_parsed, &patterns, &pat_files,
                files);
      if (patfile_exists == SUCCEED && optind < argc) {
        GetPattern(argv[optind], &flags, &patterns, &pat_files, 0, files);
        GetFile(files, &flags, argv[optind], 0);
      }
    }
    if (flags.fflag) {
      AddPatternFromFile(&patterns, pat_files, &patfile_exists, &flags,
                         argv[0]);
    }
    size_t linesize = MAXLENGTH;
    char *patternstring = (char *)malloc(linesize * sizeof(char));
    FormPatternString(&patternstring, &linesize, patterns, &flags);
    FILE *fileptr;
    LinesNode *filespointer = files->nextline;
    int cflags = REG_EXTENDED;
    FormCflags(&flags, &cflags);
    while (filespointer && flags_parsed == SUCCEED &&
           patfile_exists == SUCCEED) {
      fileptr = fopen(filespointer->line, "rb");
      BadFilePath(fileptr, &flags, filespointer->line, argv[0], &file_exists);
      if (file_exists == SUCCEED) {
        LinesNode *head = Init();
        int num_of_accepted_strings = 0;
        FillLinesNode(fileptr, head, patterns, &flags, &linesize, cflags,
                      patternstring, &num_of_accepted_strings);
        Output(head, filespointer->line, num_of_accepted_strings, &flags);
        DeleteList(&head);
        fclose(fileptr);
      }
      filespointer = filespointer->nextline;
      file_exists = SUCCEED;
    }
    free(patternstring);
  } else {
    while (1) {
      getc(stdin);
    }
  }
  DeleteList(&patterns);
  DeleteList(&pat_files);
  DeleteList(&files);
  return 0;
}

// FUNCTIONS FOR WORK WITH INPUT
void GetFlags(int *recieved_flag_ptr, FLAGS *flag_ptr, int *flags_parsed_ptr) {
  // Adds every flag to the struct flags
  if (*recieved_flag_ptr == 'e') {
    flag_ptr->eflag++;
  } else if (*recieved_flag_ptr == 'i') {
    flag_ptr->iflag = 1;
  } else if (*recieved_flag_ptr == 'v') {
    flag_ptr->vflag = 1;
  } else if (*recieved_flag_ptr == 'c') {
    flag_ptr->cflag = 1;
  } else if (*recieved_flag_ptr == 'l') {
    flag_ptr->lflag = 1;
  } else if (*recieved_flag_ptr == 'n') {
    flag_ptr->nflag = 1;
  } else if (*recieved_flag_ptr == 'h') {
    flag_ptr->hflag = 1;
  } else if (*recieved_flag_ptr == 's') {
    flag_ptr->sflag = 1;
  } else if (*recieved_flag_ptr == 'f') {
    flag_ptr->fflag++;
  } else if (*recieved_flag_ptr == 'o') {
    flag_ptr->oflag = 1;
  } else {
    *flags_parsed_ptr = ERROR;
    fprintf(stderr, "usage: s21_grep [-eivclnhsfo] [file ...]");
  }
}

void GetPattern(char *input, FLAGS *flag_ptr, LinesNode **patternhead,
                LinesNode **filepathead, const int while_call,
                LinesNode *fileshead) {
  // Adds patterns to pattern node
  static int callnum = 1, f_callnum = 1, e_callnum = 1, case_3 = 0;
  if (flag_ptr->eflag == e_callnum && while_call) {
    // Case 1 eflag enabled, adding pattern to node
    DeleteExtraPattern(patternhead, case_3, callnum, fileshead, flag_ptr);
    Shift(*patternhead, callnum, input, strlen(input));
    e_callnum++;
    callnum++;
  } else if (flag_ptr->fflag == f_callnum && while_call) {
    // Case 2 fflag enabled, adding pattern file to node of pattern files
    DeleteExtraPattern(patternhead, case_3, callnum, fileshead, flag_ptr);
    Shift(*filepathead, callnum, input, strlen(input));
    f_callnum++;
    callnum++;
  } else if (flag_ptr->eflag == 0 && flag_ptr->fflag == 0 && !while_call &&
             callnum == 1) {
    // Case 3 none of e and f flags are aktivated, adding only 1 pattern to node
    if (strstr(input, "-e") != 0 || strstr(input, "-f") != 0) {
      ;
    } else {
      Shift(*patternhead, callnum, input, strlen(input));
      optind++;
      callnum++;
      case_3 = 1;
    }
  }
}

void DeleteExtraPattern(LinesNode **patternhead, int case_3, int callnum,
                        LinesNode *fileshead, FLAGS *flag_ptr) {
  if (case_3 && callnum == 2) {
    if (patternhead == NULL) {
      exit(-1);
    }
    LinesNode *last = (*patternhead)->nextline;
    GetFile(fileshead, flag_ptr, last->line, 1);
    free(last->line);
    free(last);
    (*patternhead)->nextline = NULL;
  }
}

void GetOption(int argc, char **argv, FLAGS *flag_ptr, int *flag_parce_ptr,
               LinesNode **patternhead, LinesNode **filepathead,
               LinesNode *fileshead) {
  // Handling getopt
  int recieved_flag;
  while ((recieved_flag = getopt(argc, argv, "+e:ivclnhsf:o")) != -1) {
    GetFlags(&recieved_flag, flag_ptr, flag_parce_ptr);
    GetPattern(optarg, flag_ptr, patternhead, filepathead, 1, fileshead);
  }
}

void GetFile(LinesNode *filehead, FLAGS *flag_ptr, char *filename,
             int wrong_pattern_flag) {
  // Adding files to the files node
  static int callnum = 0;
  if (strstr(filename, "-e") != 0 || strstr(filename, "-f") != 0) {
    ;
  } else if ((filename[0] == '-') && callnum == 0) {
    ;
  } else if (wrong_pattern_flag) {
    Insert(filehead, 0, callnum, filename, strlen(filename));
    callnum++;
  } else {
    Shift(filehead, callnum, filename, strlen(filename));
    optind++;
    callnum++;
  }
  flag_ptr->many_files_flag = callnum - 1;
}

void AddPatternFromFile(LinesNode **patternhead, LinesNode *filehead,
                        int *file_exist_ptr, FLAGS *flagptr, char *name_prog) {
  // Adding patterns from the files of the node of pattern files to the node of
  // patterns
  FILE *filepointr;
  LinesNode *fileptr = filehead->nextline;
  int cntr = (*patternhead)->num_of_line;
  size_t linesize = MAXLENGTH;
  char *pattern_line = (char *)malloc(linesize * sizeof(char));
  while (fileptr && (*file_exist_ptr) == SUCCEED) {
    filepointr = fopen(fileptr->line, "rb");
    BadFilePath(filepointr, flagptr, fileptr->line, name_prog, file_exist_ptr);
    if (filepointr) {
      while (!feof(filepointr)) {
        getline(&pattern_line, &linesize, filepointr);
        int len = strlen(pattern_line);
        if (len) {
          if (len > 1 && pattern_line[len - 1] == '\n') {
            pattern_line[len - 1] = '\0';
          } else if (pattern_line[0] == '\n') {
            flagptr->empty_pattern = 1;
            strcpy(pattern_line, "$");
          }
          Shift(*patternhead, cntr, pattern_line, len);
          cntr++;
        }
      }
      fclose(filepointr);
      fileptr = fileptr->nextline;
    }
  }
  free(pattern_line);
}

// HANDLING PATTERNS
void FormPatternString(char **patternstring, size_t *linesize,
                       LinesNode *patterns, FLAGS *flagptr) {
  // Makes regular expression from all patterns in the node
  int callnum = 0;
  LinesNode *pattern_ptr = patterns->nextline;
  strcpy(*patternstring, "\0");
  while (pattern_ptr) {
    if (strlen(pattern_ptr->line)) {
      if (strcmp(pattern_ptr->line, ".") == 0) {
        flagptr->point_flag = 1;
      }
      if (callnum > 0) {
        strcat(*patternstring, "|");
      }
      StringLengthSuits(patternstring, linesize, pattern_ptr->line);
      strcat(*patternstring, pattern_ptr->line);
      pattern_ptr = pattern_ptr->nextline;
      callnum++;
    }
  }
}

void FormCflags(const FLAGS *flag_ptr, int *cflags) {
  // FORMS CFlags for regex according to enabled flags
  (*cflags) |= REG_NEWLINE;
  if (flag_ptr->iflag) {
    (*cflags) |= REG_ICASE;
  }
}

int LineIncludesPattern(const char *line_input, const char *patternstring,
                        int cflags, FLAGS *flagptr) {
  // Checks if line_input suits the regular expression patternstring
  int status = 1;
  regex_t reg;
  if (strlen(patternstring)) {
    if (!regcomp(&reg, patternstring, cflags)) {
      status = regexec(&reg, line_input, 0, NULL, 0);
    }
    if (line_input[0] == '\n') {
      if (flagptr->point_flag) {
        status = 1;
      }
    }
    regfree(&reg);
  }
  return status;
}

void OflagEnabled(int cflags, char *line_input, LinesNode **head,
                  LinesNode *patternhead, int strmax, int strmin,
                  int *num_of_string) {
  // Adds words from the line to the linesnode if they suit the pattern
  LinesNode *patterns = patternhead;
  LinesNode *lines = *head;
  regmatch_t index;
  regex_t reg;
  int status = 1;
  size_t length = strmax + 1;
  while (patterns) {
    if (strlen(patterns->line)) {
      if (!regcomp(&reg, patterns->line, cflags)) {
        status = regexec(&reg, line_input, 1, &index, 0);
      }
      int min = index.rm_so;
      int max = index.rm_eo;
      if (!status && min >= strmin && max <= strmax) {
        int substr = 0;
        MakeSubSString(patterns, &substr, cflags, line_input, &index, min, max);
        if (line_input[min] != '\n') {
          AddStrForOflag(min, max, line_input, &length, num_of_string, lines);
        } else {
          line_input += 1;
        }
        if (substr) {
          OflagEnabled(cflags, line_input, &lines, patterns->nextline, max, min,
                       num_of_string);
        }
        line_input = line_input + max;
        strmax -= max;
      } else {
        patterns = patterns->nextline;
      }
      regfree(&reg);
    } else {
      patterns = patterns->nextline;
    }
  }
}

void AddStrForOflag(int min, int max, char *line_input, size_t *length,
                    int *num_of_string, LinesNode *lines) {
  int i = 0;
  char *buffer = (char *)malloc((*length) * sizeof(char));
  max = (line_input[max - 1] == '\n') ? (max - 1) : max;
  for (int j = min; j < max; j++) {
    buffer[i++] = line_input[j];
  }
  buffer[i++] = '\0';
  Shift(lines, *num_of_string, buffer, *length);
  free(buffer);
}

void MakeSubSString(LinesNode *patterns, int *substr, int cflags,
                    char *line_input, regmatch_t *index, int min, int max) {
  regex_t sub_reg;
  LinesNode *subpatterns = patterns;
  int sub_status = 1;
  while (subpatterns) {
    if (strlen(subpatterns->line)) {
      if (!regcomp(&sub_reg, subpatterns->line, cflags)) {
        sub_status = regexec(&sub_reg, line_input, 1, index, 0);
      }
      if (!sub_status && min <= index->rm_so && max >= index->rm_eo) {
        *substr = 1;
      }
      regfree(&sub_reg);
    }
    subpatterns = subpatterns->nextline;
  }
}

void FillLinesNode(FILE *fileptr, LinesNode *head, LinesNode *patterns,
                   FLAGS *flagptr, size_t *linesize, int cflags,
                   char *patternstring, int *num_of_accepted_strings) {
  int linenumber = 1;
  char *line = (char *)malloc((*linesize) * sizeof(char));
  while (!feof(fileptr)) {
    getline(&line, linesize, fileptr);
    size_t len = strlen(line);
    if (len && ((!LineIncludesPattern(line, patternstring, cflags, flagptr) &&
                 !flagptr->vflag) ||
                (LineIncludesPattern(line, patternstring, cflags, flagptr) &&
                 flagptr->vflag))) {
      if (line[len - 1] == '\n') line[len - 1] = '\0';
      if (!flagptr->oflag || (flagptr->oflag && flagptr->vflag) ||
          (flagptr->oflag && flagptr->lflag)) {
        Shift(head, linenumber, line, len);
        (*num_of_accepted_strings)++;
      } else if (flagptr->oflag && !flagptr->vflag && !flagptr->lflag) {
        OflagEnabled(cflags, line, &head, patterns, len, 0, &linenumber);
      }
    }
    linenumber++;
  }
  free(line);
}

// FUNCTIONS FOR OUTPUT
void PrintList(LinesNode *head, char *prefix, const FLAGS *flag_ptr) {
  // Formatted output the node of lines to the console
  LinesNode *p = head->nextline;
  int num_of_prev_line = head->num_of_line;
  while (p) {
    if (flag_ptr->nflag && p->num_of_line != num_of_prev_line) {
      printf("%s%d:%s\n", prefix, p->num_of_line, p->line);
    } else if (p->num_of_line != num_of_prev_line) {
      printf("%s%s\n", prefix, p->line);
    } else {
      printf("%s\n", p->line);
    }
    num_of_prev_line = p->num_of_line;
    p = p->nextline;
  }
}

void Output(LinesNode *head, char *filename, const int numofaccstrings,
            const FLAGS *flag_ptr) {
  // Output according the enabled flags
  size_t linesize = MAXLENGTH;
  char *prefix = (char *)malloc(linesize * sizeof(char));
  strcpy(prefix, "\0");
  if (flag_ptr->many_files_flag > 0 && !flag_ptr->hflag) {
    StringLengthSuits(&prefix, &linesize, filename);
    sprintf(prefix, "%s:", filename);
  }
  if (flag_ptr->cflag && flag_ptr->lflag) {
    if (numofaccstrings > 0) {
      printf("%s%d\n%s\n", prefix, 1, filename);
    } else {
      printf("%s%d\n", prefix, 0);
    }
  } else if (flag_ptr->cflag) {
    printf("%s%d\n", prefix, numofaccstrings);
  } else if (flag_ptr->lflag && numofaccstrings > 0) {
    printf("%s\n", filename);
  } else {
    PrintList(head, prefix, flag_ptr);
  }
  free(prefix);
}

// NODE METHODS
LinesNode *Init(void) {
  LinesNode *head = (LinesNode *)malloc(sizeof(LinesNode));
  head->line = (char *)malloc(1 * sizeof(char));
  head->num_of_line = 0;
  strcpy(head->line, "\0");
  head->nextline = NULL;
  return (head);
}

LinesNode *GetLast(LinesNode *head) {
  LinesNode *p = head;
  if (p != NULL) {
    while (p->nextline) {
      p = p->nextline;
    }
  }
  return p;
}

void Shift(LinesNode *head, const int numline, char *input_line,
           size_t length) {
  LinesNode *last = GetLast(head);
  LinesNode *elem = (LinesNode *)malloc(sizeof(LinesNode));
  elem->num_of_line = numline;
  elem->line = (char *)malloc((length + 1) * sizeof(char));
  strcpy(elem->line, input_line);
  elem->nextline = NULL;
  last->nextline = elem;
}

void Insert(LinesNode *head, unsigned n, int num_of_str, char *input_line,
            size_t length) {
  unsigned i = 0;
  LinesNode *tmp = NULL;
  while (i < n && head->nextline) {
    head = head->nextline;
    i++;
  }
  tmp = (LinesNode *)malloc(sizeof(LinesNode));
  tmp->num_of_line = num_of_str;
  tmp->line = (char *)malloc((length + 1) * sizeof(char));
  strcpy(tmp->line, input_line);
  if (head->nextline) {
    tmp->nextline = head->nextline;
  } else {
    tmp->nextline = NULL;
  }
  head->nextline = tmp;
}

void DeleteList(LinesNode **head) {
  LinesNode *prev = NULL;
  while ((*head)->nextline) {
    prev = (*head);
    (*head) = (*head)->nextline;
    free(prev->line);
    free(prev);
  }
  free((*head)->line);
  free(*head);
}

// SERVICE FUNCTIONS
void StringLengthSuits(char **string, size_t *length, char *input_string) {
  // Reallocs string if it is too short
  if ((*length) - strlen(*string) - strlen(input_string) < 4) {
    *length = (*length) * 2 + strlen(input_string);
    *string = (char *)realloc(*string, ((*length) * sizeof(char)));
  }
}

void BadFilePath(FILE *fileptr, FLAGS *flagptr, char *filename, char *progname,
                 int *file_exist_ptr) {
  // Checks if the file can be opened
  if (fileptr == NULL) {
    if (!(flagptr->sflag)) {
      fprintf(stderr, "%s: %s: No such file or directory\n", progname,
              filename);
    }
    *file_exist_ptr = ERROR;
  }
}
