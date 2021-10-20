#include <catch2/catch.hpp>


TEST_CASE("fibanocci numbers calculated" "[fibanocci]") {
    Fibcalculator fib;
    REQUIRE(fib.nth(0) == 0);
}