#include <catch2/catch.hpp>
#include <vector>
class Fibanocci_calculator {

public:
    std::vector<unsigned int> cache;

    unsigned int naive(unsigned int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return naive(n-1) + nth(n-2);
    }
    unsigned int nth(unsigned int n) {
        cache.clear();
        cache.resize(n+1);
        return memo(n);
    }
    unsigned int memo(unsigned int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (cache[n] != 0) {
            return cache[n];
        }
        cache[n] = memo(n-1) + memo(n-2);
        return cache[n];
    }
};





TEST_CASE("computes fibanocci numbers", "[fibanocci]"){
    Fibanocci_calculator fib;
    REQUIRE(fib.nth(0) == 0);
    REQUIRE(fib.nth(1) == 1);
    REQUIRE(fib.nth(2) == 1);
    REQUIRE(fib.nth(3) == 2);
    REQUIRE(fib.nth(4) == 3);
    REQUIRE(fib.nth(5) == 5);
    REQUIRE(fib.nth(6) == 8);
    REQUIRE(fib.nth(23) == 28657);
    REQUIRE(fib.nth(45) == 1134903170);
    //naive recursive approach 9.7s
    //DP 0.01s
}