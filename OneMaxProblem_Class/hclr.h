#pragma once
#include "AlgoClass.h"

class HcLr : public AlgoClass {
public:

public:
	void mesg() {
		cout << "HI, here is hclr algo." << endl;
		cout << "We have : " << endl;
		cout << "\t" << bits << " bits" << endl;
		cout << "\t" << iterations << " iterations" << endl;
		cout << "\t" << runs << " runs" << endl;
		//cout << "\t" << "Output filename : \"" << outputfile << "\"" << endl;
	}

	HcLr() {
		runs = 30;
		iterations = 3000;
		bits = 100;
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);

		mesg();
	}
	HcLr(int _r, int _i, int _b) {
		runs = _r;
		iterations = _i;
		bits = _b;
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);

		mesg();
	}

	void run() {
		start_time = time(NULL);
		for (int i = 1; i < runs+1; i++) {
			cout << "Start " << i << " run." << endl;
			initial();
			for (int j = 0; j < iterations; j++)
			{
				transition();
				determination();
			}
			cout << "End " << i << " run." << endl << endl;
		}
	}

	void initial() {
		srand(time(NULL));
		bit_map.reset();

		for (int i = 0; i < bits; i++) {
			if (rand() % 2)
				bit_map.flip(i);
		}

		bit_best = bit_map;
		np = evaluation(bit_map);
		gp = np;

		cout << "The initial bitmap" << endl;
		cout << bit_map.to_string() << endl;
		cout << "The number of 1's : " << np << endl;
	}

	int evaluation(MyBitSet b) {
		return b.count();
	}

	void transition() {
		srand(time(NULL));
		if (rand() % 2) {
			for (int i = bits - 1; i >= 0; i--) {
				if (bit_map.test(i)) {
					bit_map.reset(i);
					continue;
				}
				else {
					bit_map.set(i);
					break;
				}
			}
		}
		else {
			for (int i = bits - 1; i >= 0; i--) {
				if (bit_map.test(i)) {
					bit_map.reset(i);
					break;
				}
				else {
					bit_map.set(i);
					continue;
				}
			}
		}
		np = evaluation(bit_map);
		//cout << bit_map.to_string() << endl;
	}

	void determination() {
		if (np > gp) {
			bit_best = bit_map;
			gp = np;
			//cout << bit_best.to_string() << endl;
			cout << "Have " << gp << " bits." << endl;
		}
		return;
	}

};
