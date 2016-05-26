#include <iostream>
#include <map.h>
using namespace std;


int main() {
 std::map<string,int> mymap;

if(mymap.find(“string_to search”) == mymap.end()) cout << “false”;
else cout << “true”;

return 0 ;
}