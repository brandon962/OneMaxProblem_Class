#pragma once
#include "AlgoClass.h"
#include <queue>

class Ts : public AlgoClass {
public:
	queue <vector<bool>> tabu_list;
	int list_long = 7;
public:
	void mesg() {
		cout << "HI, here is ts algo." << endl;
		cout << "We have : " << endl;
		cout << "\t" << bits << " bits" << endl;
		cout << "\t" << iterations << " iterations" << endl;
		cout << "\t" << runs << " runs" << endl;
		//cout << "\t" << "Output filename : \"" << outputfile << "\"" << endl;
	}

	void start() {
		bit_map = MyBitSet(bits);
		bit_best = MyBitSet(bits);
		strcpy(algoname, "ts");
		mesg();
		savenum = iterations / savefreq;
		savedata = (int*)calloc(savenum, sizeof(int));
	}

	Ts() {
		runs = 30;
		iterations = 3000;
		bits = 100;
		start();
	}
	Ts(int _r, int _i, int _b) {
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
			for (int j = 0; j < iterations; j++)
			{
				transition();
				determination();
				if ((j + 1) % savefreq == 0) {
					savedata[count] += gp;
					count++;
				}

			}

			while (!tabu_list.empty()) {
				tabu_list.pop();
			}
			
			cout << "End " << i << " run." << endl << endl;
		}
		
		for (int i = 0; i < savenum; i++) {
			savedata[i] /= runs;
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
		cout << "Cost " << end_time - start_time << " s." << endl;
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


		for (int i = 0; i < list_long; i++) {
			tabu_list.push(bit_map.bit_map);
		}

		cout << "The initial bitmap" << endl;
		cout << bit_map.to_string() << endl;
		cout << "The number of 1's : " << np << endl;
	}

	int evaluation(MyBitSet b) {
		return b.count();
	}

	void transition() {
		int itmp;
		do {
			bit_map = bit_best;
			itmp = rand() % bits;
			bit_map.flip(itmp);
		} while (find_tabu(tabu_list, bit_map.bit_map));
		tabu_list.pop();
		tabu_list.push(bit_map.bit_map);
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

	bool find_tabu(queue<vector<bool>> l, vector<bool> t) {
		queue<vector<bool>> ltmp = l;
		int size = l.size();
		for (int i = 0; i < size; i++) {
			if (ltmp.front() == t) {
				return true;
			}
			ltmp.pop();
		}
		return false;
	}

};
