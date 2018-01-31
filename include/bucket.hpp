//  BUCKET.HPP

#include <iostream>
#include <vector>

template <typename T, typename RandomAccessIterator>
void bucket_sort(RandomAccessIterator begin, RandomAccessIterator end, int rad) {

    // 1) Создаем корзину
    int size = (end - begin);
    std::vector<T> bucket[size];

    // 2) Распределяем массив в различные корзины
    // (по n разряду) 256 -> [2]56
    for (RandomAccessIterator iter = begin; iter < end; iter++) {
        int bi = (*iter) / rad;
        bucket[bi].push_back(*iter);
    }

    // 3) Отдельно сортируем каждую корзину
    for (int i = 0; i < size; i++)
        std::sort(bucket[i].begin(), bucket[i].end());

    // 4) Сливаем отсортированные части в исходный массив
    // int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            *begin = bucket[i][j];
            begin++;
        }
    }
}
