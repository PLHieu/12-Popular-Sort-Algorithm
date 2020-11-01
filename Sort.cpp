#include "Sort.h"
#include "DataGenerator.h"
#include "TypeSort.h"
#include <chrono> 
#include <fstream>

using namespace std;
using namespace std::chrono;

const string  Sort::SELECTION = "Selection";
const string  Sort::INSERTION = "Insertion";
const string  Sort::BINARY_INSER = "Binary_Insertion";
const string  Sort::BUBBLE = "Bubble";
const string  Sort::SHAKER = "Shaker";
const string  Sort::SHELL = "Shell";
const string  Sort::HEAP = "Heap";
const string  Sort::MERGE = "Merge";
const string  Sort::QUICK = "Quick";
const string  Sort::COUNTING = "Counting";
const string  Sort::RADIX = "Radix";
const string  Sort::FLASH = "Flash";

const int Sort::RANDOM = 0;
const int Sort::SORTED = 1;
const int Sort::REVERSED = 2;
const int Sort::NEARLY_SORTED = 3;

Sort::Sort(const int state, int size, const string type_sort) {
	this->_size = size;
	this->_state = state;
	this->_type = type_sort;	
}

map<string, FnPtr_Sort > Sort::mapTypeOfSort = {
	{"Selection", SelectionSort},
	{"Insertion", InsertionSort},
	{"Binary_Insertion", Binary_InsertionSort},
	{"Bubble", BubbleSort},
	{"Shaker", ShakerSort},
	{"Shell", ShellSort},
	{"Heap", HeapSort},
	{"Merge", MergeSort},
	{"Quick", QuickSort},
	{"Counting", CountingSort},
	{"Radix", RadixSort},
	{"Flash", FlashSort}
};

void Sort::Sort_Count_exetime() {
	// tao bo du lieu de test 
	int* Arr = new int[this->_size];
	GenerateData(Arr, this->_size, this->_state);

	// Dat diem bat dau 
	auto start = high_resolution_clock::now();
	// tien hanh Sort 
	mapTypeOfSort.at(this->_type)(Arr, this->_size);
	// Dat diem ket thuc
	auto stop = high_resolution_clock::now();
	// tinh toan thoi gian thuc thi ham sap xep
	auto duration = duration_cast<microseconds>(stop - start);

	//// Xuat ra console mang 
	//for (int i = 0; i < this->_size; i++) {
	//	cout << " " << Arr[i];
	//}

	//xuat ra file thoi gian thuc thi
	ofstream writers("time.txt", ios::out);
	if (writers.fail()) {
		cout << "Cannot write the file, there could be some errors" << endl;
	}
	writers << this->_type << " " << this->_state << " " << this->_size << " Time: " << duration.count() << " micros" << endl;
	writers.close();

	delete[] Arr;
}

Sort::~Sort() {
	cout << "Destruction";
}

