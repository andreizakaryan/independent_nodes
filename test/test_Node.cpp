#include <boost/test/unit_test.hpp>

#include "../include/Node.hpp"
#include "../include/Utils.hpp"

BOOST_AUTO_TEST_SUITE(node_suite)

    BOOST_AUTO_TEST_CASE(constructor_test)
    {
        Node *node = new Node("ROOT");
        BOOST_CHECK_EQUAL(node->getName(), "ROOT");
        delete node;
    }

    BOOST_AUTO_TEST_CASE(addnode_test)
    {
        Node *root = new Node("ROOT");
        for (unsigned i = 0; i < 10; i++)
        {
            root->addNextNode(new Node("v" + std::to_string(i)));
        }
        BOOST_CHECK_EQUAL(root->getNextNodes().size(), 10);
        freeDAG(root);
    }

BOOST_AUTO_TEST_SUITE_END()