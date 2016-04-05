// Example program
/*
Write a multiply function that multiples 2 integers without using *
*/
#include <iostream>
#include <string>

using namespace std;

double multiply(int x, int y) {
	if(x == 0 || y == 0) {
		return 0;
	}
	bool neg = false;
	if(x < 0 && y < 0) neg = false;
	else if(x <0 && y >0) neg = true;
	if(x>0  && y < 0) neg = true;

	x= abs(x);
	y = abs(y);
	int min = x>y?y:x;
	int max = x>y?x:y;
	double temp = max;
	double result =0.0;

	for(int i = min; i >0; i = i/2) {
		if(i%2==1) {
			result = result + temp;
		}
		temp = temp + temp;
	} 
	if(neg) result = 0.0-result;
	return result;
}

int main()
{
    cout << multiply(-6,-5) << endl;
    cout << multiply(3,-5) << endl;
	cout << multiply(-1,2) << endl;
	cout << multiply(-1,0) << endl;
}
