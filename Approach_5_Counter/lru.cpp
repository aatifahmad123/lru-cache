#include<iostream>
#include<vector>
#include<chrono>
using namespace std;

/*

Data Structure(s) Used : vector<pair<pair<int,char>,int>>

Verdict : 21/23 test cases passed on LC [TLE]

*/

class LRUCache {
    int cap; // capacity
    vector<pair<pair<int,int>,int>> v; // vector to store key-value pairs and counters
    int curr; // current size

public:

    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }
    
    int get(int key) {
        // check if the key is present or not
        bool found = false;
        int keycounter = 0;
        int ch;
        for(auto &p : v){
            if(p.first.first == key){
                found = true;
                ch = p.first.second;
                keycounter = p.second;
                p.second = curr;
                break;
            }
        }
        if(!found){
            // if not present, then return '#'
            return -1;
        }
        else{
            /*
            if present, then decrement the counters of other pairs which are
            more frequently used than the pair in which our key exists
            */ 
            for(auto &p : v){
                if((p.first.first != key) && (p.second > keycounter)){
                    p.second--;
                }
            }
            return ch;
        }
    }
    
    void put(int key, int value) {
        /*
        first check, if there is some space left on the cache
        */
        if(curr >= cap){
            /*
            no space left, let's check if the key is already present
            */
            bool found = false;
            int keycounter = 0;
            for(auto &p : v){
                if(p.first.first == key){
                    // if present, then decrement the counters of more frequently used pairs
                    found = true;
                    keycounter = p.second;
                    p.second = curr;
                    p.first.second = value;
                    break;
                }
            }
            if(found){
                for(auto &p : v){
                    if((p.first.first != key) && (p.second > keycounter)){
                        p.second--;
                    }
                }
            }
            else if(!found){
                // if not, then replace the lru pair and update the others
                for(auto &p : v){
                    if(p.second == 1){
                        p.first.first = key;
                        p.first.second = value;
                        p.second = curr;
                    }
                    else{
                        p.second--;
                    }
                }
            }
        }
        else{
            // if space is left, proceed similarly as above
            bool found = false;
            int keycounter = 0;
            for(auto &p : v){
                if(p.first.first == key){
                    found = true;
                    keycounter = p.second;
                    p.second = curr;
                    p.first.second = value;
                    break;
                }
            }
            if(found){
                for(auto &p : v){
                    if((p.first.first != key) && (p.second > keycounter)){
                        p.second--;
                    }
                }
            }
            else if(!found){
                curr++;
                pair<int,int> p = make_pair(key,value);
                pair<pair<int,int>,int> temp = make_pair(p,curr);
                v.push_back(temp);
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
