#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left_child;
    TreeNode *right_child;
};

void pre_order_dfs(std::vector<TreeNode *> &node_vec, TreeNode *root) {
    if (root != nullptr) {
        node_vec.push_back(root);
        pre_order_dfs(node_vec, root->left_child);
        pre_order_dfs(node_vec, root->right_child);
    }
}

void pre_order_traversal_with_recursion(TreeNode *root) {
    std::cout << "start to perform pre_order_traversal_with_recursion -> " << std::endl;
    std::vector<TreeNode *> tree_vec;
    pre_order_dfs(tree_vec, root);

    std::cout << "start to dump out the pre-order traversal result -> " << std::endl;
    for (TreeNode *node : tree_vec) {
        std::cout << node->val << "\t";
    }
    std::cout << std::endl;
}

// pre-order traversal the binary tree with no recursion
void pre_order_traversal(TreeNode *root) {
    std::stack<TreeNode *> tree_stack;
    std::vector<TreeNode *> tree_vec;

    TreeNode *cur_node = root;
    while (cur_node != nullptr || !tree_stack.empty()) {
        while (cur_node != nullptr) {
            tree_stack.push(cur_node);
            // 其实这个过程和 in-order 得实现过程很相似
            // 唯一得区别就是这里得 tree_vec 什么时候将遍历到得节点放到 
            // std::vector 当中
            tree_vec.push_back(cur_node);
            cur_node = cur_node->left_child;
        }
        cur_node = tree_stack.top();
        tree_stack.pop();
        cur_node = cur_node->right_child;
    }

    std::cout << "start to dump out the pre-order traverse result with stack -> " << std::endl;
    for (TreeNode *node : tree_vec) {
        std::cout << node->val << "\t";
    }
    std::cout << std::endl;

}

int main(int argc, char **argv) {
    // to dump out the following binary tree in breadth first search
    //                 1
    //             2        3
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
    pre_order_traversal_with_recursion(&root);

    pre_order_traversal(&root);
    return 0;
}