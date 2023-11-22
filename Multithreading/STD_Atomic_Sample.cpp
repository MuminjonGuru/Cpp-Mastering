#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> counter(0);

void increment_counter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        ++counter;
    }
}

int main() {
    const int num_threads = 10;
    const int iterations_per_thread = 1000;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(increment_counter, iterations_per_thread));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
