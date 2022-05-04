#include "s21_string.h"
#include <limits.h>
#include <stdarg.h>

// 1
// c
// Символ
// Символ
// int CSpecificator(char* dest, char** end_of_string, char c, int flags, int width, int long_flag);
// Если width == -1, то значит спецификатора не было

// 4
// f
// Десятичное число с плавающей точкой
// Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)
// int FlSpecificator(char* dest, char** end_of_string, float number, int flags, int width, int precision);
// int LfSpecificator(char* dest, char** end_of_string, double number, int flags, int width, int precision); просто дабловский

// 5
// s
// Строка символов
// Строка символов
// int SSpecificator(char* dest, char** end_of_string, char* string, int flags, int width, int long_flag);

// 7
// %
// Символ %
// Символ %

#define SUCCEED 0
#define ERROR -1

#define MINUS_FLAG 0b1
#define PLUS_FLAG 0b10
#define SPACE_FLAG 0b100

#define H_LENGH_FLAG 0b1
#define L_LENGH_FLAG 0b10
#define L_CAPS_LENGH_FLAG 0b100

typedef enum SPECIFICATORS {C, F, S, PERCENT, I, U, D} SPECIFICATORS;

int ParseSpecificator(char **string_pointer, const char **format_pointer, int *flags, int *width, int *precision, int *length, SPECIFICATORS *specificator);
int GetFlags(const char **format_pointer, int *flags);
int GetWidth(const char **format_pointer, int *width);
int GetPrecision(const char **format_pointer, int *precision);
int GetLength(const char **format_pointer, int *length);
int GetSpecificatior(const char **format_pointer, SPECIFICATORS *specificator);
int IsFlag(char c);
int IsDigit(char c);
int IsSpecificator(char c);
int IntToString(char **string_pointer, long long int number, int flags, int width, int precision, int radix);
int SpecificatorF(char **string_pointer, double number, int flags, int width, int precision);

int sprintf(char *str, const char *format, ...) {
    int flags = 0, width = 0, precision = 0, length = 0;
    SPECIFICATORS specificator;
    int status = SUCCEED;
    va_list argument_list;
    va_start(argument_list, format);

    while (status == SUCCEED && *format) {
        if (*format != '%') {
            *str = *format++;
            str++;
        } else {
            status = ParseSpecificator(&str, &format, &flags, &width, &precision, &length, &specificator);
            switch (specificator)
            {
            case C:
                break;
            case F:
                break;
            case S:
                break;
            case PERCENT:
                *str = '%';
                str++;
                break;
            case I:
                long long number = (width & H_LENGH_FLAG) ? va_arg(argument_list, short) : (width & L_LENGH_FLAG) ? va_arg(argument_list, long) : va_arg(argument_list, int);
                IntToString(&str, (long long)number, flags, width, precision, 10);
                break;
            case U:
                unsigned long number = (width & H_LENGH_FLAG) ? va_arg(argument_list, unsigned short) : (width & L_LENGH_FLAG) ? va_arg(argument_list, unsigned long) : va_arg(argument_list, unsigned int);
                IntToString(&str, (long long)number, flags, width, precision, 10);
                break;
            case D:
                long long number = (width & H_LENGH_FLAG) ? va_arg(argument_list, short) : (width & L_LENGH_FLAG) ? va_arg(argument_list, long) : va_arg(argument_list, int);
                IntToString(&str, (long long)number, flags, width, precision, 10);
                break;
            default:
                break;
            }
        }
    }
    return status;
}

int ParseSpecificator(char **string_pointer, const char **format_pointer, int *flags, int *width, int *precision, int *length, SPECIFICATORS *specificator) {
    int status = SUCCEED;
    char* string = *string_pointer;
    const char* format = *format_pointer;

    status = GetFlags(format_pointer, flags);
    status = GetWidth(format_pointer, width);
    status = GetPrecision(format_pointer, precision);
    status = GetLength(format_pointer, length);
    status = GetSpecificatior(format_pointer, specificator);
    return status;
}

