#include <iostream>

class MyStr {
	char* str;
	int size;
public:
	MyStr();
};

int main() {
	
	return 0;
}

MyStr::MyStr()
{
	size = 80;
	str = new char[80];
}
