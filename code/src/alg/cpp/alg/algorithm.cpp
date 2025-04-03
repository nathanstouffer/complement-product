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

    // an internal function that computes the complement product for a particular index
    stff::mtx2 compute(std::vector<stff::mtx2> const& input, std::size_t ignore)
    {
        stff::mtx2 product = stff::mtx2();
        for (std::size_t i = 0; i < input.size(); ++i)
        {
            if (ignore != i)
            {
                product *= input[i];
            }
        }
        return product;
    }

    std::vector<stff::mtx2> brute_force(std::vector<stff::mtx2> const& input)
    {
        if (input.empty())
        {
            return {};
        }
        else if (input.size() == 1)
        {
            return { stff::mtx2() };
        }
        else
        {
            std::vector<stff::mtx2> result; result.reserve(input.size());
            for (std::size_t i = 0; i < input.size(); ++i)
            {
                result.push_back(compute(input, i));
            }
            return result;
        }
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
                std::vector<float> result; result.reserve(input.size());
                for (std::size_t i = 0; i < input.size(); ++i)
                {
                    result.push_back(product / input[i]);
                }
                return result;
            }
        }
    }

    std::vector<stff::mtx2> complement_product(std::vector<stff::mtx2> const& input)
    {
        std::size_t singular_count = std::count_if(input.begin(), input.end(), [](stff::mtx2 const& mtx) { return !mtx.invertible(); });
        if (singular_count > 0)     // if any matrices are singular, then we brute force
        {
            return brute_force(input);
        }
        else                        // all matrices are invertible, so we can use a clever trick to keep track of partial products
        {
            // set up the L matrix as the identity and the R matrix as the complete product
            stff::mtx2 L = stff::mtx2();
            stff::mtx2 R = stff::mtx2();
            for (stff::mtx2 const& M : input) { R *= M; }

            std::vector<stff::mtx2> result; result.reserve(input.size());
            for (std::size_t i = 0; i < input.size(); ++i)
            {
                // grab a reference to the relevant matrix and compute the inverse
                stff::mtx2 const& M = input[i];
                stff::mtx2 inv = M.inverted();

                // compute the complement product
                result.push_back(L * inv * R);

                // update L and R for the next iteration
                L *= M;
                R = inv * R;
            }
            return result;
        }
    }

}