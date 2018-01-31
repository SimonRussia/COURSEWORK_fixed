//  RADIX.HPP

#include <iostream>
#include <vector>

template <typename T, typename RandomAccessIterator>
int getMaxValue(RandomAccessIterator left, RandomAccessIterator right){
    T max = *left;
    for (RandomAccessIterator iter = left + 1; iter != right; iter++) {
        if (*iter > max) {
            max = *iter;
        }
    }

    return max;
}


template <typename T, typename RandomAccessIterator>
void count_sort(RandomAccessIterator left, RandomAccessIterator right, int exp) {
    long int i;
    // Создаем временный пустой массив и заполняем его 0.
    long int size = (right - left);
    T* temp = new T[size] {0};
    
    // Создаем массив для подсчета количества элементов
    // заполняем его 0.
    int count[10] = {0};
 
    // Подсчитываем количество повторений каждого
    // символа в сортируемом массиве
    // и вносим в массив count.
    for (RandomAccessIterator iter = left; iter != right; iter++)
        // явное привидение типа int, необходимо
        // для сортировки массивов типа double и float.
        count[ int((*iter)/exp) % 10 ]++;

    // Проходим по массиву count и складываем значения
    // текущей ячейки со значением в предыдущей.
    // Для получения актуального положения элемента.
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Заполняе временный массив temp сопоставляя
    // значения сортируемого массива с индексом
    // в массиве count.
    for (RandomAccessIterator iter = right - 1; iter >= left; iter--) {
        temp[count[ int((*iter)/exp) % 10 ] - 1] = *iter;
        count[ int((*iter)/exp) % 10 ]--;
    }

    // Копируем значения из массива temp
    // в сортируемый массив.
    for (i = 0; i < size; i++) {
        *left = temp[i];
        left++;
    }

    delete[] temp;
}


template <typename T, typename RandomAccessIterator>
void radix_sort(RandomAccessIterator left, RandomAccessIterator right) {
    // Находим максимальное значение,
    // чтобы определить номер порядка.
    T max = getMaxValue<T>(left, right);

    // Применяем алгоритм сортировки вставками.
    // Для получения разряда используем экспоненту.
    // exp = 10^i, где i - номер порядка.
    for (int exp = 1; max/exp > 0; exp *= 10)
        count_sort<T>(left, right, exp);
}
