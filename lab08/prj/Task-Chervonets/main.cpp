#include "ModulesChervonets.h"

#include <windows.h>
#include <iostream>
#include <cmath>       // sin, cos, fabs, sqrt, pow, isnan
#include <limits>      // numeric_limits
#include <iomanip>     // fixed, setprecision, hex, dec, nouppercase
#include <cstdint>     // uint64_t

namespace {
    constexpr double pi = 3.14159265358979323846;
}


void developer_information() {
    std::cout << "Артем Червонець ©, Усі права захищені." << std::endl;
}

double logical(int a, int b) {
    bool res = (a + 1 <= b);
    std::cout << "Результат логічного виразу: " << (res ? '1' : '0') << std::endl;
    return res ? 1.0 : 0.0;
}

void numbers_in_systems(double x, double y, double z) {
    // Для бітового представлення double використовуємо union
    auto print_pair = [&](double v, const char* name) {
        union {
            double    d;
            uint64_t  u;
        } cv{v};
        std::cout << name << " = "
                  << std::fixed << std::setprecision(2) << v
                  << " (десяткова) = 0x"
                  << std::hex << std::uppercase << cv.u
                  << std::dec << std::nouppercase
                  << std::endl;
    };

    std::cout << "\nЗначення змінних в десятковій та шістнадцятковій системах числення:\n";
    print_pair(x, "x");
    print_pair(y, "y");
    print_pair(z, "z");

    double s = calculateS(x, y, z);
    std::cout << "\nРезультат обчислення функції calculateS: "
              << std::fixed << std::setprecision(6)
              << s << std::endl;
}

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    developer_information();

    // Введення даних для функції logical
    int a, b;
    std::cout << "Введіть два цілих числа для логічної функції (a b): ";
    std::cin >> a >> b;
    logical(a, b);

    // Введення даних для функції numbers_in_systems
    double x, y, z;
    std::cout << "Введіть три дійсних числа (x y z): ";
    std::cin >> x >> y >> z;
    numbers_in_systems(x, y, z);

    return 0;
}
