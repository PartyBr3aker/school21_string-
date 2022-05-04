#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *start_point;  // start of the next search
    char *result = NULL;
    if (!str) {
        str = start_point;
    }
    if (str) {  // clearing the beginning of a string
        int all_deligms = 0;
        while (1) {
            if (is_delim(*str, delim)) {
                str++;
                continue;
            }
            if (*str == '\0') {
                all_deligms = 1;
                // we've reached the end of the string
                // and no regular character was there
            }
            break;
        }
        if (!all_deligms) {  // if the string still contains smth
            result = str;
            int flag = 1;
            while (flag == 1) {
                if (*str == '\0') {
                    start_point = str;
                    flag = 0;  // next execution will return NULL
                }
                if (is_delim(*str, delim)) {
                    *str = '\0';
                    start_point = str + 1;
                    flag = 0;
                }
                str++;
            }
        }
    }
    return result;
}

int is_delim(char c, const char *delim) {
    int flag = 0;
    while (*delim != '\0') {
        if (c == *delim) {
            flag = 1;
        }
        delim++;
    }
    return flag;
}
