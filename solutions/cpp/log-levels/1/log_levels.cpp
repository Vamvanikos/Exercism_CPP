#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    int delimiter = line.find(":");
    
    return line.substr(delimiter + 2);
}

std::string log_level(std::string line) {
    int beg = line.find("[") + 1;
    int end = line.find("]") - 1;
    
    return line.substr(beg, end);
    // return the log level
}

std::string reformat(std::string line) {
    // return the reformatted message
    
    return (message(line) + " (" + log_level(line)) + ")";
}
}  // namespace log_line
