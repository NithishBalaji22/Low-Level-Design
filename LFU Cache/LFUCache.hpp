#pragma once
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key, val, cnt;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = next = NULL;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* headNext = head->next;
        node->next = headNext;
        node->prev = head;
        head->next = node;
        headNext->prev = node;
        size++;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache{
    private:
        int minFreq;
        int currSize;
        int maxCacheSize;
        map<int, Node*>keyNode;
        map<int, List*> freqMapList;

    public:
        LFUCache(int capacity){
            minFreq = 0;
            currSize = 0;
            maxCacheSize = capacity;
            keyNode = map<int, Node*>();
            freqMapList = map<int, List*>();
        }

        void updateFreqList(Node* node){
            keyNode.erase(node->key);
            freqMapList[node->cnt]->remove(node);
            if(node->cnt == minFreq && freqMapList[node->cnt]->size == 0){
                minFreq++;
            }

            List* newHigherFreq = new List();
            if(freqMapList.find(node->cnt + 1) != freqMapList.end()){
                newHigherFreq = freqMapList[node->cnt+1];
            }

            node->cnt += 1;
            newHigherFreq->addFront(node);
            keyNode[node->key] = node;
            freqMapList[node->cnt] = newHigherFreq;
        }

        int get(int key){
            if(keyNode.find(key) != keyNode.end()){
                int value = keyNode[key]->val;
                updateFreqList(keyNode[key]);
                return value;
            }
            return -1;
        }

        void put(int key, int value){
            if(maxCacheSize == 0){
                cout<<"As the Cache Size is 0 we cannot add the Node"<<'\n';
                return;
            }

            if(keyNode.find(key) != keyNode.end()){
                Node* node = keyNode[key];
                node->val = value;
                updateFreqList(node);
            }else{
                if(currSize == maxCacheSize){
                    //Follow LRU
                    List* list = freqMapList[minFreq];
                    keyNode.erase(list->tail->prev->key);
                    list->remove(list->tail->prev);
                    currSize--;
                }

                currSize++;
                Node* node = new Node(key, value);
                minFreq = 1;
                List* list = new List();
                if(freqMapList.find(minFreq) != freqMapList.end()){
                    list = freqMapList[minFreq];
                }

                list->addFront(node);
                keyNode[key] = node;
                freqMapList[minFreq] = list;
            }
        }
};
