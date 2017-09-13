#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class SudokuGenerate {
public:
	SudokuGenerate() {};
	void init();
	void initArray();
	bool generate(int k);
	bool IsRightPlace(int number, int row, int col);
	void print();
	void set(int number);
private:
	int num[9][9];
	int count[9];
	
};


