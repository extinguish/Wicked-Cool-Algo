#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode * left_child;
    TreeNode * right_child;
};

void breadth_first_search(TreeNode * root_node) {
    if (root_node == nullptr) {
        return;
    }
    std::cout << "to dump out the tree -->" << std::endl;
    std::vector<int> tree_dump_vec;
    std::queue<TreeNode *> node_queue;
    node_queue.push(root_node);
    while (!node_queue.empty()) {
        // std::cout << "--->" << std::endl;
        TreeNode *cur_node = node_queue.front();
        // std::cout << " to handle node -> " << cur_node->val;
        node_queue.pop();
        tree_dump_vec.push_back(cur_node->val);
        std::cout << cur_node->val << "\t";

        if (cur_node->left_child != nullptr) {
            node_queue.push(cur_node->left_child);
        }

        if (cur_node->right_child != nullptr) {
            node_queue.push(cur_node->right_child);
        }
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    // to dump out the following binary tree in breadth first search
    //                1
    //             2       3
    //          4    5   6     7
    //        8
    // we need to dump out the tree with layer
    TreeNode root;
    root.val = 1;
    TreeNode node_2;
    node_2.val = 2;
    TreeNode node_3;
    node_3.val = 3;
    TreeNode node_4;
    node_4.val = 4;
    TreeNode node_5;
    node_5.val = 5;
    TreeNode node_6;
    node_6.val = 6;
    TreeNode node_7;
    node_7.val = 7;
    TreeNode node_8;
    node_8.val = 8;

    root.left_child = &node_2;
    node_2.left_child = &node_4;
    node_2.right_child = &node_5;
    root.right_child = &node_3;
    node_3.left_child = &node_6;
    node_3.right_child = &node_7;

    node_4.left_child = &node_8;
    node_4.right_child = nullptr;

    node_5.left_child = nullptr;
    node_5.right_child = nullptr;

    node_6.left_child = nullptr;
    node_6.right_child = nullptr;

    node_7.left_child = nullptr;
    node_7.right_child = nullptr;

    node_8.left_child = nullptr;
    node_8.right_child = nullptr;

    breadth_first_search(&root);

    return 0;
}