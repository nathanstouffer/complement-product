#pragma once

#include <vector>

#include <stf/stf.hpp>

namespace alg
{

    std::vector<float> complement_product(std::vector<float> const& input);

    std::vector<stff::mtx2> complement_product(std::vector<stff::mtx2> const& input);

}