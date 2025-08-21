#include "triangle.h"
#include <stdexcept>

namespace triangle {

// TODO: add your solution here
flavor kind(float side1, float side2, float side3)
{
    flavor ret;
    if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0)       ||
        (side1 + side2 < side3) || (side1 + side3 < side2) ||
        (side2 + side3 < side1)) { throw std::domain_error("This is not a Triangle"); } 
    else if ((side1 == side2) && (side2 == side3)) { ret = flavor::equilateral; }
    else if((side1 == side2) || (side1 == side3) ||
            (side2 == side3)) { ret = flavor::isosceles; }
    else { ret = flavor::scalene; }

    return ret;
}

}  // namespace triangle
