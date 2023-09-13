#include <stdio.h>

#define SIZE 10

short Input (int *mas);
short Output(int *mas);
void Swap(int *mas, int left, int right);
void QuickSort(int* mas, int left, int  right);
void CopyMas(int *mas, int *mas2);
void SiftDown(int *numbers, int root, int bottom);
void HeapSort(int *numbers, int array_size);

int main(void) {
    int n, mas[SIZE], mas2[SIZE];
    if (Input (mas)) { 
        CopyMas(mas, mas2);
        QuickSort(mas, 0, SIZE-1);
        Output (mas);
        printf("\n");
        HeapSort(mas2, SIZE);
        Output (mas2);
        return 0;
    }
    printf("n/a");
    return 1;
}

void CopyMas(int *mas, int *mas2) {
    for(int i =0; i < SIZE; i++){
        mas2[i] = mas[i];
    }
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

// Функция "просеивания" через кучу - формирование кучи
void SiftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}

// Функция сортировки на куче
void HeapSort(int *numbers, int array_size) {
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2); i >= 0; i--)
    SiftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    SiftDown(numbers, 0, i - 1);
  }
}