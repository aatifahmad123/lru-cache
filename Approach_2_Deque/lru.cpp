#include<iostream>
#include<deque>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<chrono>
using namespace std;

/*

Data Structure(s) Used : deque<int> and unordered_map<int,char>

Verdict : 21/23 test cases passed on LC [TLE]

*/

class LRUCache {
public:
    int cap; // capacity
    deque<int> dq; // to maintain the key order
    unordered_map<int,int> m; // store key value pairs
    int curr; // current size


    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            auto it = find(dq.begin(),dq.end(),key);
            dq.erase(it);
            dq.push_front(key);
            return m[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
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
