#include <stdio.h>

#define SIZE 10

short Input (int *mas);
short Output(int *mas);
void Swap(int *mas, int left, int right);
void QuickSort(int* mas, int left, int  right);

int main(void) {
    int n, mas[SIZE];
    if (Input (mas)) { 
        QuickSort(mas, 0, SIZE-1);
        Output (mas);
        return 0;
    }
    printf("n/a");
    return 1;
}

short Input(int *mas) {
    int n = SIZE;
    char buf;
    for (int *p = mas; p - mas < n; p++) {
        if (scanf("%d%c", p, &buf) !=2 || (buf != '\n' && buf != ' ' && buf != EOF)) {
        return 0;
        }
    }
    return 1;
}

short Output(int *mas) {
    int n = SIZE;
    char buf;
    for (int *p = mas; p - mas < n-1; p++) {
        printf("%d ", *p);
    }
    printf("%d", mas[n-1]);
    return 1;
}

void Swap(int *mas, int left, int right) {
    int value;
    value = mas[left];
    mas[left] = mas[right];
    mas[right] = value;
}

void QuickSort(int* mas, int left, int  right) {
    int pivot = mas[left];
    int l_check = left;
    int r_check = right;

    while(l_check < r_check) {
        //идем с права-конец на лево-начало
        while(mas[r_check] >= pivot && l_check < r_check) { r_check--; }
        if (r_check != l_check) {
            mas[l_check] = mas[r_check];
            l_check++;
        }
        //идём с лева-начало на право-конец
        while(mas[l_check] <= pivot && l_check < r_check) { l_check++; }
        if (r_check != l_check) {
            mas[r_check] = mas[l_check];
            r_check--;
        }
    }
    //l_check = r_check
    mas[l_check] = pivot;
    if (left < l_check) { QuickSort(mas, left, l_check-1); }
    if (right > l_check) {  QuickSort(mas, l_check+1, right); }
}
