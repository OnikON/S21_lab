#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_strlen(char *string) {
  int count = 0;
  while (*string++) count++;
  return count;
}

int s21_strcmp(char *str1, char *str2) {
    int size_1 = s21_strlen(str1);
    int size_2 = s21_strlen(str2);

    if (size_1 == size_2) {
        for (int i = 0; i < size_1; i++) {
            if (str1[i] != str2[i]) {
                if (str1[i] > str2[i]) {
                    return 1;
                }
                return -1;
            }
        }
        return 0;
    }

    if (size_1 > size_2) {
        return 1;
    }
    if (size_2 > size_1) {
        return -1;
    }
    return 0;
}

char *s21_strcpy(char *str1, char *str2) {
    int len2 = s21_strlen(str2);
    str1 = (char *)realloc(str1, len2);
    for (int i = 0; i < len2; i++) {
        str1[i] = str2[i];
    }
    return str1;
}

char *s21_strcat(char *str1, char *str2) {
    int size_1 = s21_strlen(str1);
    int size_2 = s21_strlen(str2);

    str1 = (char *)realloc(str1, size_1 + size_2);
    for(int i = size_1; i < size_1 + size_2; i++) {
        str1[i] = str2[i - size_1];
    }
    return str1;
}

char *s21_strchr(char *str1, int ch) {
    char *point = NULL;
    for(int i = 0; i < s21_strlen(str1); i++) {
        if (str1[i] == ch) {
            point = (str1 + i);
            break;
        }
    }
    return point;
}