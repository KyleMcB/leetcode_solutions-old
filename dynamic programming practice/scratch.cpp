#include <vector>
#include <iostream>
int main() {
    std::vector<int> hi;
    hi.push_back(3);
    std::cout << hi[100] << '\n';
    return 0;
}