#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H
#include <string>

namespace isbn_verifier {

inline constexpr int NUM_DIGITS_MINUS_10TH = 9;

bool is_valid(const std::string& isbnInput);

}  // namespace isbn_verifier

#endif  // ISBN_VERIFIER_H