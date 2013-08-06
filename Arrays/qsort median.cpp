//find the median
#include <iostream>

using namespace std;



void qsortforMedain(int A[], int start, int end, int midpos, int& medianElement)
{
	/*
	int n = end - start + 1;
	if(end < start)
		return A[start];
	if(n == 1)
		return A[start];
		*/

	if(start>end)
		return;
	
	cout << "start : "  << start << endl;
	cout << "end : "  << end << endl;
	int median = start;
	for(int runningIndex = start; runningIndex <= end; runningIndex++)
	{
		if(A[start] < A[runningIndex])
		{
			median++;	
			swap(A[median], A[runningIndex]);
		}
	}
	swap(A[start], A[median]);
	for(int i = start; i <= end; i++)
		cout << A[i] << "\t";
	cout << endl;
	if(median == midpos)
		medianElement =  A[median];
	else if(median > midpos)
	{
		return qsortforMedain(A,start,median-1, midpos,medianElement);
	}
	else
	{
		return qsortforMedain(A, median+1, end, midpos,medianElement);	
	}
}

int findmedian(int A[], int n)
{
	if(n == 0)
		return -1;
	if(n == 1)
		return A[0];
	if(n == 2)
		return (A[0] + A[1])/2;

	int median = 0, median1 = 0, median2 = 0;
	if(n%2 == 0)
	{
		int medianpos1 = n/2;
		int medianpos2 = n/2 - 1; 

		qsortforMedain(A, 0, n-1,medianpos1, median1);
		qsortforMedain(A, 0, n/2 -1,medianpos2, median2);
		return (median1+median2)/2;

		//return (qsortforMedain(A, 0, n-1,medianpos1) + qsortforMedain(A, 0, n/2 -1,medianpos2))/2;
	}
	else
	{
		 qsortforMedain(A, 0, n-1,n/2, median);
		return median;//qsortforMedain(A, 0, n-1,n/2);
	}
}

int main()
{
	int A[8] = {5,7,8,2,1,10,12,4};

	cout << findmedian(A, 8);
}

