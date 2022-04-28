#include "main.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++){}
    return len;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    for (long unsigned i = 0; i < n; i++) {
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return dest;
}

char *s21_strchr(const char *str, int c) {
    // инициализировать как s21null или можно просто нулем?
    const char *res = s21_NULL;
    for (s21_size_t len = 0; len < s21_strlen(str); len++) {
        if (str[len] == c) {res = &str[len];
        break;
        }
    }
    return (char*)res;
}


s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    // делаем ли проверку на нулевые строки подаваемые в функцию?
    // if((str1 == NULL) || (str2 == NULL))
    //     return len;
    while (*str1) {
        //  проверяем, входит ли символ str1 в перечень символов str2
        if (s21_strchr(str2, *str1)) {break;
        } else {
            str1++;
            len++;
        }
    }
    return len;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    // делаем ли проверку на нулевые строки подаваемые в функцию?
    // if((str1 == NULL) || (str2 == NULL))
    // return len;

    while (*str1) {
        //  проверяем, входит ли символ str1 в перечень символов str2
        if (!s21_strchr(str2, *str1)) {break;
        } else {
            str1++;
            len++;
        }
    }
    return len;
}

// int main() {
//     char *test_data1 = "Hello world!";
//     char test_data2[100]="";
//     char test_data3[100]="";
//     char *test_data4 = "wo";
//     char *test_data5 = "Hleo";
//     printf("%ld\n",s21_strlen(test_data4));
//     printf("%ld\n",strlen(test_data4));

//     s21_memcpy(test_data2, test_data1, s21_strlen(test_data1));
//     memcpy(test_data3, test_data1, s21_strlen(test_data1));
//     if (strcmp(test_data2, test_data3) == 0) {printf("memcpy test OK!\n");}
//     if (s21_strchr(test_data1, 'o') == strchr(test_data1, 'o')) {printf("strchr test OK!\n");}
//     if (s21_strchr(test_data1, 'z') == strchr(test_data1, 'z')) {printf("strchr test OK!\n");}
//     if (s21_strcspn(test_data1, test_data4) == 
//     strcspn(test_data1, test_data4)) {printf("strcspn test OK!\n");}
//     if (s21_strspn(test_data1, test_data5) == strspn(test_data1, test_data5)) {printf("strspn test OK!\n");}
//     return 0;
// }
