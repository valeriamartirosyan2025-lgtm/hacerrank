#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
bool has_cycle(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, value, cycleIndex;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* node = new Node();
        node->data = value;
        node->next = nullptr;
        if (!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    cin >> cycleIndex;

    if (cycleIndex >= 0 && cycleIndex < n && tail) {
        Node* temp = head;
        for (int i = 0; i < cycleIndex; ++i) {
            temp = temp->next;
        }
        tail->next = temp; 
    }

    if (has_cycle(head)) {
        cout << " ";
    }
    else {
        cout << " ";
    }

    if (!has_cycle(head)) {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
