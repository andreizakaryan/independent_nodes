#include <boost/test/unit_test.hpp>

#include "Node.hpp"
#include "Utils.hpp"
#include "Independent.hpp"

BOOST_AUTO_TEST_SUITE(independent_suite)

    BOOST_AUTO_TEST_CASE(corner_test)
    {
        std::vector<std::vector<Node *>> groups;
        Node* root = new Node("ROOT");
        unsigned num_groups = getIndependentGroups(root, groups);
        BOOST_CHECK_EQUAL(num_groups, 1);
        BOOST_CHECK_EQUAL(groups[0].size(), 1);
        BOOST_CHECK_EQUAL(groups[0][0]->getName(), "ROOT");
        delete root;
    }

    BOOST_AUTO_TEST_CASE(dag_test)
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
        std::vector<std::unordered_set<std::string>> result({
            {"v7", "v3", "v8"}, 
            {"v4", "v5"}, 
            {"v6"}, 
            {"v2", "v1"}, 
            {"ROOT"}
        });
        Node *root = generateDAG(9, edges);
        unsigned num_groups = getIndependentGroups(root, groups);
        BOOST_CHECK_EQUAL(num_groups, 5);
        int i = 0;
        for (auto &group : groups)
        {
            BOOST_CHECK_EQUAL(group.size(), result[i].size());
            std::unordered_set<std::string> names;
            for (auto &node : group)
            {
                names.insert(node->getName());
            }
            BOOST_CHECK(names == result[i]);
            i++;
        }
        freeDAG(root);
    }

BOOST_AUTO_TEST_SUITE_END()