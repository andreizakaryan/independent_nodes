#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node
{
public:
    Node(std::string const &name);
    const std::string &getName() const;
    const std::vector<Node *> &getNextNodes() const;
    void addNextNode(Node *node);

private:
    std::string name_;
    std::vector<Node *> next_nodes_;
};

#endif //NODE_HPP