class LRUCache {
private:
    int capacity;

    // {key, value}, paling depan = paling baru
    list<pair<int, int>> cache;

    // key -> posisi di list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        // Jadi paling baru
        cache.splice(cache.begin(), cache, it);

        return it->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];

            it->second = value;

            // Jadi paling baru
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // Tambahkan sebagai paling baru
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Kalau melebihi capacity
        if (cache.size() > capacity) {
            auto last = cache.back();

            mp.erase(last.first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */