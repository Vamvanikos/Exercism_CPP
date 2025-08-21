#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <cstddef>
#include <vector>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    explicit circular_buffer(std::size_t capacity);

    T read();
    void write(const T& value);
    void overwrite(const T& value);
    void clear();

private:
    std::size_t m_capacity;
    std::size_t m_size;
    std::vector<T> m_buffer;
    std::size_t m_head;
    std::size_t m_tail;
};

}  // namespace circular_buffer

#endif  // CIRCULAR_BUFFER_H