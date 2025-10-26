#include <iostream>
using namespace std;

class Vector {
private:
    int* data;
    size_t size;
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {}
    ~Vector() { delete[] data; }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    void push_back(int value) {
        if (size >= capacity) {
            resizeCapacity(capacity == 0 ? 2 : capacity * 2);
        }
        data[size++] = value;
    }

    void pop_back() { if (size > 0) size--; }

    int& operator[](size_t index) { return data[index]; }
    const int& operator[](size_t index) const { return data[index]; }

private:
    void resizeCapacity(size_t newCapacity) {
        int* newData = new int[newCapacity];
        for (size_t i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

int main() {
    Vector v;

    int n;
    cin >> n;
    cout << "";

    for (int i = 0; i < n; i++) {
        int x;
        cout << " " << i + 1;
        cin >> x;
        v.push_back(x);
    }

    cout << "/n";
    for (size_t i = 0; i < v.getSize(); i++)
        cout << v[i] << " ";
    cout << "\n";

    return 0;
}