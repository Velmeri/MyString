#include <iostream>

using namespace std;

class MyStr {
	char* str;
	int size;
public:
	MyStr();
	MyStr(const char* str);
	MyStr(const int size);
	~MyStr();
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
	this->str = new char[size+1];
	std::strcpy(this->str, str);
}

MyStr::MyStr(const int size)
{
	this->size = size;
	this->str = new char[size];
}

MyStr::~MyStr()
{
	delete str;
	delete[] str;
}
