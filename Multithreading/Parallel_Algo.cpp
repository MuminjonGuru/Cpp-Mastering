#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // lambda function to each element in the vector
    std::for_each(std::execution::par, v.begin(), v.end(), [](int& n) {
        n *= 2;
    });

    // show modified vector
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
