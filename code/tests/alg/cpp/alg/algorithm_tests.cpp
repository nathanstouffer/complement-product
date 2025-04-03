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

}