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

