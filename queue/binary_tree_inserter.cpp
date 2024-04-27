#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left_child;
    TreeNode *right_child;
};

void dump_binar_tree_via_bfs(TreeNode *root) {
    // dump out the tree with bfs method
    std::queue<TreeNode *> tree_queue;
    tree_queue.push(root);

    while (!tree_queue.empty()) {
        TreeNode *node = tree_queue.front();
        std::cout << node->val << "\t";
        tree_queue.pop();

        if (node->left_child != nullptr) {
            tree_queue.push(node->left_child);
        }
        if (node->right_child != nullptr) {
            tree_queue.push(node->right_child);
        }
    }
    std::cout << std::endl;

}

void insert_to_binary_tree(TreeNode *root, TreeNode *new_node) {
    if (new_node == nullptr) {
        std::cout << "the node to insert are null" << std::endl;
        return;
    }

    std::cout << "start to perform insert node of " << new_node->val << std::endl;
    if (root == nullptr) {
        std::cout << "the tree are empty" << std::endl;
        return;
    }

    std::queue<TreeNode *> tree_queue;
    tree_queue.push(root);
    while (!tree_queue.empty()) {
        TreeNode *cur_node = tree_queue.front();
        tree_queue.pop();

        if (cur_node->left_child == nullptr) {
            // we need to insert the new node as left child of current node
            cur_node->left_child = new_node;
            break;
        } else {
            tree_queue.push(cur_node->left_child);
        }

        if (cur_node->right_child == nullptr) {
            cur_node->right_child = new_node;
            break;
        } else {
            tree_queue.push(cur_node->right_child);
        }
    }
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

    std::cout << "before insert, the tree structure are " << std::endl;

    dump_binar_tree_via_bfs(&root);
    TreeNode new_node;
    new_node.val = 9;
    new_node.left_child = nullptr;
    new_node.right_child = nullptr;
    insert_to_binary_tree(&root, &new_node);
    std::cout << "after insert node 9, the tree structure are " << std::endl;
    dump_binar_tree_via_bfs(&root);

    return 0;

}