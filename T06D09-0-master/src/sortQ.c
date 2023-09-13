void QuickSort(int* mas, int left, int  right) {
    int pivot = mas[left];
    int l_check = left;
    int r_check = right;

    while(l_check < r_check) {
        while(mas[r_check] > pivot && r_check != l_check) { r_check--; }
        if (r_check > l_check) {
            //
            mas[l_check] = mas[r_check];
            l_check++;
        }
        while(mas[l_check] < pivot && r_check != l_check) { l_check++; }
        if (r_check > l_check) {
            mas[r_check] = mas[l_check]
            r_check--;
        }
    }
    mas[l_check] = pivot;
    if (left < l_check) { QuickSort(mas, left, l_check); }
    if (right < l_check) {  QuickSort(mas, l_check, right); }
}

/*void QuickSort(int* mas, int left, int  right) {
    int pivot = mas[left];
    int l_check = left;
    int r_check = right;

    while (l_check < r_check) {
        //движение справа
        while(mas[r_check] > pivot && l_check <= r_check) { r_check--; }
        //движение слева
        while(mas[l_check] < pivot && l_check <= r_check) { l_check++; }
        if (l_check < r_check) {
            Swap(mas, l_check, r_check);
            r_check--;
            l_check++;
        }
    }
    
    r_check++;
    l_check--;
    
    if (left < l_check) { QuickSort(mas, left, l_check); }
    if (right > r_check) { QuickSort(mas, r_check, right); }
}
*/