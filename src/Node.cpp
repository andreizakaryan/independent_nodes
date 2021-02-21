#include "../include/Node.hpp"

Node::Node(std::string const &name)
{
    name_ = name;
}

const std::string &Node::getName() const
{
    return name_;
}

const std::vector<Node *> &Node::getNextNodes() const
{
    return next_nodes_;
}

void Node::addNextNode(Node *node)
{
    next_nodes_.push_back(node);
}
