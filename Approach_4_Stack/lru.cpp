#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

/*

Data Structure(s) Used : stack<int> and unordered_map<int,char>

Time and Space Complexities

Get : O(c) and O(c)
Put : O(c) and O(c)

c is the capacity of the cache

Verdict : 18/22 test cases passed on LC [TLE]

*/

class LRUCache {
public:
    int cap; // capacity
    stack<int> stck; // to maintain the key order
    unordered_map<int,char> m; // store key value pairs
    int curr; // current size

    void deleteBottom(stack<int> &stck){
        if(stck.size() == 1){
            stck.pop();
            return;
        }
        int num = stck.top();
        stck.pop();
        deleteBottom(stck);
        stck.push(num);
    }

    bool isPresent(stack<int> &stck,int key){
        if(stck.empty()){
            return false;
        }
        else if(stck.top() == key){
            return true;
        }

        int num = stck.top();
        stck.pop();
        bool ans = isPresent(stck,key);
        stck.push(num);
        return ans;
    }

    void deleteFromMiddle(stack<int> &stck,int key){
        if(stck.top() == key){
            stck.pop();
            return;
        }
        int num = stck.top();
        stck.pop();
        deleteFromMiddle(stck,key);
        stck.push(num);
    }

    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }
    
    char get(int key) {
        if(isPresent(stck,key)){
            deleteFromMiddle(stck,key);
            stck.push(key);
            return m[key];
        }
        else{
            return '#';
        }
    }
    
    void put(int key, char value) {
        if(isPresent(stck,key)){
            // that key is present
            deleteFromMiddle(stck,key);
            // key deleted
            stck.push(key);
            // key pushed on top
            m[key] = value;
        }
        else{
            // key not present
            if(curr == cap){
                // stack is full
                deleteBottom(stck);
                // lru removed
                stck.push(key);
                m[key] = value;
            }

            else{
                // key simply pushed
                stck.push(key);
                m[key] = value;
                // curr size incremented
                curr++;
            }
        }
    }
};


int main(){
    
    LRUCache lruc(2);
    lruc.put(1,'A');
    lruc.put(2,'B');
    cout << lruc.get(1) << endl;
    lruc.put(3,'C');
    cout << lruc.get(2) << endl;

    return 0;
}
