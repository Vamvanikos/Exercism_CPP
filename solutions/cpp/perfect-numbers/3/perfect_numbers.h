#pragma once

namespace perfect_numbers {

enum class classification {
    perfect,
    abundant,
    deficient
};
    
classification classify(int num);
    
}  // namespace perfect_numbers
