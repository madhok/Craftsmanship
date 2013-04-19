// C++ code of KMP String Matching Algorithm
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;


void FailureFunction(char P[], int F[],int m){
 int i,j;
 F[0]=0; //  assignment is important!
 j=0;
 i=1;
 while(i<m){ // that i is less than the length of pattern
  if(P[i]==P[j]){
   F[i]=j+1;
   i++;
   j++;
  }else if(j>0){
   j=F[j-1];
  }else {
   F[i]=0;
   i++;
  }
 }
}

int KMP(char T[], char P[]){
 int i,j,F[100]; // the maximum size of Pattern String
 int m=strlen(P);
 int n=strlen(T);
 FailureFunction(P,F,m);
 i=0;
 j=0;
 while(i<n){
  if(T[i]==P[j]){
   if(j==m-1)
    return i-j; // means, in (i-j)th position, there is a match occur
   else{
    i++;
    j++;
   }
  }else if(j>0){
   j=F[j-1];
  }else{
   i++;
  }
 }
 return -1; // No match found
}


int main()
{
 //freopen("in.txt","rt",stdin);
 //freopen("out.txt","wt",stdout);

 char T[1000],P[100];

 while(gets(T)){
  gets(P);
  int pos=KMP(T,P);
  if(pos!=-1)
   cout<<"String Occur at position: "<<pos<<endl;
  else
   cout<<"No match found"<<endl;

 }
 
// End of main function........
return 0;
}
