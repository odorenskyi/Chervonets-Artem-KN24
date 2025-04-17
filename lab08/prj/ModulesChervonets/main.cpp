#include "ModulesChervonets.h"
#include <cmath>    // для sin, cos, sqrt, fabs, pow, nan
#include <limits>   // для numeric_limits

double calculateS(double x, double /*y*/, double z) {
    constexpr double pi = 3.14159265358979323846;
    double sinx = std::sin(x);
    if (sinx == 0.0) {
        // якщо потрібно повернути NaN при діленні на нуль
        return std::numeric_limits<double>::quiet_NaN();
    }

    double a = std::fabs(2.0 * z - x * x) / sinx;
    double numerator   = 0.5 * std::pow(a, 3);
    double denominator = std::sqrt(1.0 + std::fabs(std::cos(x))) + 2.0 * pi;

    return numerator / denominator;
}

