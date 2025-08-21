#include "circular_buffer.h"
#include <stdexcept>
#include <string>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
circular_buffer<T>::circular_buffer(std::size_t capacity) : m_capacity(capacity), m_buffer(m_capacity), m_head(0), m_tail(0), m_size(0) {}

template <typename T>
T circular_buffer<T>::read()
{
    if (m_size == 0)
        throw std::domain_error("Can't read value. Circular buffer is empty.");

    --m_size;
    if (m_tail != m_capacity - 1)
        return m_buffer[m_tail++];
    else
    {
        m_tail = 0;
        return m_buffer[m_capacity - 1];
    }
}

template <typename T>
void circular_buffer<T>::write(T value)
{
    if (m_size == m_capacity)
        throw std::domain_error("Can't write value. Circular buffer is full.");

    overwrite(value);
}

template <typename T>
void circular_buffer<T>::overwrite(T value)
{
    if (m_head != m_capacity - 1)
        m_buffer[m_head++] = value;
    else
    {
        m_head = 0;
        m_buffer[m_capacity - 1] = value;
    }

    if (m_size < m_capacity)
        ++m_size;
    else
        if (m_tail != m_capacity - 1)
            ++m_tail;
        else
            m_tail = 0;
}

template <typename T>
void circular_buffer<T>::clear()
{
    m_head = m_tail = m_size = 0;
}

template class ::circular_buffer::circular_buffer<int>;
template class ::circular_buffer::circular_buffer<std::string>;

}  // namespace circular_buffer