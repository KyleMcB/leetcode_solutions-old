#include <catch2/catch.hpp>
#include <vector>

class Choose_calculator {
    std::vector<std::vector<unsigned int>> cache;
public:
    unsigned int naive(unsigned int n, unsigned int k) {
        if (n == k || k == 0) {
            return 1;
        }
        return naive(n-1, k-1) + choose(n-1, k);
    }
    unsigned int choose(unsigned int n, unsigned int k) {
        cache.clear();
        cache = std::vector<std::vector<unsigned int>>(n+1,std::vector<unsigned int>(k+1));
        return memo(n,k);
    }
    unsigned int memo(unsigned int n, unsigned int k) {
        if (n == k || k == 0) {
            return 1;
        }
        if (cache[n][k] != 0) {
            return cache[n][k];
        }
        cache[n][k]= memo(n-1, k-1) + memo(n-1, k);
        return cache[n][k];
    }
};

TEST_CASE("computer choose notation recusively", "[choose]") {
    Choose_calculator ch;
    REQUIRE(ch.choose(5,5) == 1);
    REQUIRE(ch.choose(5,0) == 1);
    // REQUIRE(ch.choose(5,5) == 1);
    // REQUIRE(ch.choose(5,5) == 1);
    REQUIRE(ch.choose(100,5) == 75287520);
    REQUIRE(ch.choose(190,5) == 1956800538);
    //11.48s naive recursive
    //0.00user DP memo
}