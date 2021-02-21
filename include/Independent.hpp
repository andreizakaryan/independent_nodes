#ifndef INDEPENDENT_HPP
#define INDEPENDENT_HPP

#include "Node.hpp"

#include <vector>
#include <unordered_map>

unsigned getIndependentGroups(Node *root, std::vector<std::vector<Node *>> &groups);
unsigned getLevel(Node *node, std::unordered_map<Node *, unsigned> &levels);

#endif // INDEPENDENT_HPP