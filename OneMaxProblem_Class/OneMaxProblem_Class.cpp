#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <iostream>
#include "mybitset.h"
#include "es.h"
#include "hclr.h"
#include "hc.h"
#include "sa.h"
#include "ts.h"

using namespace std;

int main()
{
    /*Hc test = Hc(30, 3000, 100);
    test.run();

    Sa test1 = Sa(30, 3000, 100);
    test1.run();*/
    
    Ts test2 = Ts(30, 3000, 100);
    test2.run();
    

    
    system("PAUSE");
}

