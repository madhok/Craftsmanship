#include<iostream>

using namespace std;

int partition(int arr[], int start, int end);
void swap(int &a,int &b);

int Kthsmallest(int arr[], int l, int r,int k) {
	 if (k > 0 && k <= r - l + 1) {
	 	int pos = partition(arr,l,r);
		if(pos-l == k-1) return arr[pos];
		else if(pos-l > k-1) {
			return Kthsmallest(arr, l,pos-1,k);	
		}
		return Kthsmallest(arr,pos+1,r,k-pos+l-1);	
	}
	return INT_MAX;
}

int partition(int arr[], int l, int r) {
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

void swap(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}


int main() {
	int arr[] = {12,3,5,7,4,19,26};
	cout << Kthsmallest(arr,0,6,7);
	return 0;
}