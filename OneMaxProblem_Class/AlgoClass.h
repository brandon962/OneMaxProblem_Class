#pragma once
#include <iostream>
#include "mybitset.h"
#include <ctime>
#include <string>

using namespace std;

class AlgoClass
{
public:
	int savefreq = 50;
	int** rundata;
	int* savedata;
	int savenum;
	FILE* fp;
	char filename[100];
	char algoname[20];
	MyBitSet bit_map;
	MyBitSet bit_best;
	MyBitSet bit_acc;
	int runs, iterations, bits, np, gp;
	//string outputfile;
	time_t start_time, now_time, end_time;

public:
	void init();
	AlgoClass() {};
	void initial();
	int evaluation();
	void transition();
	void run();
	void writefile();
	//~AlgoClass() {};
};