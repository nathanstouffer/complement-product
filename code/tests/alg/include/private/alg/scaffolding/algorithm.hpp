#pragma once

#include <gtest/gtest.h>

#include <alg/algorithm.hpp>

namespace alg::scaffolding
{

    struct numbers
    {
        std::vector<float> input;
        std::vector<float> expected;

        void verify(std::size_t const i) const
        {
            std::vector<float> result = complement_product(input);
            ASSERT_EQ(expected, result) << "Failed to correctly compute " << i << "th complement product";
        }

    };

    struct matrices
    {
        std::vector<stff::mtx2> input;
        std::vector<stff::mtx2> expected;

        void verify(std::size_t const i) const
        {
            std::vector<stff::mtx2> result = complement_product(input);
            ASSERT_EQ(expected, result) << "Failed to correctly compute " << i << "th complement product";
        }

    };

} // alg::scaffolding