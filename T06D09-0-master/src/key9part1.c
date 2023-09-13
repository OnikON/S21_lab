/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

short input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
    int n,mas[NMAX];
	if (input(mas, &n)) {
		int sum = sum_numbers(mas, n);
		if (sum == 0) {
			printf("n/a");
			return 1;
		}
		int mas_out[NMAX];
		//int c = find_numbers(mas, n, sum, mas_out);
		output(mas_out, find_numbers(mas, n, sum, mas_out));
		return 0;
	}
	printf("n/a");
	return 1;
}

short input (int *buffer, int *length) {
    char buf;
    if (scanf("%d%c", length, &buf) !=2 || buf != '\n' || (*length < 0) || (*length > NMAX)) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d%c", p, &buf) !=2 || (buf != '\n' && buf != ' ' && buf != EOF)) {
        return 0;
        }
    }
    return 1;
}
void output (int *buffer, int length) {
	for(int i = 0; i < length-1; i++) {
		printf("%d ", buffer[i]);
	}
	printf("%d", buffer[length-1]);
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
//               массив           длина   сумма подсч  выходной масив
int find_numbers(int* buffer, int length, int number, int* numbers) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (buffer[i] != 0 && (number % buffer[i]) == 0) {
			numbers[count] = buffer[i];
			count++;
		}
	}
	return count;
}
