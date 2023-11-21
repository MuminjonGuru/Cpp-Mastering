#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker_thread() {
    // Wait until main() sends data
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, []{return ready;});

    std::cout << "Worker thread is processing data\n";
    // Send data back to main()
}

void main_thread() {
    std::cout << "Main thread is preparing data\n";
    // Simulate data preparation
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lck(mtx);
        ready = true;
    }
    cv.notify_all();
}

int main() {
    std::thread worker(worker_thread);
    std::thread main(main_thread);

    worker.join();
    main.join();

    return 0;
}
