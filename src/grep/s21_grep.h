#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUCCEED 0
#define ERROR -1
#define MAXLENGTH 4096

typedef struct FLAGS {
  int eflag, iflag, vflag, cflag, lflag, nflag, hflag, sflag, fflag, oflag,
      empty_pattern, many_files_flag, point_flag;
} FLAGS;

typedef struct LinesNode {
  char *line;
  int num_of_line;
  struct LinesNode *nextline;
} LinesNode;

// INPUT
void GetFlags(int *recieved_flag_ptr, FLAGS *flag_ptr, int *flags_parsed_ptr);
void GetPattern(char *input, FLAGS *flag_ptr, LinesNode **patternhead,
                LinesNode **filepathead, const int while_call,
                LinesNode *fileshead);
void DeleteExtraPattern(LinesNode **patternhead, int case_3, int callnum,
                        LinesNode *fileshead, FLAGS *flag_ptr);
void GetOption(int argc, char **argv, FLAGS *flag_ptr, int *flag_parce_ptr,
               LinesNode **patternhead, LinesNode **filepathead,
               LinesNode *fileshead);
void GetFile(LinesNode *filehead, FLAGS *flag_ptr, char *filename,
             int wrong_pattern_flag);
void AddPatternFromFile(LinesNode **patternhead, LinesNode *filehead,
                        int *file_exist_ptr, FLAGS *flagptr, char *name_prog);
// PATTERNS
void FormPatternString(char **patternstring, size_t *linesize,
                       LinesNode *patterns, FLAGS *flagptr);
void FormCflags(const FLAGS *flag_ptr, int *cflags);
int LineIncludesPattern(const char *line_input, const char *patternstring,
                        int cflags, FLAGS *flagptr);
void OflagEnabled(int cflags, char *line_input, LinesNode **head,
                  LinesNode *patternhead, int strmax, int strmin,
                  int *num_of_string);
void AddStrForOflag(int min, int max, char *line_input, size_t *length,
                    int *num_of_string, LinesNode *lines);
void MakeSubSString(LinesNode *patterns, int *substr, int cflags,
                    char *line_input, regmatch_t *index, int min, int max);
void FillLinesNode(FILE *fileptr, LinesNode *head, LinesNode *patterns,
                   FLAGS *flagptr, size_t *linesize, int cflags,
                   char *patternstring, int *num_of_accepted_strings);
// OUTPUT
void PrintList(LinesNode *head, char *prefix, const FLAGS *flag_ptr);
void Output(LinesNode *head, char *filename, const int numofaccstrings,
            const FLAGS *flag_ptr);
// NODE METHODS
LinesNode *Init(void);
LinesNode *GetLast(LinesNode *head);
void Shift(LinesNode *head, const int numline, char *input_line, size_t length);
void Insert(LinesNode *head, unsigned n, int num_of_str, char *input_line,
            size_t length);
void DeleteList(LinesNode **head);
// SERVICE
void StringLengthSuits(char **string, size_t *length, char *input_string);
void BadFilePath(FILE *fileptr, FLAGS *flagptr, char *filename, char *progname,
                 int *file_exist_ptr);
#endif  // SRC_GREP_S21_GREP_H_