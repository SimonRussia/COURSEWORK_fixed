//  EXAMPLE_MERGE.CPP

#include "merge.hpp"
#include "message.hpp"
#include <random>
#include <iterator>

void merge() {
    const int ARRAY_LEN = 10;
    const int INT_RANGE = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_RANGE);

    int array[ARRAY_LEN];
    std::vector<int> v;

    for (int i = 0; i < ARRAY_LEN; i++) {
        array[i] = dis(gen);
        v.push_back(dis(gen));
    }

    message(std::begin(array), std::end(array));
    merge_sort<int>(std::begin(array), std::end(array));
    message(std::begin(array), std::end(array));

    std::cout << std::endl;

    message(v.begin(), v.end());
    merge_sort<int>(v.begin(), v.end());
    message(v.begin(), v.end());
}

int main(int argc, char const *argv[]) {
    merge();
    return 0;
}
