#pragma once
#include <string>
#include <iostream>
#include <map>
#include <functional>

using namespace std;

// con tro ham
typedef void (*FnPtr_Sort)(int*, int);

class Sort {

public :
	static const string SELECTION ;
	static const string INSERTION ;
	static const string BINARY_INSER ;
	static const string BUBBLE ;
	static const string SHAKER ;
	static const string SHELL ;
	static const string HEAP ;
	static const string MERGE ;
	static const string QUICK ;
	static const string COUNTING ;
	static const string RADIX ;
	static const string FLASH ;

public: 
	static const int SORTED ;
	static const int REVERSED;
	static const int RANDOM;
	static const int NEARLY_SORTED;


private :
	// trang thai cua loai sort do
	int _state;
	// kich thuoc cua loai sort do
	int _size;
	// loai sort
	string _type;
	//thoi gian thuc thi
	double _time_execute;

private:
	static map<string, FnPtr_Sort > mapTypeOfSort;

public:
	int State() { return _state; }
	double Time_execute() { return _time_execute; }
	int Size() { return _size; }

	void SetState(int state) { _state = state; }
	void SetSize(int size) { _size = size; }

public:
	Sort();
	Sort(const int,  int, const string);
	~Sort();

public:
	void Sort_Count_exetime();
};

