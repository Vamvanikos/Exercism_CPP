#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <cstddef>
#include <vector>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
class circular_buffer {
public:
circular_buffer(std::size_t capacity);
    
T read();
void write(T value);
void overwrite(T value);
void clear();

private:
std::size_t m_capacity;
std::vector<T> m_buffer;
std::size_t m_head;
std::size_t m_tail;
std::size_t m_size;
    
};

}  // namespace circular_buffer

#endif  // CIRCULAR_BUFFER_H