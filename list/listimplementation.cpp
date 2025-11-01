#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class List {
private:
    vector<int> data;

public:
    void push_back(int val) {
        data.push_back(val);
    }

    void pop_back() {
        if (data.empty()) {
            cout << " ";
            return;
        }
        data.pop_back();
    }

    
    int back() {
        if (data.empty()) {
            cout << " ";
            return -1; 
        }
        return data.back();
    }

    
    void print() {
        for (int val : data) {
            cout << val << " ";
        }
        cout << endl;
    }

    int size() {
        return data.size();
    }
};

int main() {
    List myList;

    myList.push_back( );
    myList.print();

    myList.pop_back();
    myList.print(); 

    cout << myList.back() << endl;  

    return 0;
}
