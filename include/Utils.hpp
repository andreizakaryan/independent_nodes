#ifndef UTILS_HPP
#define UTILS_HPP

#include "Node.hpp"
#include <unordered_set>
#include <vector>

void getNodes(Node *node, std::unordered_set<Node *> &nodes);
void freeDAG(Node *root);
Node* generateDAG(unsigned vetexes, std::vector<std::pair<unsigned, unsigned>>& edges);

#endif //UTILS_HPP