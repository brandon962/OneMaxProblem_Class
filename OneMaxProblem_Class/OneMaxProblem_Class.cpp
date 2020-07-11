#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <iostream>
#include <cstring>
#include "mybitset.h"
#include "es.h"
#include "hclr.h"
#include "hc.h"
#include "sa.h"
#include "ts.h"

using namespace std;

int main(int argc, char* argv[])
{
    int runs = 30;
    int bits = 100;
    int iterations = 1000;
    string algo;
    double temperature = 1.2;
    double alpha = 0.97;
    int list_long = 10;

    if (argc > 1)
        algo = argv[1];

    if (algo == "hc") {
        if(argc > 4) {
            runs = atoi(argv[2]);
            iterations = atoi(argv[3]);
            bits = atoi(argv[4]);
        }
        Hc hc = Hc(runs, iterations, bits);
        hc.run();
    }
    else if (algo == "hclr") {
        if (argc > 4) {
            runs = atoi(argv[2]);
            iterations = atoi(argv[3]);
            bits = atoi(argv[4]);
        }
        HcLr hclr = HcLr(runs, iterations, bits);
        hclr.run();
    }
    else if (algo == "sa") {
        if (argc > 6) {
            runs = atoi(argv[2]);
            iterations = atoi(argv[3]);
            bits = atoi(argv[4]);
            temperature = atoi(argv[5]);
            alpha = atoi(argv[6]);
        }
        Sa sa = Sa(runs, iterations, bits, temperature, alpha);
        sa.run();
    }
    else if (algo == "ts") {
        if (argc > 5) {
            runs = atoi(argv[2]);
            iterations = atoi(argv[3]);
            bits = atoi(argv[4]);
            list_long = atoi(argv[5]);
        }
        Ts ts = Ts(runs, iterations, bits, list_long);
        ts.run();
    }
    else
    {
        /*Hc hc = Hc(runs, iterations, bits);
        hc.run();
        HcLr hclr = HcLr(runs, iterations, bits);
        hclr.run();*/
        Sa sa = Sa(runs, iterations, bits, temperature, alpha);
        sa.run();
        Ts ts = Ts(runs, iterations, bits, list_long);
        ts.run();
    }
    
    cout << endl;

    return 0;

}

