#include<iostream>
#include<deque>
#include<unordered_map>
#include<utility>
#include<algorithm>
using namespace std;

/*

Data Structure(s) Used : deque<int> and unordered_map<int,char>

Verdict : 20/22 test cases passed on LC [TLE]

*/

class LRUCache {
public:
    int cap; // capacity
    deque<int> dq; // to maintain the key order
    unordered_map<int,char> m; // store key value pairs
    int curr; // current size


    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }
    
    char get(int key) {
        if(m.find(key) != m.end()){
            auto it = find(dq.begin(),dq.end(),key);
            dq.erase(it);
            dq.push_front(key);
            return m[key];
        }
        else{
            return '#';
        }
    }
    
    void put(int key, char value) {
        if(m.find(key) != m.end()){
            // already present
            auto it = find(dq.begin(),dq.end(),key);
            dq.erase(it);
            dq.push_front(key);
            m[key] = value;
        }
        else{
            if(curr >= cap){
                int lru = dq.back();
                m.erase(lru);
                dq.pop_back();
                dq.push_front(key);
                m[key] = value;
            }
            else{
                dq.push_front(key);
                m[key] = value;
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
