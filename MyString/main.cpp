#include <iostream>

using namespace std;

class MyStr {
	char* str;
	int size;
public:
	MyStr();
	MyStr(const char* str);
};

int main() {
	
	return 0;
}

MyStr::MyStr()
{
	size = 80;
	str = new char[80];
}

MyStr::MyStr(const char* str)
{
	this->size = strlen(str);
	this->str = new char[size];
	std::strcpy(this->str, str);
}
