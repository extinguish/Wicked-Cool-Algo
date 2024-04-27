#include <iostream>
#include <cstring>

// the following code implement the priority queue by using
// linked list
struct Node {
    int val; // the priority are sorted based on the node->val
    struct Node *next;
};

class PriorityQueue {
private:
    Node *front; // the priority_queue is also a queue, so 
                 // the first element that we access the queue is
                 // the "front" node
public:
    PriorityQueue(): front{nullptr} {}
    ~PriorityQueue() {
        Node *tmp = nullptr;
        while (front != nullptr) {
            tmp = front;
            front = front->next;
            free(tmp);
        }
    }

    // PriorityQueue的底层实现有很多种，可以是基于BinaryTree,
    // 也可以是基于vector或者linked list,
    // 如果是基于vector或者linked list的话，会相对来说比较简单
    // 就是每次在push或者pop时，直接遍历整个list找到要插入或者移除
    // 元素的位置就可以，但是这样的话，PriorityQueue push和pop
    // 操作的时间复杂度就是O(n),
    // 但是如果底层实现是BinaryTree的话，那么时间复杂度就是O(logn)了
    // 而这个BinaryTree的实现其实就是Red-black tree
    // Red-black tree在每次插入和删除节点的时候，都会重新动态的调整
    // 这个tree的结构，用于保持这棵树一直都是处于有序状态
    void push(int val) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->val = val;
        
        Node *tmp = front;
        if (front == nullptr) {
            front = new_node;
            front->next = nullptr;
            return;
        }

        if (val < front->val) {
            // we need to make new_node as the head node
            new_node->next = front;
            front = new_node;
            return;
        }

        
        std::cout << "start to insert " << val << std::endl;
        // 首先要找到插入的位置
        while (tmp != nullptr && tmp->val <= val) {
            tmp = tmp->next;
        }
        // 我们此时就是插入到tmp的后面就可以
        // Node *tmp_next = tmp->next;
        new_node->next = tmp->next;
        tmp->next = new_node;
        // new_node->next = tmp;
    }

    void pop() {
        // after pop, the priority queue need to keep order
        // but since the linked list is sorted, so the pop() action
        // only need to remove the head node will be OK


    }

    // return the front element
    int top() {
        if (front == nullptr) {
            std::cout << "fatal state error!!! the queue are empty!!!" << std::endl;
            return -1;
        }
        return front->val;
    }

    // dump all of the content in this priority queue
    void dump() {
        // as the underlying implementation of this priority queue is linked list
        // so we can dump this priority queue in the form of linked list
        Node *cur = front;
        if (cur == nullptr) {
            std::cout << "current priority queue is empty" << std::endl;
            return;
        }

        std::cout << "start to dump the content of this priority queue --> " << std::endl;
        while (cur != nullptr) {
            std::cout << cur->val << "\t";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, char **argv) {
    PriorityQueue queue;
    queue.push(100);
    queue.push(90);
    queue.push(20);
    queue.push(80);
    queue.push(30);
    queue.push(40);
    queue.push(10);
    queue.push(70);

    int val_1 = queue.top();
    std::cout << "current top element of the priority queue are " << val_1 << std::endl;
    queue.dump();

    queue.pop();
    queue.dump();

    int val = queue.top();
    std::cout << "after pop, current top element of the priority queue are " << val << std::endl;

    return 0;
}