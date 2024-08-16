#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
using namespace std;


/*

Data Structure(s) Used : doubly linked list and unordered_map<int,char>

Verdict : 23/23 test cases passed on LC [TLE]

*/

class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->value = val;
        next = prev = NULL;
    }
};



class LRUCache{
public:
    int cap; // capacity
    int curr; // current size
    unordered_map<int,Node*> m; // map of key and pointer to node
    Node* head = NULL; // head of DLL
    Node* tail = NULL; // tail of DLL

    void insertAtFront(Node* temp){
        if(head == NULL){
            head = tail = temp;
            return;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void deleteNode(Node* node){
        if((node == head) && (node == tail)){
            head = NULL;
            tail = NULL;
            delete node;
            return;
        }
        else if(node == head){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }
        else if(node == tail){
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            return;
        }
        else{
            Node* temp = node->prev;
            Node* fwd = node->next;
            temp->next = fwd;
            fwd->prev = temp;
            delete node;
        }
    }

    void deleteTail(){
        if(tail == head){
            Node* temp = tail;
            tail = NULL;
            head = NULL;
            delete temp;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
    }

    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        else{
            int ch = m[key]->value;
            Node* node = m[key];
            deleteNode(node);
            Node* newnode = new Node(key,ch);
            insertAtFront(newnode);
            m[key] = newnode;
            return ch;
        }
    }

    void put(int key, int val) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            deleteNode(node);
            Node* newnode = new Node(key,val);
            insertAtFront(newnode);
            m[key] = newnode;
        }
        else{
            if(curr >= cap){
                int lru = tail->key;
                deleteTail();
                m.erase(lru);
                Node* node = new Node(key,val);
                m[key] = node;
                insertAtFront(node);
            }
            else{
                Node* node = new Node(key,val);
                m[key] = node;
                insertAtFront(node);
                curr++;
            }
        }
    }
};

int main() {

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