//  TEST_BUCKET.CPP

#include <catch.hpp>
#include "bucket.hpp"
#include <random>
#include <iterator>

TEST_CASE("Testing BUCKET sort") {
    std::cout << "\n********* BUCKET CHECK *********\n" << std::endl;

    const int ARRAY_LEN = 10;
    const int INT_RANGE = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_RANGE);

    int array[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i ++) {
        array[i] = dis(gen);
    }

    // Стандартная сортировка для проверки.
    std::vector<int> v(std::begin(array), std::end(array));
    std::sort(v.begin(), v.end());

    // Сортировка алгоритмом bucket.
    bucket_sort<int>(std::begin(array), std::end(array), INT_RANGE);

    // Сравнение отсортированных массивов.
    for (int i = 0; i < ARRAY_LEN; i++) {
        REQUIRE(array[i] == v[i]);
    }
}
