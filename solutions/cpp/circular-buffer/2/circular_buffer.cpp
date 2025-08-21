#include "circular_buffer.h"
#include <stdexcept>
#include <string>

namespace circular_buffer {

template <typename T>
circular_buffer<T>::circular_buffer(std::size_t capacity)
    : m_capacity(capacity), m_size(0), m_buffer(capacity), m_head(0), m_tail(0) {}

template <typename T>
T circular_buffer<T>::read() {
    if (m_size == 0) {
        throw std::domain_error("Can't read value. Circular buffer is empty.");
    }

    T value = m_buffer[m_tail];
    m_tail = (m_tail + 1) % m_capacity;
    --m_size;

    return value;
}

template <typename T>
void circular_buffer<T>::write(const T& value) {
    if (m_size == m_capacity) {
        throw std::domain_error("Can't write value. Circular buffer is full.");
    }

    m_buffer[m_head] = value;
    m_head = (m_head + 1) % m_capacity;
    ++m_size;
}

template <typename T>
void circular_buffer<T>::overwrite(const T& value) {
    if (m_size == m_capacity)
    {
        m_buffer[m_head] = value;
        m_head = (m_head + 1) % m_capacity;
        m_tail = (m_tail + 1) % m_capacity;
    }
    else
        write(value);
}

template <typename T>
void circular_buffer<T>::clear() {
    m_size = 0;
    m_head = 0;
    m_tail = 0;
}

template class ::circular_buffer::circular_buffer<int>;
template class ::circular_buffer::circular_buffer<std::string>;
    
}  // namespace circular_buffer