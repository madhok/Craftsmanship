#include <iostream>

using namespace std;

struct Element {
	int data;
	Element *next;
};

class Stack {
	Element *top;	
public:
	Stack() {top =NULL;}
	bool push(int newdata);
	int pop();
};

bool Stack::push(int newdata) {	
	Element *element = new Element();
	element->data = newdata;
	element->next = NULL;

	if(top == NULL) {
		top = element;
		return true;
	}
	element->next = top;
	top = element;
	cout << "pushed " << top->data << endl;
	return true;
}
int Stack::pop() {
	if(top == NULL) {return -1; }
	if(top->next == NULL) {
		int ret = top->data;
		delete top;
		top = NULL;		
		return ret;
	}
	int ret = top->data;
	Element *curr = top;
	top = top->next;
	delete curr;
  	return ret;
}

int main (){
	Stack mystack;
	mystack.push(1);	
	mystack.push(2);
	mystack.push(3);

	std::cout << "pop " << mystack.pop() << endl;
	mystack.push(3);
	mystack.push(4);
	std::cout << "pop " << mystack.pop() << endl;
	std::cout << "pop " << mystack.pop() << endl;
	std::cout << "pop " << mystack.pop() << endl;
	std::cout << "pop " << mystack.pop() << endl;
	std::cout << mystack.pop() << endl;
	return 0;
}