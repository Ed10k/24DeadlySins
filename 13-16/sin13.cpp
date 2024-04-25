// Race condition
// I use a mutex to lock a global count variable so when the two theads complete then it will have the correct value at the end of the program

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex counterMutex;

void incrementCounter(int id) {
    counterMutex.lock();
    for (int i = 0; i < 1000; ++i) {
        counter++; // Incrementing the shared variable with proper synchronization
    }
    cout << "Thread " << id << " finished.\n";
    counterMutex.unlock();
}

int main() {
    thread t1(incrementCounter, 1);
    thread t2(incrementCounter, 2);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << std::endl;

    return 0;
}
