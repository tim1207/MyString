#include"test_MyString.h"
#include <iostream>
#include <string>
using namespace std;
using std::ostream;
using std::istream;

class MyString_Derived :public MyString {
	
public:
	//template <class T>
	//MyString_Derived(T s) : MyString(s) {}
	MyString_Derived(const char* s) : MyString(s) {}
};


