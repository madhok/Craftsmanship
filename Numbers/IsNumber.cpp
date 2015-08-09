/*
Check if a string is a number or not
*/
#include <iostream>
#include <string>
using namespace std;


bool isNum(char c) {
  if(c < '0' || c > '9')
  {
    return false;
  }
    
  return true;
}

bool isNumber(string str) {
  if(str.length() == 0) 
    return true;

  int index = 0;
  int len = str.size();
  while(str[index] == ' ') {
    index++;
    continue;
  }
  if(str[index] == '+' || str[index] == '-') {
    index++;
  }
  bool isdecimal = false;
  bool num = false;
  while(index < len) {

    if(isNum(str[index])) {
      num = true;
      index++;
      continue;
    }
      if(!isdecimal && str[index] == '.') {
      isdecimal = true;
      index++;
      continue;
    }
    
    return false;
  }
  return num;
}

int main() {
  //cout << "Enter the number\n"<< endl;
  //string str ;
  //getline(cin,str);
  string str = "        -65.090";
  if(isNumber(str))
    cout << "Is a number" << endl;
  else cout << "Not a number" << endl;
  return 0;
}
