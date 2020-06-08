#include <iostream>
//#include <string>
#include <vector>
using namespace std;
using std::ostream;
using std::istream;

class MyString {
protected:
	char* _data;
	int  _len;

public:
	static int _total_MyString;
	/////////////////////////////////////////////////////////
		// 把σ strlen strcpy
	MyString()
	{
		_data = nullptr;
		_len = 0;
		_total_MyString++;
	}
	MyString(const char* s) {
		_data = nullptr;
		//_len = strlen(s);
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		i++;
		_len = i;
		_data = new char[_len + 1];
		for (int i = 0; i <= _len; i++)
			_data[i] = s[i];
		_total_MyString++;
	}
	MyString(const MyString& s) {
		_len = s._len;
		_data = new char[_len + 1];
		for (int i = 0; i <= _len; i++)
			_data[i] = s._data[i];
		_total_MyString++;
	}
	~MyString() {
		_total_MyString--;
		delete[] _data;
		_len = 0;
	}
	/////////////////////////////////////////////////////////
	static int total_MyString() {
		return _total_MyString;
	}
	/////////////////////////////////////////////////////////
	// 把σ strcpy	
	MyString& operator=(const MyString& rhs);
	/////////////////////////////////////////////////////////
	// 把σ strcat	
	MyString& operator+=(const MyString& rhs);
	/////////////////////////////////////////////////////////
	inline char& operator[](const int pos) {
		return _data[pos];
	}
	/////////////////////////////////////////////////////////
	// 把σ strlen	
	unsigned length() const {
		return _len;
	}
	/////////////////////////////////////////////////////////
	friend ostream& operator<<(ostream&, const MyString&);
	//*********
	friend istream& operator>>(istream&, MyString&);
	//friend ostream& operator>>(ostream& in, MyString_Derived& a);
	/////////////////////////////////////////////////////////
	// 把σ strcmp
	bool operator==(const MyString&);
	friend bool operator!=(const MyString&, const MyString&);
};

ostream& operator<<(ostream& out, const MyString& a) {
	//out << a._data;
	//out << a._len;
	for (int i = 0; i < a._len; i++)
		out << a._data[i];
	return out;
}
//**********


MyString& MyString :: operator=(const MyString& rhs) {
	delete[]_data;
	_len = rhs._len;
	_data = new char[_len + 1];
	for (int i = 0; i <= _len; i++)
		_data[i] = rhs._data[i];
	return *this;
}

//************************************
bool MyString ::operator==(const MyString& com) {
	int i;
	for (i = 0; i < _len; i++) {
		if (_data[i] != com._data[i])
			break;
	}
	if (i != _len)
		return false;
	else
		return true;
	/*
	int compare = strcmp(_data, com._data);
	if (_len == com._len && compare == 0)
		return true;
	else
		return false;
	*/
}
bool operator!=(const MyString& a, const MyString& b) {
	int i;
	for (i = 0; i < a._len; i++) {
		if (a._data[i] != b._data[i])
			break;
	}
	if (i != a._len)
		return true;
	else
		return false;
	
	/*
	int compare = strcmp(a._data, b._data);
	if (a._len != b._len)
		return true;
	else if (compare != 0)
		return true;
	else
		return false;
	*/
}

istream& operator>>(istream& in, MyString& a) {
	/*string temp = "";
	in >> temp;
	a._len = temp.length();
	delete[]a._data;
	a._data = new char[a._len + 1];
	const char* buffer = temp.c_str();
	MyString temp2(buffer);
	a = buffer;
	***********************************************************
	inline istream& operator>>(istream & in, MyString & s) {
		cin >> s._data;
		s._len = strlen(s._data);
		return in;
	}
	*/
	vector<char> temp;
	delete[]a._data;
	while (true) {
		char c = cin.get();
		if (c == '\n')
			break;
		temp.push_back(c);
	}
	a._len = temp.size();
	a._data = new char[a._len + 1];
	int i;
	for (i = 0; i < temp.size(); i++)
		a._data[i] = temp[i];
	a._data[i] = '\0';
	return in;
	//
}
//*****************************************
MyString& MyString:: operator+=(const MyString& rhs) {
	/*
	string a = "";
	a = _data;
	a.append(rhs._data);	//a += rhs._data;
	cout << a;
	_len += rhs._len;
	const char* buffer = a.c_str();
	MyString temp(buffer);
	*this = buffer;
	return *this;
	*/

	MyString temp(*this);
	delete[]_data;
	_data = new char[_len + rhs._len + 1];
	for (int i = 0; i < _len; i++)
		_data[i] = temp._data[i];
	for (int i = 0; i < rhs._len; i++)
		_data[i + _len] = rhs._data[i];
	_len += rhs._len;

	return *this;
}





#pragma once
