//%32 speed
class LRUCache {
    list<pair<int,int>> l;
    unordered_map<int, decltype(l.begin())> m;
    void insert(int key, int value) {
        auto iter = l.insert(l.begin(), {key, value});
        m.insert({key, iter});
        size++;
    }
    void remove(int key) {
        auto iter = m.at(key);
        l.erase(iter);
        m.erase(key);
        size--;
    }
    void printlist() {
        for (auto x : l) {
            cout << x.first << "->" << x.second << " ";
        }cout << '\n';
    }
    void removeOldest() {
        auto iter = --l.end();
        remove(iter->first);
    }
    int cap;
    int size=0;
public:
    LRUCache(int capacity) : cap(capacity) {

    }

    int get(int key) {
        if (m.count(key) > 0) {
            //we have this element
            auto kvpair = *m.at(key);
            remove(kvpair.first);
            insert(kvpair.first, kvpair.second);
            return kvpair.second;
        } else {
            //we don't have it
            return -1;
        }
    }

    void put(int key, int value) {
        if (m.count(key) > 0) {
            //we have that key, need to update value
            remove(key);
            insert(key, value);
        } else {
            //else we don't have that key insert into DB
            if (size < cap) {
                //new element will fit
                insert(key, value);
            } else {
                //won't fit evict old element
                removeOldest();
                insert(key, value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
