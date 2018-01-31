//  MESSAGE.HPP

#include <iostream>

template <typename BidirectionalIterator>
void message(BidirectionalIterator left, BidirectionalIterator right) {
    for (BidirectionalIterator iter = left; iter != right; iter++) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
}
