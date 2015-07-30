#include <iostream>

using namespace std;

float sqrt(unsigned int x) {
	float high = x;
	float low = 0;
	float lc = 0.0001;
	float mid =0;
	while((high-low) > lc) {
		mid = low +(high -low)/2 ;
		if(mid*mid == x) {
			return mid;
		} else if(mid *mid < x) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return mid;

}

int main() {
	cout << sqrt(15);
}
