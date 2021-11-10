#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int iter_count = 400000;



class Test {
    public:
    int _;
    
    Test() {
        static int __ = 0;
        this->_ = __;
        ++__;
    }
};

int main() {
    clock_t cl = clock();
    for(int it = 0; it < iter_count; ++it) {
        new Test[10000];
    }
    clock_t end_cl = clock();
    double tim = (end_cl-cl)/(double)CLOCKS_PER_SEC*1000000000;
    printf("%.14lf\n", tim / iter_count);
    return 0;
}