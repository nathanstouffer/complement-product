#include "alg/algorithm.hpp"

namespace alg
{

    std::vector<float> complement_product(std::vector<float> const& input)
    {
        if (input.empty())
        {
            return {};
        }
        else if (input.size() == 1)
        {
            return { 1 };
        }
        else
        {
            std::vector<float> result;
            result.reserve(input.size());
    
            for (std::size_t i = 0; i < input.size(); ++i)
            {
                float product = 1.f;
                for (std::size_t j = 0; j < input.size(); ++j)
                {
                    if (i != j)
                    {
                        product *= input[j];
                    }
                }
                result.push_back(product);
            }
    
            return result;
        }
    }

}