
#include <iostream>
#include <thread>

using namespace std;

int x = 0;
int y = 0;

void thread1()
{
  x = 1;
  if (y == 0)
    cout << "1" << endl;
}

void thread2()
{
  y = 1;
  if (x == 0)
     cout << "2" << endl;
}

int main() {

  thread t1(thread1);
  thread t2(thread2);

  t1.join();
  t2.join();

  cout << "\n" << endl;
  return 0;
}
