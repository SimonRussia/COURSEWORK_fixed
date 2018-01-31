//  SELECTION.HPP

#include <iostream>
#include <vector>

template <typename RandomAccessIterator>
void selection_sort(RandomAccessIterator left, RandomAccessIterator right) {
    for (RandomAccessIterator iter1 = left; iter1 != (right - 1); iter1++) {
        RandomAccessIterator min = iter1;
        for (RandomAccessIterator iter2 = (iter1 + 1); iter2 != right; iter2++) {
            if (*min > *iter2) {
                min = iter2;
            }
        }
        std::swap(*min, *iter1); //  В случае 1 2 3 |4| 5 меняем 4 саму с собой
    }
}
