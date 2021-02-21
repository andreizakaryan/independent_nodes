#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node
{
public:
    Node(const std::string &name);
    const std::string &getName() const;
    const std::vector<Node *> &getNextNodes() const;
    void addNextNode(Node *node);

private:
    std::string name_;
    std::vector<Node *> next_nodes_;
};

#endif //NODE_HPP