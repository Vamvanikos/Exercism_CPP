#include "largest_series_product.h"
#include <stdexcept>
#include <cctype>

namespace largest_series_product {

// TODO: add your solution here
int largest_product(const std::string& input, const int span)
{
    if (input.empty())
        throw std::domain_error("Input sequence is empty.");
    if (span < 1)
        throw std::domain_error("Span size can't be zero.");
    if (static_cast<int>(input.size()) < span)
        throw std::domain_error("Input sequence size can't be smaller than span size.");
    for (const char ch : input)
    {
        if (!std::isdigit(ch))
            throw std::domain_error("Input sequence must include only numerical digits.");
    }

    int result = 0;
    for (int i = 0; i < static_cast<int>(input.size()) - span + 1; ++i)
    {
        int product = 1;
        for (int s = 0; s < span; ++s)
            product *= input[i + s] - '0';
        result = std::max(result, product);
    }

    return result;
}

}  // namespace largest_series_product