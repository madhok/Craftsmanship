//Heapify - Top down approach 
//http://sankofa.loc.edu/chu/web/Courses/Cosi335/Ch6/Heapify.pdf

#include<iostream> 
#include <vector> 
using namespace std; 

void heapify(vector<int> &v, int i); 
void main() 
{ 
	int Arr[9]={1, 14, 10, 8, 7, 9, 3, 2, 4}; 
	 vector<int> A(Arr, Arr+9); 
	 heapify(A, 0); 
	 for(int i=0; i<9; i++) 
	 cout<<A[i]<<" "; 
	 cout<<endl; 
} 

void heapify(vector<int> &v, int i) 
{ 
	int left=2*i+1, right=2*i+2, largest=i, temp; 
	
	if(left < v.size() && v[largest] < v[left]) 
	 largest = left; 
	
	if(right < v.size() && v[largest] < v[right]) 
	 largest = right; 
	
	if( i != largest) 
	 { 
		 temp = v[i]; 
		 v[i] = v[largest]; 
		 v[largest] = temp; 
		 heapify(v, largest); 
	 } 
}