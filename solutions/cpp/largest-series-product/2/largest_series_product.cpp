#include "largest_series_product.h"
#include <stdexcept>
#include <algorithm>

namespace largest_series_product {

bool invalidInput(const std::string& input)
{
    auto invalidDigit = [](char digit)
        { return !std::isdigit(static_cast<unsigned char>(digit)); };

    return std::any_of(input.begin(), input.end(), invalidDigit);
}
    
int largest_product(const std::string& input, int span)
{
    const size_t inputSize = input.size();
    
    if (span <= 0)
        throw std::domain_error("Span size must be positive.");
    if (inputSize < static_cast<size_t>(span))
        throw std::domain_error("Input string size must be larger than given span.");
    if (invalidInput(input))
        throw std::domain_error("Input string must include only digits.");
    
    int largest_prod = 0;
    for (size_t i = 0; i < inputSize - span + 1; ++i)
    {
        int prod = 1;
        for (int s = 0; s < span; ++s)
            prod *= input[i + s] - '0';
        
        largest_prod = std::max(largest_prod, prod);
    }

    return largest_prod;
}

}  // namespace largest_series_product