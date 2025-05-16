#pragma once

#ifndef __SDK250_H__
#define __SDK250_H__

#include <vector>
#include <algorithm>
#include <functional>

namespace sdk250
{
    template <typename K, typename V>
    class Map
    {
        private:
            std::vector<std::pair<K, V>> groups_;
            std::function<bool (K, K)> comp_;

        public:
            Map(decltype(comp_) comp, std::size_t size = 100) noexcept : comp_(comp)
            {
                groups_.reserve(size);
            }
            ~Map(void) noexcept
            {

            }
            V &operator[](K k) noexcept
            {
                auto it = find(k);

                if (it != groups_.end())
                    if (it->first == k)
                        return it->second;

                return groups_.insert(it, {k, V{}})->second;
            }
            typename decltype(groups_)::iterator erase(const K &v) noexcept
            {
                auto it = find(v);
                if (it == end())
                    return it;

                return groups_.erase(it);
            }
            typename decltype(groups_)::iterator erase(
                typename decltype(groups_)::iterator &it
            ) noexcept
            {
                return groups_.erase(it);
            }
            typename decltype(groups_)::iterator begin(void) noexcept
            {
                return groups_.begin();
            }
            typename decltype(groups_)::iterator end(void) noexcept
            {
                return groups_.end();
            }
            typename decltype(groups_)::iterator find(const K &k) noexcept
            {
                return std::lower_bound(
                    groups_.begin(),
                    groups_.end(),
                    k,
                    [this](const std::pair<K, V> &p, const K &d)
                    {
                        return this->comp_(p.first, d);
                    }
                );
            }
            std::size_t size(void) const noexcept
            {
                return groups_.size();
            }
    };
}

#endif // __SDK250_H__
