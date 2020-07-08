#pragma once
#include <iostream>
#include "mybitset.h"
#include <ctime>
#include <string>

using namespace std;

class AlgoClass
{
public:
	MyBitSet bit_map;
	MyBitSet bit_best;
	MyBitSet bit_tmp;
	int runs, iterations, bits, np, gp;
	//string outputfile;
	time_t start_time, now_time, end_time;

public:
	AlgoClass() {};
	void initial();
	int evaluation();
	void transition();
	void run();
	//~AlgoClass() {};
};