int GetFlags(const char **format_pointer, int *flags) {
    const char* format = *format_pointer;
    int status = SUCCEED;
    int _flags = 0;
    
    while (status == SUCCEED && IsFlag(*format)) {
        if (*format == '+') {
            if (_flags & PLUS_FLAG) {
                status = ERROR;
            } else {
                _flags |= PLUS_FLAG;
            }
            format++;
        } else if (*format == '-') {
            if (_flags & MINUS_FLAG) {
                status = ERROR;
            } else {
                _flags |= MINUS_FLAG;
            }
            format++;
        } else if (*format == ' ') {
            if (_flags & SPACE_FLAG) {
                status = ERROR;
            } else {
                _flags |= SPACE_FLAG;
            }
            format++;
        } else {
            status = ERROR;
        }
    }
    *flags = status == SUCCEED ? _flags : 0;
    *format_pointer = format;
    return status;
}

int GetWidth(const char **format_pointer, int *width) {
    const char* format = *format_pointer;
    int status = SUCCEED;
    unsigned int _width = 0;

    while (status == SUCCEED && IsDigit(*format)) {
        _width *= 10;
        _width += *format - '0';
        format++;
        if (_width + *format - '0' > INT_MAX) {
            status = ERROR;
        } 
    }
    if (status == SUCCEED) {
        *format_pointer = format;
        *width = (int)_width;
    }
    return status;
}

int GetPrecision(const char **format_pointer, int *precision) {
    const char* format = *format_pointer;
    int status = SUCCEED;
    unsigned int _precision = 0;
    
    if (*format == '.') {
        while (status == SUCCEED && IsDigit(*format)) {
            _precision *= 10;
            _precision += *format - '0';
            format++;
            if (_precision + *format - '0' > INT_MAX) {
                status = ERROR;
            } 
        }
        if (status == SUCCEED) {
            *format_pointer = format;
            *precision = (int)_precision;
        }
    } else {
        precision = 0;
    }
    return status;
}

int GetLength(const char **format_pointer, int *length) {
    const char* format = *format_pointer;
    int _length = 0;
    int status = SUCCEED;

    if (*format == 'h') {
        _length |= H_LENGH_FLAG;
        format++;
    } else if (*format == 'l') {
        _length |= L_LENGH_FLAG;
        format++;
    }

    *length = status == SUCCEED ? _length : *length;
    *format_pointer = format;
}

int GetSpecificatior(const char **format_pointer, SPECIFICATORS *specificator) {
    const char* format = *format_pointer;
    SPECIFICATORS _specificator = 0;
    int status = SUCCEED;

    if (IsSpecificator(*format)) {
        if (*format == 'c') {
            specificator = C;
        } else if (*format == 'f') {
            specificator == F;
        } else if (*format == 's') {
            specificator == S;
        } else if (*format == '%') {
            specificator == PERCENT;
        } else if (*format == 'i') {
            specificator == I;
        } else if (*format == 'u') {
            specificator == U;
        } else if (*format == 'd') {
            specificator == D;
        } else {
            status = ERROR;
        }
        format++;
    } else {
        status = ERROR;
    }
    *specificator = status == SUCCEED ? _specificator : *specificator;
    *format_pointer = format;
}

int IsFlag(char c) {
    return c == '+' || c == '-' || c == ' ';
}

int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int IsSpecificator(char c) {
    return c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' || c == 'u' || c == '%';
}

int IntToString(char **string_pointer, long long int number, int flags, int width, int precision, int radix) {
    precision += precision ? 1 : 0;
    s21_size_t length = GetNumberLength(number, radix) + precision + (number < 0 || flags & PLUS_FLAG || flags & SPACE_FLAG);
    width = (length >= width) ? length : width;
    long long int number_abs = abs(number);
    char* string = *string_pointer;
    s21_memset(string, ' ', width);
    char *end_of_number = flags & MINUS_FLAG ? string + length : string + width;

    for (; end_of_number > string + w)


}