#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <string>
#include <vector>

// the 'using' keyword create aliases and improves the code readability
using StringFloatPair   = std::pair< std::string, float>;
using StringFloatVector = std::vector<StringFloatPair>;

bool fcomp(const StringFloatPair& p, const StringFloatPair& q);
void testVector();

#endif // TEST_VECTOR_H