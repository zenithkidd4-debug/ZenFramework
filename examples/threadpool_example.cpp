#include <zen/ThreadPool.hpp>

#include <chrono>
#include <iostream>

int main()
{
    zen::ThreadPool pool(4);

    auto task1 = pool.enqueue([]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Task 1 finished\n";
    });

    auto task2 = pool.enqueue([]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Task 2 finished\n";
    });

    auto task3 = pool.enqueue([]()
    {
        std::cout << "Task 3 finished\n";
    });

    task1.get();
    task2.get();
    task3.get();

    std::cout << "All tasks completed!" << std::endl;

    return 0;
}
