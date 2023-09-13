#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int Sum(int *mas_b, int *mas_m, int nB, int nM, int *rez);
short Input(int *mas, int *n);
void Output (int *buffer, int length, int check);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main()
{
    int mas1[LEN], n1;
    int mas2[LEN], n2;
    int rez[LEN+1], nR;
    if (Input(mas1, &n1) && Input(mas2, &n2)) {
      if (n1 >= n2) {
        nR = Sum(mas1, mas2, n1, n2, rez);
        Output(rez, nR, n1);
      }
      else {
        nR = Sum(mas2, mas1, n2, n1, rez);
        Output(rez, nR, n2);
      }
    }
    printf("n/a");
    return 1;
}

short Input(int *mas, int *n) {
  char buf;
  int index = 0;
  while (1) {
    if (scanf("%d%c", &mas[index], &buf) == 2 && index < 100 && (buf == ' ' || buf == '\n') && mas[index] < 10 && mas[index] > -1) {
      index++;
      if (buf == '\n') { 
        *n = index++;
        return 1;
      }
    }
    else {
      return 0;
    }
  }
}

int Sum(int *mas_b, int *mas_m, int nB, int nM, int *rez) {
  nM--;
  rez[nB] = 0;
  int check = 1;
  printf("%d\n", nB);
  for(int i = nB-1; i >= 0; i--) {

    if(nM >= 0) {
      rez[i+1] += mas_b[i] + mas_m[nM];
      rez[i] = 0;
      if (rez[i+1] > 10) {
        printf("sssssss");
        rez[i] = 1;
        rez[i+1] = rez[i+1] % 10;
        if (i = 0) { check = 0; }
      }
      nM--;
      printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
      continue;
    }
    if (nM == -1) {
      rez[i+1] += mas_b[i];
      nM--;
      printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
      continue;
    }
    rez[i+1] = mas_b[i];
    printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
  }
  return check == 1 ? nB : nB + 1;
}

int Sub(int *mas_b, int *mas_m, int nB, int nM, int *rez) {
  nM--;
  rez[nB] = 0;
  int check = 1;
  printf("%d\n", nB);
  for(int i = nB-1; i >= 0; i--) {

    if(nM >= 0) {
      rez[i+1] += mas_b[i] + mas_m[nM];
      rez[i] = 0;
      if (rez[i+1] > 10) {
        printf("sssssss");
        rez[i] = 1;
        rez[i+1] = rez[i+1] % 10;
        if (i = 0) { check = 0; }
      }
      nM--;
      printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
      continue;
    }
    if (nM == -1) {
      rez[i+1] += mas_b[i];
      nM--;
      printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
      continue;
    }
    rez[i+1] = mas_b[i];
    printf("%d-%d +%d+%d\n", i, rez[i+1],mas_b[i],mas_b[i]);
  }
  return check == 1 ? nB : nB + 1;
}

void Output (int *buffer, int length, int check) {
  int start = 1;
  if (check > length) {
    start = 0;
  }
  int count = 0;
	for(int i = start; i < length; i++) {
    if (count == 0 && buffer[i] != 0) {
      printf("%d ", buffer[i]);
      count = 1;
    }
    else {
      printf("%d ", buffer[i]);
    }
	}
	printf("%d", buffer[length]);
}

