#include <vector>

#include <gtest/gtest.h>

#include <alg/algorithm.hpp>

#include "alg/scaffolding/algorithm.hpp"

namespace alg
{

    TEST(complement_product, numbers)
    {
        std::vector<scaffolding::numbers> tests = 
        {
            // test cases where there is just one value => return the empty product
            { { 1 }, { 1 }},
            { { 2 }, { 1 }},
            // test cases with two values should swap positions
            { { 1, 0 }, { 0, 1 }},
            // test cases with a single zero should only have on product that matters
            { { 0, 1, 2 }, { 2, 0, 0 }},
            // test cases with two zeros should return all zeros
            { { 0, 6, 2, 0 }, { 0, 0, 0, 0 }},
            // general test cases
            { { 1, 6, 2, 5 }, { 60, 10, 30, 12 }},
        };

        std::size_t i = 0;
        for (scaffolding::numbers const& test : tests)
        {
            test.verify(i++);
        }
    }

    inline stff::mtx2 rot(float theta) { return stf::math::rotate<float>(theta); }

    TEST(complement_product, matrices)
    {
        std::vector<scaffolding::matrices> tests = 
        {
            // test cases where there is just one value => return the identity matrix
            { { stff::mtx2() }, { stff::mtx2() } },
            { { stff::mtx2(4) }, { stff::mtx2() } },
            // test cases with two values should swap positions
            { { stff::mtx2(1), stff::mtx2() }, { stff::mtx2(), stff::mtx2(1) } },
            { { stff::mtx2(5), stff::mtx2(1) }, { stff::mtx2(1), stff::mtx2(5) } },
            { { stff::mtx2(stff::vec4(1, 0, 0, 5)), rot(3) }, { rot(3), stff::mtx2(stff::vec4(1, 0, 0, 5)) } },
            // general test cases
            { { rot(1), rot(2), rot(3), rot(4) }, { rot(9), rot(8), rot(7), rot(6) } },
            { { rot(1), rot(-2), rot(3), rot(-4) }, { rot(-3), rot(0), rot(-5), rot(2) } },
        };

        std::size_t i = 0;
        for (scaffolding::matrices const& test : tests)
        {
            test.verify(i++);
        }
    }

}