#include  <iostrem> 
#include <cstring>
using namespace std; 

class String {
private:
    static const size_t A ; 
    size_t length;
    union {
        char small[A + 1]; 
        char* heap;                
    };
    bool isSSO() const { return length <= A; }

public:
    String() : length(0) { small[0] ; }

    String(const char* str) {
        length = std::strlen(str);
        if (length <= A) {
            memcpy(small, str, length + 1);
        }
        else {
            heap = new char[length + 1];
            memcpy(heap, str, length + 1);
        }
    }

    String(const String& other) {
        length = other.length;
        if (other.isSSO()) {
            memcpy(small, other.small, length + 1);
        }
        else {
            heap = new char[length + 1];
            memcpy(heap, other.heap, length + 1);
        }
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;

        if (!isSSO()) delete[] heap;

        length = other.length;
        if (other.isSSO()) {
            memcpy(small, other.small, length + 1);
        }
        else {
            heap = new char[length + 1];
            memcpy(heap, other.heap, length + 1);
        }
        return *this;
    }

    ~String() {
        if (!isSSO()) delete[] heap;
    }

    const char* c_str() const { return isSSO() ? small : heap; }

    size_t size() const { return length; }


    void print() const { cout << c_str() ; }
};

int main() {
    String s1();
    cout  << s1.c_str()  << s1.size() << endl;

    String s2 = s1;
    cout << s2.c_str()  << s2.size() << endl;

    String s3;
    s3 = s1; 
    cout  << s3.c_str()  << s3.size() << endl;

    String s4;
    cout << s4.c_str() << s4.size() << endl;

    return 0;
}
