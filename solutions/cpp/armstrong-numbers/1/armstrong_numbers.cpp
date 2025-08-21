#include "armstrong_numbers.h"
#include <iostream>
#include <cmath>

namespace armstrong_numbers {

// TODO: add your solution here
    bool is_armstrong_number(int num)
    {
        int count = 1;
        num = abs(num);
        int sum = 0 - num;
        
        if (num != 0)
        {
            count += std::log10(num);
            std::cout << count << std::endl;
        }
        else
        {
            return true;
        }

        for (int i = 0; i < count; i++)
        {
            sum += pow(num%10, count);
            num /= 10;
        }

        return (sum == 0);
    }

}  // namespace armstrong_numbers
