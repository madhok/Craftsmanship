/*
There is one meeting room in Flipkart. There are n meetings in the form of (S [ i ], F [ i ]) where S [ i ] is start time of meeting i and F [ i ] is finish time of meeting i

What is the maximum number of meetings that can be accommodated in the meeting room ?

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].


Output:

In each separate line print the order in which the meetings take place separated by a space.


Constraints:

1 ≤ T ≤ 70

1 ≤ N ≤ 100

1 ≤ S[ i ], F[ i ] ≤ 100000


Example:

Input:

1
6
1 3 0 5 8 5
2 4 6 7 9 9 

Output:

1 2 4 5

*/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>
using namespace std;

int get_index(int* S, int* F, int si, int fi,int size) {
    for(int i = 0; i < size; ++i) {
        if(si == S[i] && fi == F[i]) {
            return i;
        }
    }
}

bool comparator(pair<int,int> i, pair<int,int> j) {
    return i.second<j.second;
}

void print_meetings(int *S, int *F, int size) {
    vector<pair<int,int> >meeting;
    for(int i = 0; i < size; ++i) {
        meeting.push_back(make_pair(S[i],F[i]));    
    }
    sort(meeting.begin(), meeting.end(),comparator);
    //cout << meeting[0].first << "-" << meeting[0].second << ",";
    //int prev= meeting[0].second;
    int prev = INT_MIN;
    for(int i = 0; i< size; ++i) {
        if(prev <= meeting[i].first) {
            //cout << meeting[i].first << "-" << meeting[i].second << ",";
            int index = get_index(S,F,meeting[i].first, meeting[i].second,size);
            cout << index+1 << " ";
            prev = meeting[i].second;
        }
    }
    cout << endl;    
}

int main() {
	//code
	int n;
	cin >> n;
	while(n) {
	    n--;
	    int size;
	    cin >> size;
	    int S[size],F[size];
	    for(int i = 0; i < size; ++i) {
	        int val;
	        cin >> val;
	        S[i] = val;
	    }
	    for(int i = 0; i < size; ++i) {
	        int val;
	        cin >> val;
	        F[i] = val;
	    }
	    print_meetings(S,F, size);
	}
	return 0;
}