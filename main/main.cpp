#include "Node.hpp"
#include "Independent.hpp"
#include "Utils.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<Node *>> groups;
    std::vector<std::pair<unsigned, unsigned>> edges({
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, 
        {1, 5}, {1, 6}, 
        {2, 6},
        {5, 8}, 
        {6, 5}, 
        {4, 7}, 
    });
    Node *root =  generateDAG(9, edges);
    unsigned num_groups = getIndependentGroups(root, groups);
    std::cout << "GROUPS: " << num_groups << std::endl;
    int i = 0;
    for (auto &group : groups)
    {
        std::cout << "GROUP #" << i++ << ": ";
        for (auto &node : group)
        {
            std::cout << node->getName() << " ";
        }
        std::cout << std::endl;
    }
    freeDAG(root);
    return 0;
}