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
            { { 1 }, { 1 }},
            { { 2 }, { 2 }},
            { { -5 }, { -5 }},
        };

        size_t i = 0;
        for (scaffolding::numbers const& test : tests)
        {
            test.verify(i++);
        }
    }

}