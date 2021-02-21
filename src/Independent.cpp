#include "../include/Independent.hpp"
#include <vector>
#include <unordered_map>

unsigned getIndependentGroups(Node *root, std::vector<std::vector<Node *>> &groups)
{
    std::unordered_map<Node *, unsigned> levels;
    unsigned num_groups = getLevel(root, levels) + 1;
    groups.clear();
    groups.resize(num_groups);
    for (auto &elem : levels)
    {
        groups[elem.second].push_back(elem.first);
    }
    return num_groups;
}

unsigned getLevel(Node *node, std::unordered_map<Node *, unsigned> &levels)
{
    unsigned level = 0;
    if (node->getNextNodes().size() == 0)
    {
        levels[node] = level;
        return level;
    }
    for (auto &child : node->getNextNodes())
    {
        unsigned child_level = 0;
        auto it = levels.find(child);
        if (it != levels.end())
        {
            child_level = it->second;
        }
        else
        {
            child_level = getLevel(child, levels);
        }
        if (child_level > level)
        {
            level = child_level;
        }
    }
    level++;
    levels[node] = level;
    return level;
}