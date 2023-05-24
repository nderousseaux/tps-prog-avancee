#ifndef TEST_UNORDERED_CONTAINERS_H
#define TEST_UNORDERED_CONTAINERS_H

#include <string>
#include <unordered_set>

using StringFloatPair = std::pair< std::string, float>;

void insertInSetAndCheck(std::unordered_set<std::string>&   set,
                         const std::string&                 value);

void testUnorderedSet();

struct StringFloatPairHash
{
    std::hash<std::string> hs_;
    inline size_t operator()(const StringFloatPair& p) const
    {
        return hs_(p.first);
    }
};

void testUnorderedSetHashMap();

#endif // TEST_UNORDERED_CONTAINERS_H