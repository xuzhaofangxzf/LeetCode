#pragma once
class Array
{
public:
	Array();
	Array(const Array& another);
	Array(int len);
	void push_back(int value);
	int front();
	int back();
	void pop_back();
	int size();
	~Array();
	

private:
	int len;
	int* space;

};

