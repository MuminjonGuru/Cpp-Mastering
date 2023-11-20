#include <iostream>
#include <future>
#include <vector>

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    const int num_tasks = 10;

    std::vector<std::future<int>> futures;
    for (int i = 0; i < num_tasks; ++i) {
        futures.push_back(std::async(std::launch::async, factorial, i));
    }

    for (auto& future : futures) {
        std::cout << "Factorial: " << future.get() << std::endl;
    }

    return 0;
}
