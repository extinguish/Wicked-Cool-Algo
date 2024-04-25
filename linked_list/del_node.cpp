#include <iostream>

struct Node {
    int data;
    struct Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void print_linked_list(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

Node * reverse_linked_list(Node *head) {
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void reverse_linked_list_1(Node *head) {
    Node *prev = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        Node *next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    std::cout << "head->data = " << head->data << std::endl;
    std::cout << "prev->data = " << prev->data << std::endl;

    head = prev;
}


struct LinkedList {
    Node *head;
    LinkedList() {
        head = nullptr;
    }

    void reverse() {
        Node *tmp = head;

        Node *cur = tmp;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void print() {
        Node *tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->data << "\t";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void push(int data) {
        Node *tmp = new Node(data);
        tmp->next = head;
        head = tmp;
    }
};

int main(int argc, char **argv) {
    Node node_1{1};
    Node node_2{2};
    Node node_3{3};
    Node node_4{4};
    Node node_5{5};
    Node node_6{6};

    node_1.next = &node_2;
    node_2.next = &node_3;
    node_3.next = &node_4;
    node_4.next = &node_5;
    node_5.next = &node_6;
    node_6.next = nullptr;
    Node *head = &node_1;
    print_linked_list(head);
    print_linked_list(head);

    Node *reversed_list = reverse_linked_list(head);
    print_linked_list(reversed_list);

    Node *tmp = &node_1;
    reverse_linked_list_1(tmp);
    print_linked_list(tmp);

    // another way to reverse the linked list
    LinkedList linkedList;
    linkedList.push(1);
    linkedList.push(2);
    linkedList.push(3);
    linkedList.push(4);
    linkedList.push(5);

    linkedList.print();
    linkedList.reverse();
    linkedList.print();
    
}