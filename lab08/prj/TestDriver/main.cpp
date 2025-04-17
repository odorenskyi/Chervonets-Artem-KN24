#include <iostream>
#include <cmath>
#include "ModulesChervonets.h"

int main() {
    double x, y, z;
    std::cout << "x y z? ";
    std::cin  >> x >> y >> z;
    double S = calculateS(x, y, z);
    if (std::isnan(S)) {
        std::cout << "S = NaN (sin(x) == 0)\n";
    } else {
        std::cout << "S = " << S << "\n";
    }
    return 0;
}
