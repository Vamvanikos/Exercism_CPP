#include "difference_of_squares.h"

namespace difference_of_squares {

// TODO: add your solution here
unsigned long square_of_sum(unsigned int N)
{
    /*
    unsigned long sum = 0;
    
    for (unsigned int i = 1; i <= N; i++)
    {
        sum += i;
    }
    */

    unsigned long sum = N * (N + 1) / 2;

    return (sum*sum);
}

unsigned long sum_of_squares(unsigned int N)
{
    /*
    unsigned long sum = 0;

    for (unsigned int i = 1; i <= N; i++)
    {
        sum += i*i;
    }

    return sum;
    */

    return (N * (N + 1) * (2 * N + 1) / 6);
}

unsigned long difference(unsigned int N)
{
    return (square_of_sum(N) - sum_of_squares(N));
}

}  // namespace difference_of_squares
