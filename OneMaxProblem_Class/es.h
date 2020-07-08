#pragma once
#include "AlgoClass.h"

class Es : public AlgoClass {
public:

public:
	void mesg() {
		cout << "HI, here is es algo." << endl;
		cout << "We have : " << endl;
		cout << "\t" << bits << " bits" << endl;
		cout << "\t" << iterations << " iterations" << endl;
		cout << "\t" << runs << " runs" << endl;
		//cout << "\t" << "Output filename : \"" << outputfile << "\"" << endl;
	}

	Es() {
		runs = 30;
		iterations = 3000;
		bits = 100;
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);

		mesg();
	}
	Es(int _r, int _i, int _b) {
		runs = _r;
		iterations = _i;
		bits = _b;
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);
		
		mesg();
	}

	void run() {
		start_time = time(NULL);
		initial();
		while (1)
		{
			transition();
			determination();
			now_time = time(NULL);

			if (now_time - start_time > 3600) {
				cout << "hi" << endl;
				break;
			}
		}
		cout << gp << endl;
	}

	void initial() {
		srand(time(NULL));
		bit_map.reset();
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
		for (int i = bits - 1; i >= 0; i--) {
			if(bit_map.test(i)) {
				bit_map.reset(i);
				continue;
			}
			else {
				bit_map.set(i);
				break;
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
		}
		return;
	}

};
