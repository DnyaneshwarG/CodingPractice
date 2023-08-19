#include <iostream> 
#include <thread>  
#include <mutex>  

using namespace std;

mutex mtx;

void print_block (int n, string s) {
  mtx.lock();
  for (int i=0; i<n; ++i) { cout << "\n" << s << endl; }
  mtx.unlock();
}

int main ()
{
  thread th1 (print_block,50,"thread1");
  thread th2 (print_block,50,"thread2");

  th1.join();
  th2.join();

  return 0;
}
