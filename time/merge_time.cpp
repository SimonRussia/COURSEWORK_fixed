//  TIME_MERGE.CPP

#include "merge.hpp"
#include "message.hpp"
#include <random>
#include <chrono>

void merge() {
    std::cout << std::endl << "++++++++ TIME TEST MERGE ++++++++" << std::endl;

    long int ARRAY_LEN;
    const int INT_RANGE = 100;

    for (ARRAY_LEN = 1000; ARRAY_LEN < 10000000000; ARRAY_LEN *= 10) {
        std::cout << "Time for " << ARRAY_LEN << " size:\t";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, INT_RANGE);

        int* array = new int[ARRAY_LEN];

        for (int i = 0; i < ARRAY_LEN; i++) {
            array[i] = dis(gen);
        }

        auto start = std::chrono::high_resolution_clock::now();
        merge_sort<int>(array, array + ARRAY_LEN);
        auto finish = std::chrono::high_resolution_clock::now();

        std::cout << (std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()) << " [ns]\n";

        delete[] array;
    }

    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    merge();
    return 0;
}
