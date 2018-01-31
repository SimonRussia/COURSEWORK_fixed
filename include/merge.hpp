//  MERGE.HPP

#include <iostream>
#include <vector>

template <typename T, typename RandomAccessIterator>
void merge(RandomAccessIterator left, RandomAccessIterator medium, RandomAccessIterator right) {
    RandomAccessIterator iter = left;
    long int i, j;
    long int leftSize = medium - left + 1;
    long int rightSize =  right - medium;

    // Создаем временные массивы Left и Right.
    T* L = new T[leftSize];
    T* R = new T[rightSize];

    // Копируем значения в массивы L[] и R[].
    for (i = 0; i < leftSize; i++) {
        L[i] = *iter;
        iter++;
    }

    for (j = 0; j < rightSize; j++) {
        R[j] = *iter;
        iter++;
    }

    // Слияние L[] и R[] в сортируемый массив.
    i = 0;  // Индекс для левого массива.
    j = 0;  // Индекс для правого массива.
    iter = left;  // Индекс для слияния левого и правого массивов.

    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            *iter = L[i];
            i++;
        } else {
            *iter = R[j];
            j++;
        }
        iter++;
    }

    // Проверяем L[] на оставшиеся элементы,
    // если они есть, копируем в сортируемый масив.
    while (i < leftSize) {
        *iter = L[i];
        i++;
        iter++;
    }

    // Проверяем R[] на оставшиеся элементы,
    // если они есть, копируем в сортируемый масив.
    while (j < rightSize) {
        *iter = R[j];
        j++;
        iter++;
    }

    delete[] L;
    delete[] R;
}

template <typename T, typename RandomAccessIterator>
void merge_sort(RandomAccessIterator left, RandomAccessIterator right) {
    static bool enter = true;
    
    //  Сдвигаем указатель на последний элемент
    //  сортируемого массива.
    if (enter) {
      --right;
      enter = false;
    }

    if (left < right) {
        // Получем середину сортируемого массива.
        RandomAccessIterator medium = left + (right - left)/2;

        // Сортируем левую и правую части массива,
        // путем рекурсивного вызова merge_sort.
        merge_sort<T>(left, medium);
        merge_sort<T>(medium + 1, right);
        
        merge<T>(left, medium, right);
    }
}
