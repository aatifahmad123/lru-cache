#include<iostream>
#include<stack>
#include<unordered_map>
#include<chrono>
#include<vector>
using namespace std;

/*

Data Structure(s) Used : stack<int> and unordered_map<int,char>

Verdict : 19/23 test cases passed on LC [TLE]

*/

class LRUCache {
public:
    int cap; // capacity
    stack<int> stck; // to maintain the key order
    unordered_map<int,int> m; // store key value pairs
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
    
    int get(int key) {
        if(isPresent(stck,key)){
            deleteFromMiddle(stck,key);
            stck.push(key);
            return m[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
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
    
    LRUCache lruc(10); // Initialize the LRU cache with a capacity of 10

    auto start = chrono::high_resolution_clock::now();

    vector<int> outputs;

    for(int i = 0;i < 100000;i++){
        lruc.put(10, 13);
        lruc.put(3, 17);
        lruc.put(6, 11);
        lruc.put(10, 5);
        lruc.put(9, 10);
        outputs.push_back(lruc.get(13));
        lruc.put(2, 19);
        outputs.push_back(lruc.get(2));
        outputs.push_back(lruc.get(3));
        lruc.put(5, 25);
        outputs.push_back(lruc.get(8));
        lruc.put(9, 22);
        lruc.put(5, 5);
        lruc.put(1, 30);
        outputs.push_back(lruc.get(11));
        lruc.put(9, 12);
        outputs.push_back(lruc.get(7));
        outputs.push_back(lruc.get(5));
        outputs.push_back(lruc.get(8));
        outputs.push_back(lruc.get(9));
        lruc.put(4, 30);
        outputs.push_back(lruc.get(9));
        outputs.push_back(lruc.get(10));
        lruc.put(6, 14);
        outputs.push_back(lruc.get(3));
        lruc.put(10, 11);
        outputs.push_back(lruc.get(8));
        lruc.put(2, 14);
        outputs.push_back(lruc.get(1));
        outputs.push_back(lruc.get(5));
        outputs.push_back(lruc.get(4));
        lruc.put(11, 4);
        lruc.put(12, 24);
        lruc.put(5, 18);
        outputs.push_back(lruc.get(13));
        outputs.push_back(lruc.get(7));
        outputs.push_back(lruc.get(8));
        outputs.push_back(lruc.get(12));
        lruc.put(3, 27);
        lruc.put(2, 12);
        outputs.push_back(lruc.get(5));
        lruc.put(2, 9);
        outputs.push_back(lruc.get(13));
        lruc.put(8, 18);
        lruc.put(1, 7);
        lruc.put(6, 30);
        outputs.push_back(lruc.get(9));
        lruc.put(8, 21);
        outputs.push_back(lruc.get(5));
        lruc.put(6, 30);
        outputs.push_back(lruc.get(1));
        outputs.push_back(lruc.get(10));
        lruc.put(4, 15);
        outputs.push_back(lruc.get(7));
        lruc.put(11, 26);
        outputs.push_back(lruc.get(8));
        outputs.push_back(lruc.get(9));
        lruc.put(5, 29);
        outputs.push_back(lruc.get(3));
        lruc.put(11, 30);
        outputs.push_back(lruc.get(12));
        lruc.put(4, 29);
        outputs.push_back(lruc.get(3));
        outputs.push_back(lruc.get(9));
        lruc.put(6, 30);
        outputs.push_back(lruc.get(3));
        lruc.put(10, 28);
        outputs.push_back(lruc.get(1));
        lruc.put(11, 13);
        outputs.push_back(lruc.get(3));
        outputs.push_back(lruc.get(3));
        lruc.put(12, 24);
        outputs.push_back(lruc.get(9));
        outputs.push_back(lruc.get(6));
        outputs.push_back(lruc.get(3));
        lruc.put(13, 17);
        outputs.push_back(lruc.get(2));
        lruc.put(11, 15);
        lruc.put(12, 24);
        outputs.push_back(lruc.get(9));
        outputs.push_back(lruc.get(2));
        outputs.push_back(lruc.get(15));
        outputs.push_back(lruc.get(11));
        lruc.put(4, 29);
        outputs.push_back(lruc.get(6));
        outputs.push_back(lruc.get(19));
        outputs.push_back(lruc.get(4));
        lruc.put(13, 28);
        lruc.put(11, 26);
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}
