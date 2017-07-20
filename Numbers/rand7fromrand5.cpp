/*
We know foo() returns integers from 1 to 5. How we can ensure that integers from 1 to 7 occur with equal probability?
If we somehow generate integers from 1 to a-multiple-of-7 (like 7, 14, 21, …) with equal probability, we can use modulo division by 7 followed by adding 1 to get the numbers from 1 to 7 with equal probability.

We can generate from 1 to 21 with equal probability using the following expression.

 5*foo() + foo() -5 
Let us see how above expression can be used.
1. For each value of first foo(), there can be 5 possible combinations for values of 
second foo(). So, there are total 25 combinations possible.
2. The range of values returned by the above equation is 1 to 25, each 
integer occurring exactly once.
3. If the value of the equation comes out to be less than 22, return modulo 
division by 7 followed by adding 1. Else, again call the method recursively. 
The probability of returning each integer thus becomes 1/7.
*/

#include<iostream>
using namespace std;

int rand7() {
	while(true) {
		int val = 5 * rand5() + rand5()-5;
		if(val <22) {
			return val%7 +1;
		}
	}
}