#include "../include/Utils.hpp"

#include <unordered_set>

void freeDAG(Node *root)
{
    std::unordered_set<Node *> nodes;
    getNodes(root, nodes);
    for (auto &node : nodes)
    {
        delete node;
    }
}

void getNodes(Node *node, std::unordered_set<Node *> &nodes)
{
    auto it = nodes.find(node);
    if (it != nodes.end())
    {
        return;
    }
    nodes.insert(node);
    for (auto &child : node->getNextNodes())
    {
        getNodes(child, nodes);
    }
}

Node *generateDAG(unsigned vertexes, std::vector<std::pair<unsigned, unsigned>> &edges)
{
    if (vertexes <= 0)
    {
        return nullptr;
    }
    std::vector<Node *> nodes;
    for (unsigned i = 0; i < vertexes; i++)
    {
        if (i == 0)
        {
            nodes.push_back(new Node("ROOT"));
        }
        else
        {
            nodes.push_back(new Node("v" + std::to_string(i)));
        }
    }
    for (auto &edge : edges)
    {
        nodes[edge.first]->addNextNode(nodes[edge.second]);
    }
    return nodes[0];
}