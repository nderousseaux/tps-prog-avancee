#ifndef TEST_MAP_H
#define TEST_MAP_H

#include <string>
#include <map>

// the 'using' keyword create aliases and improves the code readability
using StringFloatPair       = std::pair< std::string, float>;
using MapCustomPair         = std::map< int, StringFloatPair>;
using MultimapCustomPair    = std::multimap< int, StringFloatPair>;

void testMap();
void testMultimap();

#endif // TEST_MAP_H