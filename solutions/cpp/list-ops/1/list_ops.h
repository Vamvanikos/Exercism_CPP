#pragma once
#include <vector>
#include <utility>

namespace list_ops {

template <typename T>
void append(std::vector<T>& left, const std::vector<T>& right)
{
    left.insert(left.cend(), right.cbegin(), right.cend());
}

template <typename T>
std::vector<T> concat(const std::vector<std::vector<T>>& listSeries)
{
    std::vector<T> result;
    std::size_t totalSize = 0;
    for (const auto& list : listSeries)
        totalSize += list.size();
    result.reserve(totalSize);
    
    for (const auto& list : listSeries)
        append(result, list);

    return result;
}

template <typename T, typename Predicate>
std::vector<T> filter(const std::vector<T>& list, Predicate lambda)
{
    std::vector<T> result;
    result.reserve(list.size());

    for (const T& item : list)
    {
        if (lambda(item))
            result.push_back(item);
    }

    return result;
}

template <typename T>
std::size_t length(const std::vector<T>& list)
{
    return list.size();
}

template <typename T, typename funcRet>
auto map(const std::vector<T>& list, funcRet lambda) -> std::vector<decltype(lambda(std::declval<T>()))>
{
    using R = decltype(lambda(std::declval<T>()));
    std::vector<R> result;
    result.reserve(list.size());

    for (const auto& item : list)
    {
        result.push_back(lambda(item));
    }

    return result;
}

template <typename T, typename R, typename funcRet>
R foldl(const std::vector<T>& list, R accum, funcRet lambda)
{
    R result = accum;
    
    for (const auto& item : list)
    {
        result = lambda(result, item);
    }

    return result;
}

template <typename T, typename R, typename funcRet>
R foldr(const std::vector<T>& list, R accum, funcRet lambda)
{
    R result = accum;

    for (auto it = list.crbegin(); it != list.crend(); ++it)
    {
        result = lambda(result, *it);
    }

    return result;
}
    
template <typename T>
std::vector<T> reverse(const std::vector<T>& list)
{
    return std::vector<T>(list.crbegin(), list.crend());
}

}  // namespace list_ops
