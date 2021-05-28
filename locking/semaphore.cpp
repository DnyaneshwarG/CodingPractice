/**
 * Semaphore example, written in C++ May 4, 2014
 * Compiled on OSX 10.9, using:
 * g++ -std=c++11 semaphore.cpp
 **/

#include <iostream>      
#include <thread>        
#include <mutex>         
#include <condition_variable>
 
using namespace std;

mutex mtx;             // mutex for critical section
condition_variable cv; // condition variable for critical section  
bool ready = false;         // Tell threads to run
int current = 0;            // current count

/* Prints the thread id / max number of threads */
void print_num(int num, int max) {

  unique_lock<mutex> lck(mtx);
  while(num != current || !ready){ cv.wait(lck); }
  current++;
  cout << "Thread: ";
  cout << num + 1 << " / " << max;
  cout << " current count is: ";
  cout << current << endl;
  
  /* Notify next threads to check if it is their turn */
  cv.notify_all(); 
}

/* Changes ready to true, and begins the threads printing */
void run(){
  unique_lock<mutex> lck(mtx);
  ready = true;
  cv.notify_all();
}
 
int main (){

  int threadnum = 15;
  thread threads[15];

  /* spawn threadnum threads */
  for (int id = 0; id < threadnum; id++)
    threads[id] = thread(print_num, id, threadnum);

  cout << "\nRunning " << threadnum;
  cout << " in parallel: \n" << endl;

  run(); // Allows threads to run

  /* Merge all threads to the main thread */
  for(int id = 0; id < threadnum; id++)
    threads[id].join();

  cout << "\nCompleted semaphore example!\n";
  cout << endl;

  return 0;
}
