/*
Given a positive number x, print all Jumping Numbers smaller than or equal to x. A number is called as a Jumping Number if all adjacent digits in it differ by 1. The difference between ‘9’ and ‘0’ is not considered as 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

Input:
The first line of the input contains T denoting the number of testcases. Each testcase contain a positive number 'x'.
Output:
All the jumping numbers less than 'x' are generated in increasing order of the most significant digit. See example for better understanding.


Constraints:
1 <=T<= 100
1 <=N<= 100000


Example:
Input:
2
10
50
Output:
0 1 10 2 3 4 5 6 7 8 9
0 1 10 12 2 21 23 3 32 34 4 43 45 5 6 7 8 9

*/
#include <iostream>
#include <queue>
using namespace std;

void print_jumping(int num, int x) {
    queue<int> q;
    q.push(num);
    
    while(!q.empty()) {
        num=q.front();
        q.pop();
        if(num<=x) {
            cout << num << " ";
            int last = num%10;
            if(last == 0) {
                q.push((num*10) + (last+1));
            } else if(last ==9) {
                q.push((num*10) + (last-1));
            } else {
                q.push((num*10) + (last+1));
                q.push((num*10) + (last-1));
            }
        }
    }
}

int main() {
	int n;
	cin >>n;
	while(n) {
	    n--;
	    int val;
	    cin >> val;
	    cout << 0 << " "; 
	    for(int i=1;i<=val && i<=9;++i) {
	        print_jumping(i,val);
	    }
	    cout << endl;
	}
	return 0;
}
