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
	void MyStrcpy(MyStr& obj);
	bool MyStrStr(const char* str2);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyStr & b);
	void MyDelChr(char c);
	int MyStrCmp(MyStr & b);
};

int main() {

	
	return 0;
}

MyStr::MyStr()
{
	size = 80;
	str = new char[size];
}

MyStr::MyStr(const char* str)
{
	this->size = strlen(str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size, str);
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

void MyStr::MyStrcpy(MyStr& obj)
{
	if (obj.size > size)
		strcpy_s(obj.str, size, str);
}

bool MyStr::MyStrStr(const char* str2)
{
	int size2 = 0;
	for (int i = 0; str2[i] != '\0'; i++)
		size2++;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size2; j++) {
			if (str2[j] != str[i])
				break;
			else if (j == size2 - 1)
				return 1;
		}
	return 0;
}

int MyStr::MyChr(char c)
{
	for (int i = 0; i < size; i++)
		if (str[i] == c)
			return i;
	return -1;
}

int MyStr::MyStrLen()
{
	return size;
}

void MyStr::MyStrCat(MyStr& b)
{
	char* TempStr = new char[size+1];
	strcpy_s(TempStr, size, str);
	size += b.size;
	delete[] str;
	str = new char[size+1];
	for (int i = 0; i < size - b.size; i++)
		str[i] = TempStr[i];
	for (int i = size - b.size; i < b.size; i++)
		str[i] = b.str[i - b.size];
}

void MyStr::MyDelChr(char c)
{
	int x = 0;
	char* TempStr = new char[size+1];
	strcpy_s(TempStr, size, str);
	for (int i = 0; i < size; i++) {
		if (str[i] == c) {
			size--;
			x++;
		}
		else
			TempStr[i - x] = str[i];
	}
	delete[] str;
	str = new char[size+1];
	strcpy_s(str, size, TempStr);
}

int MyStr::MyStrCmp(MyStr& b)
{
	if (size < b.size)
		return -1;
	if (size > b.size)
		return 1;
	return 0;
}
