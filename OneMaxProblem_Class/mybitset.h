#pragma once
#include <iostream>
#include <vector>


using namespace std;

class MyBitSet {
public:
	vector <bool> bit_map;
	int bitsize;

public:
	MyBitSet() {
		bit_map.resize(1, false);
		bitsize = 1;
	}
	MyBitSet(int _size) {
		bit_map.resize(_size, false);
		bitsize = _size;
	}

	bool all() {
		for (int i = 0; i < bitsize; i++) {
			if (!bit_map[i])
				return false;
		}
		return true;
	}

	bool any() {
		for (int i = 0; i < bitsize; i++) {
			if (bit_map[i])
				return true;
		}
		return false;
	}

	int count() {
		int c = 0;
		for (int i = 0; i < bitsize; i++) {
			if (bit_map[i])
				c++;
		}
		return c;
	}

	void flip()	{
		for (int i = 0; i < bitsize; i++)
			bit_map[i] = !bit_map[i];
	}

	void flip(int i) {
		bit_map[i] = !bit_map[i];
	}

	bool none() {
		for (int i = 0; i < bitsize; i++) {
			if (bit_map[i])
				return true;
		}
		return true;
	}

	void set() {
		for (int i = 0; i < bitsize; i++)
			bit_map[i] = true;
	}

	void set(int i)	{
		bit_map[i] = true;
	}

	void reset() {
		for (int i = 0; i < bitsize; i++)
			bit_map[i] = false;
	}

	void reset(int i) {
		bit_map[i] = false;
	}

	int size() {
		return bitsize;
	}

	bool test(int i)
	{
		if (bit_map[i])
			return true;
		return false;
	}

	string to_string() {
		string stmp;
		for (int i = 0; i < bitsize; i++)
		{
			if (bit_map[i])
				stmp += "1";
			else
				stmp += "0";
		}

		return stmp;
	}
	//~MyBitSet() {}
};