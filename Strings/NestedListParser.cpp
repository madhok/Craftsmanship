#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define INVALID = -1;

template <class T>
class NestedList {
private:
	T value;
	bool isNum;
	vector<NestedList> List;
public:
	NestedList():value(-1),isNum(false) {}
	NestedList(T num) {
		value = num;
		isNum =true;
	}
	void add_list(NestedList l) {
		List.push_back(l);
	}
	void get_val(T &val, bool& err) {
		if(isNum) {
			err = false;
			val = value;	
		}else {
		    err = true;
		}
		
	}
};

int main() {
	NestedList<int> input;
	NestedList<int> nest1(20);
	input.add_list(nest1);
 	int val = 0;
	bool err = false;
    input.get_val(val, err);
    if(!err)
    cout << val;
	return 0;
}


