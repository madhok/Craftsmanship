// Example program
#include <iostream>
#include <string>
#include <map>

using namespace std;

void print(char arr[], int n) {
    for(int i = 0; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void match_array(char nuts[], char bolts[], int n) {
    map<char,int> hmap;
    for(int i = 0; i < n; i++) {
        hmap[bolts[i]] = i;
    }
    for(int i = 0; i < n; ++i) {
        if(hmap.find(nuts[i]) == hmap.end()) {
            cout << "Error" << endl;
            return;
        }
        int index = hmap[nuts[i]];
        cout << nuts[i] << endl;
        cout << "Index is" << index << endl;
        cout << "I is" << i << endl;
        //cout << bolts[i] << endl;
        swap(nuts[index], nuts[i]);
        hmap[nuts[i]] = index;
        //cout << bolts[i] << endl;
        
    }
    print(nuts,5);
    print(bolts,5);
    
    return;
}

int main()
{
  char nuts[5] = {'@','%','$','#','^'};
  char bolts[5] = {'%','#','^','@','$'};
  match_array(nuts, bolts,5);
    
}
