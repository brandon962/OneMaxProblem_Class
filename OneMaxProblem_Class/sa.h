#pragma once
#pragma once
#include "AlgoClass.h"
#include <cmath>

class Sa : public AlgoClass {
public:
	double temperature = 1;
	double temperature_end = 0.001;
	int ap;
	double alpha = 0.85;
public:
	void mesg() {
		cout << "HI, here is sa algo." << endl;
		cout << "We have : " << endl;
		cout << "\t" << bits << " bits" << endl;
		cout << "\t" << iterations << " iterations" << endl;
		cout << "\t" << runs << " runs" << endl;
	}

	void init() {
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);
		strcpy(algoname, "sa");
		mesg();
		savenum = iterations / savefreq;
		rundata = (int**)calloc(runs, sizeof(int*));
		for (int i = 0; i < runs; i++) {
			rundata[i] = (int*)calloc(savenum, sizeof(int));
		}
		savedata = (int*)calloc(savenum, sizeof(int));
	}

	Sa() {
		runs = 30;
		iterations = 3000;
		bits = 100;
		init();
	}
	Sa(int _r, int _i, int _b, double _t, double _a) {
		runs = _r;
		iterations = _i;
		bits = _b;
		temperature = _t;
		alpha = _a;
		init();
	}

	void run() {

		int count;

		start_time = time(NULL);
		for (int i = 1; i < runs + 1; i++) {
			cout << "Start " << i << " run." << endl;
			initial();
			count = 0;
			for (int j = 0; j < iterations; j++)
			{
				transition();
				determination();
				temperature *= alpha;
				
				if ((j + 1) % savefreq == 0) {
					rundata[i - 1][count] = gp;
					count++;
				}

			}
			cout << "Have " << gp << "'s 1" << endl ;
			cout << "End " << i << " run." << endl << endl;
		}
		int itmp = 0;
		for (int i = 0; i < savenum; i++) {
			itmp = 0;
			for (int j = 0; j < runs; j++) {
				itmp += rundata[j][i];
			}
			savedata[i] = itmp / runs;
		}


		strcpy(filename, "./data/");
		strcat(filename, algoname);
		strcat(filename, ".txt");

		fp = fopen(filename, "w+");

		for (int i = 0; i < savenum; i++) {
			fprintf(fp, "%d%s%d%s", (i + 1) * savefreq, " ", savedata[i], "\n");
		}

		fclose(fp);
		end_time = time(NULL);
		
	}

	void initial() {
		srand(time(NULL));
		bit_map.reset();

		for (int i = 0; i < bits; i++) {
			if (rand() % 2)
				bit_map.flip(i);
		}

		bit_best = bit_map;
		bit_acc = bit_map;
		ap = evaluation(bit_acc);
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
		bit_map = bit_acc;
		int itmp = rand() % bits;
		bit_map.flip(itmp);
		np = evaluation(bit_map);
	}

	double probability() {
		return exp((0.0 + np - ap) / temperature);
	}

	void determination() {
		double r;
		r = (double)rand() / RAND_MAX;

		if (probability() > r)
		{
			bit_acc = bit_map;
			ap = evaluation(bit_acc);
			if (np > gp) {
				bit_best = bit_map;
				gp = np;
			}
		}
		return;
	}

};

