#include <iostream>
#include "Sort.h"

int main() {
    std::cout << "Welcome to my Sort Algorithm!" << std::endl;

    int array[10] = {0,5,4,6,1,3,2,7,9,8};
    int length = sizeof(array)/ sizeof(int);

    Sort::CountingSort(array, length);

    for (auto item : array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}