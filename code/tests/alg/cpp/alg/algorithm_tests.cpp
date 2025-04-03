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
            { { 2 }, { 1 }},
            { { 1, 0 }, { 0, 1 }},
            { { 0, 1, 2 }, { 2, 0, 0 }},
        };

        std::size_t i = 0;
        for (scaffolding::numbers const& test : tests)
        {
            test.verify(i++);
        }
    }

}