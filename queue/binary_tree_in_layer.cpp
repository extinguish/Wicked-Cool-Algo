#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left_child;
    TreeNode *right_child;
};

// 以下是第一种将层 信息获取到的遍历方法
// 下面的这种方法是使用到了2个变量来记录这个层的过程
void get_layer_max(TreeNode *root) {
    // get the max Node in each layer
    // the following vector are using to store all
    // of the node value of the whole tree
    std::vector<int> val_vec;

    int cur_layer_count = 0;
    int next_layer_node_count = 0;
    int layer_index = 0;

    std::queue<TreeNode *> tree_queue;
    tree_queue.push(root);
    cur_layer_count = 1;
    // 我们这里不需要将root节点提前放到 val_vec 当中
    // 因为我们在后面遍历 tree 的时候，也会将 tree node
    // 当中的值 push 到 val_vec 当中
    // val_vec.push_back(root->val);

    while (!tree_queue.empty()) {
        TreeNode *cur_node = tree_queue.front();
        // 这个 val_vec 是问题的关键，需要注意的是，
        // 只有在遍历当前节点的时候，我们才需要把当前节点放到 val_vec
        // 当中，
        // 也就是说，val_vec 当中保存的只是当前正在遍历的节点
        // 只有当cur_layer_count == 0 的时候，
        // 就代表当前层 空了，只有当 当前 layer 空了之后，
        // 我们才需要去 dump 当前的 val_vec
        val_vec.push_back(cur_node->val);

        tree_queue.pop();
        cur_layer_count -= 1;

        if (cur_node->left_child != nullptr) {
            tree_queue.push(cur_node->left_child);
            next_layer_node_count += 1;
        }
        if (cur_node->right_child != nullptr) {
            tree_queue.push(cur_node->right_child);
            next_layer_node_count += 1;
        }

        if (cur_layer_count == 0) {
            // one layer is complete, start to calculate the 
            // max value of current layer
            int max_val = 0;
            std::cout << "start to dump the node in layer : " << layer_index << std::endl;
            for (int i = 0; i < val_vec.size(); ++i) {
                std::cout << val_vec[i] << "\t";
                if (max_val <= val_vec[i]) {
                    max_val = val_vec[i];
                }
            }
            std::cout << std::endl;
            std::cout << "layer " << layer_index << " max value are " << max_val << std::endl;
            val_vec.clear();

            layer_index += 1;
            cur_layer_count = next_layer_node_count;
            next_layer_node_count = 0;
        }

    }
}

// 下面是另一种获取bfs遍历过程当中层 信息的方法
// 在下面的这种方法当中，我们使用2个 queue 来分别维护当前层
// 和下一层的节点信息
void get_layer_max_2(TreeNode *root) {
    std::queue<TreeNode *> cur_layer_queue;
    std::queue<TreeNode *> next_layer_queue;

    cur_layer_queue.push(root);

    int layer_index = 0;
    std::vector<int> val_vec;
    while (!cur_layer_queue.empty()) {
        TreeNode *cur_node = cur_layer_queue.front();
        val_vec.push_back(cur_node->val);
        cur_layer_queue.pop();
        
        if (cur_node->left_child != nullptr) {
            next_layer_queue.push(cur_node->left_child);
        }
        if (cur_node->right_child != nullptr) {
            next_layer_queue.push(cur_node->right_child);
        }

        if (cur_layer_queue.empty()) {
            std::cout << "start to dump layer of " << layer_index << std::endl;
            for (int i = 0; i < val_vec.size(); ++i) {
                std::cout << val_vec[i] << "\t";
            }
            val_vec.clear();
            std::cout << std::endl;

            // 此时我们需要切换一下cur_layer_queue和next_layer_queue
            while (!next_layer_queue.empty()) {
                cur_layer_queue.push(next_layer_queue.front());
                next_layer_queue.pop();
            }

            layer_index += 1;
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

    get_layer_max(&root);

    std::cout << "start to get the max node in each layer with two queue " << std::endl;
    get_layer_max_2(&root);

    return 0;
}