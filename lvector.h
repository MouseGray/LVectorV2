#ifndef LVECTOR_H
#define LVECTOR_H

#include <vector>
#include <stdexcept>

template<typename Ty>
class LVector
{
public:
    LVector()
    {
        m_data.reserve(5);
    }
    void append(const Ty& val)
    {
        _append(val);
        ++m_pointer;
    }
    void append(Ty&& val)
    {
        _append(std::forward<Ty>(val));
        ++m_pointer;
    }
    void quietAppend(const Ty& val)
    {
        _append(val);
    }
    void quietAppend(Ty&& val)
    {
        _append(std::forward<Ty>(val));
    }
    int size() const noexcept
    {
        return static_cast<int>(m_data.size());
    }
    int isEmpty() const noexcept
    {
        return m_data.empty();
    }
    int pointer() const noexcept
    {
        return m_pointer;
    }
    std::pair<int, int> next() noexcept
    {
        if (isEmpty()) return { m_pointer, m_pointer };
        auto old = m_pointer;
        m_pointer = (m_pointer + 1) % size();
        return { old, m_pointer };
    }
    std::pair<int, int> prev() noexcept
    {
        if (isEmpty()) return { m_pointer, m_pointer };
        auto old = m_pointer;
        m_pointer = (m_pointer + size() - 1) % size();
        return { old, m_pointer };
    }
    Ty& operator[](int pos) {
        if (0 <= pos && pos < size())
            return m_data[pos];
        throw std::out_of_range("LVector subscript out of range");
    }
    const Ty& operator[](int pos) const {
        if (0 <= pos && pos < size())
            return m_data[pos];
        throw std::out_of_range("LVector subscript out of range");
    }
    Ty& current() {
        return operator[](m_pointer);
    }
    const Ty& current() const {
        return operator[](m_pointer);
    }
private:
    template<typename Ex>
    void _append(Ex&& val)
    {
        m_data.emplace_back(std::forward<Ex>(val));
    }
    std::vector<Ty> m_data;
    int m_pointer = -1;
};

#endif // LVECTOR_H
