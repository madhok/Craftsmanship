#include <iostream>


using namespace std;

int fib(int n)
{
int f[2];
if(n == 0)
    return 0;

f[0] = 0;
f[1] = 1;

for(int i = 2; i < n; i++)
{
    f[0] = f[1];
    f[1] = f[0] + f[1];
}

return f[0] + f[1];
}