#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned int square_of_sum(unsigned int num)
{
    unsigned int sum = num * (num + 1) / 2;
    return sum * sum;

}
    
unsigned int sum_of_squares(unsigned int num)
{
    return num * (num + 1) * (2 * num + 1) / 6;
}
    
unsigned int difference(unsigned int num)
{
    return square_of_sum(num) - sum_of_squares(num);
}

}  // namespace difference_of_squares
