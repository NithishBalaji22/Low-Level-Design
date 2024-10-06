#pragma once
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        class Node{
            public:
                int key;
                int val;
                Node* prev;
                Node* next;
                
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                    prev = next = NULL;
                }
        };
        
        int capacity;
        unordered_map<int, Node*> mp;
        
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
        
        LRUCache(int capacity){
            this->capacity = capacity;
            head->next = tail;
            tail->prev = head;
        }
        
        void addNode(Node* node){
            Node* headNext = head->next;
            node->next = headNext;
            node->prev = head;
            head->next = node;
            headNext->prev = node;
        }
        
        void deleteNode(Node* delNode){
            Node* nodePrev = delNode->prev;
            Node* nodeNext = delNode->next;
            nodePrev->next = nodeNext;
            nodeNext->prev = nodePrev;
        }
        
        int get(int key){
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                int nodeVal = node->val;
                deleteNode(node);
                addNode(node);
                mp.erase(key);
                mp[key] = head->next;
                return nodeVal;
            }
            return -1;
        }
        
        void put(int key, int val){
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                deleteNode(node);
                mp.erase(key);
            }
            
            if(mp.size() == capacity){
                Node* tailPrev = tail->prev;
                //int nodeVal = tailPrev->val; deletion should be based on they key not on the based of value
                int nodeKey = tailPrev->key;
                mp.erase(nodeKey);
                deleteNode(tailPrev);
            }
            
            addNode(new Node(key, val));
            mp[key] = head->next;
        }
};

