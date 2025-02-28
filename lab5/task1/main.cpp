#include "solution.cpp"

int main() {
    binary_int a = 1024;
    std::cout << a + a - 1 << ' ' << a * 10 << ' ' << '\n' << a << '\n';

    std::pair<binary_int, binary_int> res = ((binary_int)((1 << 31))).split();

    std::cout << res.first << ' ' << res.second << std::endl;

    return 0;
}