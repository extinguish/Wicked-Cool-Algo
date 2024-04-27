#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left_child;
    TreeNode *right_child;
};

void dfs_with_recursion(std::vector<TreeNode *> &node_list, TreeNode *node) {
    if (node != nullptr) {
        dfs_with_recursion(node_list, node->left_child);
        node_list.push_back(node);
        dfs_with_recursion(node_list, node->right_child);
    }
}

// the in-order traversal are left-child --> root --> right-child
// implement in-order depth-first-traversal with recursion
void in_order_traversal_in_recursion(TreeNode *node) {
    // this vector is just using to place the traversal result
    std::vector<TreeNode *> node_vec;
    dfs_with_recursion(node_vec, node);
    // the recursion is finished, now the result is contained inside the 
    // node_vec
    std::cout << "start to dump out the in-order traversal result -> " << std::endl;
    for (const TreeNode *node : node_vec) {
        std::cout << node->val << "\t";
    }
    std::cout << std::endl;
}

// implemen in-order depth-first-traversal without recursion
// we need using the stack to avoid recursion
void in_order_traversal(TreeNode *root) {
    // this vector are using to store the in-order traversal result
    std::vector<TreeNode *> node_vec;
    std::stack<TreeNode *> node_stack;

    // using a temp node to trace the binary tree
    // thus to avoid modify the root node
    TreeNode *cur_node = root;
    while (cur_node != nullptr || !node_stack.empty()) {
        while (cur_node != nullptr) {
            node_stack.push(cur_node);
            cur_node = cur_node->left_child;
        }

        cur_node = node_stack.top();
        // 如果是第一次走到这里的话，那么此时的stack当中存放得就是left-bottom 节点了
        node_vec.push_back(cur_node); // put the traversal records into the node_vec
        node_stack.pop();
        cur_node = cur_node->right_child;
    }

    std::cout << "start to dump the out tree with in-order traverser -> " << std::endl;
    for (TreeNode *node : node_vec) {
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


    in_order_traversal_in_recursion(&root);

    std::cout << "in-order traversal without recursion --> " << std::endl;
    in_order_traversal(&root);
    return 0;
}