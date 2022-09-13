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

	void Print();
	void Inpute();
};

int main() {
	MyStr str1("Hello WORLD");
	str1.Print();
	
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
	this->str = new char[size + 1];
	strcpy(this->str, str);
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

void MyStr::Print()
{
	if(size != 0)
		cout << str;
}

void MyStr::Inpute()
{
	char* buf = new char[size];
	cin.getline(buf, size);
	strcpy_s(this->str, size, buf);
}