#pragma once
#include "AlgoClass.h"

class Hc : public AlgoClass {
public:
	
public:
	void mesg() {
		cout << "HI, here is hc algo." << endl;
		cout << "We have : " << endl;
		cout << "\t" << bits << " bits" << endl;
		cout << "\t" << iterations << " iterations" << endl;
		cout << "\t" << runs << " runs" << endl;
		//cout << "\t" << "Output filename : \"" << outputfile << "\"" << endl;
	}

	void start() {
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);
		strcpy(algoname, "hc");
		mesg();
		savenum = iterations / savefreq;
		rundata = (int**)calloc(runs, sizeof(int*));
		for (int i = 0; i < runs; i++) {
			rundata[i] = (int*)calloc(savenum, sizeof(int));
		}
		savedata = (int*)calloc(savenum, sizeof(int));
	}

	Hc() {
		runs = 30;
		iterations = 3000;
		bits = 100;
		start();
	}
	Hc(int _r, int _i, int _b) {
		runs = _r;
		iterations = _i;
		bits = _b;
		start();
	}

	void run() {
		
		int count;
		
		start_time = time(NULL);
		for (int i = 1; i < runs + 1; i++) {
			cout << "Start " << i << " run." << endl;
			initial();
			count = 0;
			for (int j = 0 ; j < iterations; j++)
			{
				transition();
				determination();
				if ((j+1)%savefreq == 0) {
					rundata[i-1][count] = gp;
					count++;
				}

			}
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
			fprintf(fp, "%d%s", savedata[i], "\n");
		}

		fclose(fp);
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
		bit_map = bit_best;
		int itmp = rand() % bits;
		bit_map.flip(itmp);
		//cout << itmp << "   " << bit_map.bit_map[itmp] << "  " << bit_best.bit_map[itmp] << endl;
		np = evaluation(bit_map);
		//cout << bit_map.to_string() << endl;
		//cout << "np = " << np << endl;
	}

	void determination() {
		if (np > gp) {
			bit_best = bit_map;
			gp = np;
			//cout << bit_best.to_string() << endl;
			//cout << "Have " << gp << " bits." << endl;
		}
		return;
	}

	void writefile() {

	}
};
