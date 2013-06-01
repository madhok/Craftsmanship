#include <iostream>
#include <thread>

using namespace std;

int function()
{
	cout << "Runing thread" << endl;
}

int main()
{
	std::thread t(function);
	t.join();
	return 0;
}