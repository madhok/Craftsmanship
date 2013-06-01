#include <iostream>
#include <pthread.h>

using namespace std;

int a = 1;

void* function1(void *msg)
{
  
  a++;
  cout << a << endl;
  cout << "hello";

}
void* function2(void *msg)
{
  a++;
  cout << a << endl;
  cout << "world";
  string* s = (string*)msg;
  cout << *s;
}

int main()
{
  pthread_t t1, t2;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
  pthread_mutex_lock(&mutex);
  string msg1 = "in Function 1";
  int result = pthread_create(&t1, NULL, &function1, static_cast<void *>(&msg1));
  if(result != 0)
  {
    cout << "Error" << endl;
    cout << "Error code = " << result << endl;
  }
  pthread_mutex_unlock(&mutex);
  pthread_mutex_lock(&mutex);
  string msg2 = "in Function 2";
  result = pthread_create(&t2, NULL, &function2, static_cast<void *>(&msg2));
  if(result != 0)
  {
    cout << "2- Error" << endl;
    cout << "Error code = " << result << endl;
  }
  pthread_mutex_unlock(&mutex);
  //sleep(1); //Important for the functions 1 nad 2 to complete.
  cout << a << endl;
  return 0;
}



/*
a = data;
a++;
data = a;

p_thread_mutex_unlock(&mut) */