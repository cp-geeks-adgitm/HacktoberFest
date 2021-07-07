#warning *find my detailed video explanation here: https://www.youtube.com/watch?v=zDknUrGFoxI*

class LRUCache {
public:
    
    list<int> cache; // the linked list!!! acting as a queue!
    unordered_map<int , int> val;//just store the values...
    unordered_map<int , list<int>::iterator > pos;//store the position of each key inside the list!
    
    int capacity;
        
    LRUCache(int _capacity) {
        capacity=_capacity;
    }
    
    int get(int key) {
        if(val.count(key)){
            cache.erase(pos[key]);
            cache.push_back(key);
            pos[key]=std::prev(cache.end());
            //remove him from the list, and put him in the back ;)
            return val[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(pos.count(key))
            cache.erase(pos[key]);
        //i am already inside the list!!!!
        //erase my old position
        
        //i am full!!!
        if(cache.size()==capacity){
            pos.erase(cache.front());
            val.erase(cache.front());
            cache.pop_front();//he is the lru object...
        }
        
        cache.push_back(key);
        val[key]=value;
        pos[key]=std::prev(cache.end()); // x->y->end 
    }
};

/**
 * My LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */