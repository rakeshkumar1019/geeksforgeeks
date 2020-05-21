#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class LRUCache{
  private:
  int capacity;
  list<int> keys;
  unordered_map<int,pair<int,list<int>::iterator >> map;
  public:
  LRUCache(int cap){
    capacity=cap;
  }
  int get(int key){
    if(map.find(key)!=map.end()){
      keys.erase(map[key].second);
      keys.push_front(key);
      map[key].second=keys.begin();
      //return value w.r.t key 
      return map[key].first;
    }
    return -1;

  }

  void put(int key,int value){
    if(map.find(key)!=map.end()){
      //key is present list
      keys.erase(map[key].second);
      keys.push_front(key);
      map[key]={value,keys.begin()};
    }else{
      if(keys.size()==capacity){
        map.erase(keys.back());
        keys.pop_back();
      }
      keys.push_front(key);
      map[key]={value,keys.begin()};
    }
    
  }

};
int main(){
  LRUCache lru(3);
  lru.put(1,10);
  lru.put(2,20);
  lru.put(3,30);
  lru.put(4,40);
  cout<<lru.get(4)<<endl;


}
