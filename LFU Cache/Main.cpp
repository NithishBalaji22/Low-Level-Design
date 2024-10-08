#include "LFUCache.hpp"
#include<iostream>
using namespace std;

int main(){
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1,1);
    lfu->put(2,2);
    cout<<lfu->get(1)<<" ";
    cout<<lfu->get(2)<<" ";
    lfu->put(3,3);
    cout<<lfu->get(3)<<" ";
    cout<<lfu->get(2)<<" ";
    cout<<lfu->get(1)<<" ";
}
