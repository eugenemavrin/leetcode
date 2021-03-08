#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
    // Runtime: 108 ms,        77%
    // Memory Usage: 188.6 MB, 23%
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mValues = vector<int>(1000000, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        mValues.at(key) = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return mValues.at(key);
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mValues.at(key) = -1;
    }
private:
    vector<int> mValues;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

