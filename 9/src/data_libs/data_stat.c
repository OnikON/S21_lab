#include <stdio.h>
#include <stdlib.h>

#include "data_stat.h"

double MaxSearch(double *data, int n) {
    double MaxValue = data[0];
    for(int i = 1; i < n; i++) {
        if (data[i] > MaxValue) { MaxValue = data[i]; }
    }
    return MaxValue;
}
double MinSearch(double *data, int n) {
    double MinValue = data[0];
    for(int i = 1; i < n; i++) {
        if (data[i] < MinValue) { MinValue = data[i]; }
    }
    return MinValue;
}
double mean(double *data, int n) {
    double sum = 0;
    for(int i = 1; i < n; i++) {
        sum += data[i];
    }
    return (double)sum / (double)n;
}
double variance(double *data, int n) {
    double M = mean(data, n);
    double sum = 0;
    for(int i = 1; i < n; i++) {
        sum += data[i] * data[i];
    }
    return ((double)sum / (double)n)-(M*M);
}
void sort(double *data, int n) {
    QuickSort(data, 0, n - 1);
}

void QuickSort(double* mas, int left, int  right) {
    double pivot = mas[left];
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
