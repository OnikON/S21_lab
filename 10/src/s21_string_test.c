#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();

int main(void) {
    //s21_strlen_test();
    //s21_strcmp_test();
    //s21_strcpy_test();
    //s21_strcat_test();
    s21_strchr_test();
}

void s21_strlen_test() {
    char *test1 = "12345";
    char *test2 = "1";
    char *test3 = "";
    
    printf("%s len=%d\n", test1, s21_strlen(test1));
    if (s21_strlen(test1) == 5) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    printf("%s len=%d\n", test2, s21_strlen(test2));
    if (s21_strlen(test2) == 1) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    printf("%s len=%d\n", test3, s21_strlen(test3));
    if (s21_strlen(test3) == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    char *test1 = "123";
    char *test2 = "12345";
    printf("strcmp(%s, %s) = %d\n", test1, test1, s21_strcmp(test1, test1));
    if (s21_strcmp(test1, test1) == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    printf("strcmp(%s, %s) = %d\n", test1, test2, s21_strcmp(test1, test2));
    if (s21_strcmp(test1, test2) == -1) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    printf("strcmp(%s, %s) = %d\n", test2, test1, s21_strcmp(test2, test1));
    if (s21_strcmp(test2, test1) == 1) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char *test1 = "123";
    char *test2 = "abc";
    char *test3 = "456";

    char *str = malloc(sizeof(char));

    str = s21_strcpy(str, test1);
    printf("strcpy('', %s) = %s|\n",test1, str);
    if (s21_strcmp(str, test1) == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
    
    str = s21_strcpy(str, test2);
    printf("strcpy(%s, %s) = %s|\n",test1, test2, str);
    if (s21_strcmp(str, test2) == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    str = s21_strcpy(str, test3);
    printf("strcpy(%s, %s) = %s|\n",test2, test3, str);
    if (s21_strcmp(str, test3) == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char *test1 = "Hi";
    char *test2 = " ";
    char *test3 = "Man";

    char *str = malloc(sizeof(char));

    str = s21_strcat(str, test1);
    printf("strcat('', %s) = %s|\n",test1, str);
    if (s21_strcmp(str, "Hi") == 0) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    str = s21_strcat(str, test2);
    printf("strcat(%s, '%s') = %s|\n", test1, test2, str);
    if (s21_strcmp(str, "Hi ") == 0) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
    
    str = s21_strcat(str, test3);
    printf("strcat('Hi ', '%s') = %s|\n", test3, str);
    if (s21_strcmp(str, "Hi Man") == 0) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
    free(str);
}

void s21_strchr_test() {
    char *test1 = "1234567";
    char *test2 = "9999999";
    char *test3 = "abcdefg";

    char a = '5';
    printf("strchr(%s, %c) - test1 = %ld|\n",test1, a, s21_strchr(test1, 48 + 5) - test1);
    if (*s21_strchr(test1, 48 + 5) == *(test1 + 4)) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    char b = '9';
    printf("strchr(%s, %c) - test2 = %ld|\n",test2, b, s21_strchr(test2, 48 + 9) - test2);
    if (*s21_strchr(test2, 48 + 9) == *(test2 + 0)) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    char c = 'g';
    printf("strchr(%s, %c) - test3 = %ld|\n",test3, c, s21_strchr(test3, 103) - test3);
    if (*s21_strchr(test3, 103) == *(test3 + 6)) {
         printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
}