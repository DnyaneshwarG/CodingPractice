#include <iostream>
#include <pthread.h>

using namespace std;

struct arg_struct {
   int arg1;
   int arg2;
};

void *print_the_arguments(void *arguments)
{
   struct arg_struct *args = (struct arg_struct *)arguments;
   cout<< args -> arg1<<endl;
   cout<< args -> arg2<<endl;
   pthread_exit(NULL);
   return NULL;
}

int main()
{
   pthread_t some_thread;
   struct arg_struct args;
   args.arg1 = 5;
   args.arg2 = 7;
   if (pthread_create(&some_thread, NULL, &print_the_arguments, (void *)&args) != 0) {
       printf("Uh-oh!\n");
       return -1;
   }
   return pthread_join(some_thread, NULL);
}
