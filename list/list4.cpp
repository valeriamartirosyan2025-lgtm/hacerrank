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

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data ;
        node = node->next;
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

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* ptr1 = head1;
    SinglyLinkedListNode* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = ptr1 ? ptr1->next : head2;
        ptr2 = ptr2 ? ptr2->next : head1;
    }

    return ptr1 ? ptr1->data : -1; 
}

int main() {
    SinglyLinkedList list1, list2;
    int n1, n2, value, mergeIndex;
    cin >> n1;
  
    for (int i = 0; i < n1; ++i) {
        cin >> value;
        list1.insert_node(value);
    }

    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> value;
        list2.insert_node(value);
    }
    cin >> mergeIndex;

    if (mergeIndex >= 0 && mergeIndex < n1 && list2.tail) {
        SinglyLinkedListNode* temp = list1.head;
        for (int i = 0; i < mergeIndex; ++i) {
            temp = temp->next;
        }
        list2.tail->next = temp;
    }

    cout << findMergeNode(list1.head, list2.head) << endl;

    free_singly_linked_list(list1.head);
    free_singly_linked_list(list2.head);

    return 0;
}
