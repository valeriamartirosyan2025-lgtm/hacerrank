#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep = ) {
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) cout << sep;
    }
    cout << endl;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* current = llist;
    int idx = 0;

    while (current != nullptr && idx < position - 1) {
        current = current->next;
        idx++;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return llist;
}

int main() {
    SinglyLinkedList list;

    list.insert_node();
    list.insert_node();
    list.insert_node();
;
    print_singly_linked_list(list.head);

    list.head = insertNodeAtPosition(list.head);

    print_singly_linked_list(list.head);

    free_singly_linked_list(list.head);
    return 0;
}
