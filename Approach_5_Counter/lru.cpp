#include<iostream>
#include<vector>
using namespace std;

/*

Data Structure(s) Used : vector<pair<pair<int,char>,int>>

Time and Space Complexities:

Get : O(c) and O(1)
Put : O(c) and O(1)

Verdict : 20/22 test cases passed on LC [TLE]

*/

class LRUCache {
    int cap; // capacity
    vector<pair<pair<int,char>,int>> v; // vector to store key-value pairs and counters
    int curr; // current size

public:

    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }
    
    char get(int key) {
        // check if the key is present or not
        bool found = false;
        int keycounter = 0;
        char ch;
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
            return '#';
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
    
    void put(int key, char value) {
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
                pair<int,char> p = make_pair(key,value);
                pair<pair<int,char>,int> temp = make_pair(p,curr);
                v.push_back(temp);
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
