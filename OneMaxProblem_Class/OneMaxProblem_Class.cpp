#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <iostream>
#include "mybitset.h"
#include "es.h"
#include "hclr.h"
#include "hc.h"

using namespace std;

int main()
{
    Hc test = Hc(30, 3000, 100);
    test.run();
    system("PAUSE");
}

