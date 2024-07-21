#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int key;
    char value;
    Node* next;
    Node* prev;

    Node(int key, char val){
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

    char get(int key) {
        if(m.find(key) == m.end()){
            return '#';
        }
        else{
            char ch = m[key]->value;
            Node* node = m[key];
            deleteNode(node);
            Node* newnode = new Node(key,ch);
            insertAtFront(newnode);
            m[key] = newnode;
            return ch;
        }
    }

    void put(int key, char val) {
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

    // your code goes here
    LRUCache lruc(2);
    lruc.put(2,'A');
    lruc.put(1,'A');
    cout << lruc.get(2) << endl;
    lruc.put(4,'A');
    cout << lruc.get(1) << endl;
    cout << lruc.get(2) << endl;

    return 0;
}