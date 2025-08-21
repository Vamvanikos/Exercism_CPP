#include "triangle.h"
#include <stdexcept>

namespace triangle {

// TODO: add your solution here
flavor kind(double a, double b, double c)
{
    flavor ret = flavor::scalene;
    if (a == 0 || b == 0 || c == 0)
        throw std::domain_error("invalid arguments");
    if (a + b < c || b + c < a || a + c < b)
        throw std::domain_error("not a triangle");
    if (a == b || b == c || a == c)
        ret = flavor::isosceles;
    if (a == b && b == c)
        ret = flavor::equilateral;
    
    return ret;
}

}  // namespace triangle
