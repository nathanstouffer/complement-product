#include "alg/algorithm.hpp"

#include <algorithm>
#include <functional>
#include <numeric>

namespace
{

    // an internal function that computes the complement product for a particular index
    float compute(std::vector<float> const& input, std::size_t ignore)
    {
        float product = 1.f;
        for (std::size_t i = 0; i < input.size(); ++i)
        {
            if (ignore != i)
            {
                product *= input[i];
            }
        }
        return product;
    }
}

namespace alg
{

    std::vector<float> complement_product(std::vector<float> const& input)
    {
        if (input.empty())
        {
            return {};
        }
        else
        {
            std::size_t zero_count = std::count(input.begin(), input.end(), 0.f);
            if (zero_count > 1)         // if there is more than one zero then all products are zero
            {
                return std::vector<float>(input.size(), 0.f);
            }
            else if (zero_count == 1)   // if there is exactly one zero then only one product is important
            {
                std::vector<float> result(input.size(), 0);
                for (std::size_t i = 0; i < input.size(); ++i)
                {
                    if (input[i] == 0)
                    {
                        result[i] = compute(input, i);
                    }
                }
                return result;
            }
            else                        // there are no zeros, compute the product and then just divide by the relevant value
            {
                float product = std::accumulate(input.begin(), input.end(), 1.f, std::multiplies<float>());
                std::vector<float> result;
                result.reserve(input.size());
                for (std::size_t i = 0; i < input.size(); ++i)
                {
                    result.push_back(product / input[i]);
                }
                return result;
            }
        }
    }

}