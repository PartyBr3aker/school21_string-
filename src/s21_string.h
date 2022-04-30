#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define S21_NULL 0
typedef long unsigned s21_size_t;

// 1. Searches for the first occurrence of the character c (an unsigned char) 
// in the first n bytes of the string pointed to, by the argument str.
void *s21_memchr(const void *str, int c, s21_size_t n);

// 2. Compares the first n bytes of str1 and str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

//3. Copies n characters from src to dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

// 4. Another function to copy n characters from str2 to str1.
void *s21_memmove(void *dest, const void *src, s21_size_t n);

// 5. Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
void *s21_memset(void *str, int c, s21_size_t n);

// 6. Appends the string pointed to, by src to the end of the string pointed to by dest.
char *s21_strcat(char *dest, const char *src);

// 7. Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// 8. Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
char *s21_strchr(const char *str, int c);

// 9. Compares the string pointed to, by str1 to the string pointed to by str2.
int s21_strcmp(const char *str1, const char *str2);

// 10. Compares at most the first n bytes of str1 and str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// 11. Copies the string pointed to, by src to dest.
char *s21_strcpy(char *dest, const char *src);

// 12. Copies up to n characters from the string pointed to, by src to dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// 13. Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
s21_size_t s21_strcspn(const char *str1, const char *str2);

// 14. Searches an internal array for the error number errnum and returns 
// a pointer to an error message string. You need to declare macros containing 
// arrays of error messages for mac and linux operating systems. 
// Error descriptions are available in the original library. 
// Checking the current OS is carried out using directives.
char *s21_strerror(int errnum);

// 15. Computes the length of the string str up to but not including the terminating null character.
s21_size_t s21_strlen(const char *str);

// 16. Finds the first character in the string str1 that matches any character specified in str2.
char *s21_strpbrk(const char *str1, const char *str2);

// 17. Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
char *s21_strrchr(const char *str, int c);

// 18. Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
s21_size_t s21_strspn(const char *str1, const char *str2);

// 19. Finds the first occurrence of the entire string needle
//(not including the terminating null character) which appears in the string haystack.
char *s21_strstr(const char *haystack, const char *needle);

// 20. Breaks string str into a series of tokens separated by delim.
char *s21_strtok(char *str, const char *delim);

#ifdef __APPLE__ 
char* _errors[107] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"
};
#endif // __APPLE__

char unknown_error[150] = "Unknown error:    ";
#endif // SRC_S21_STRING_H_