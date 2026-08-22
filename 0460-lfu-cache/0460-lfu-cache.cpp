class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> keyData;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> position;

    void increaseFreq(int key) {
        int freq = keyData[key].second;

        freqList[freq].erase(position[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq) {
                minFreq++;
            }
        }

        keyData[key].second++;
        int newFreq = freq + 1;

        freqList[newFreq].push_front(key);
        position[key] = freqList[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyData.find(key) == keyData.end()) {
            return -1;
        }

        int value = keyData[key].first;

        increaseFreq(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (keyData.find(key) != keyData.end()) {
            keyData[key].first = value;

            increaseFreq(key);

            return;
        }

        if (keyData.size() >= capacity) {
            int lruKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyData.erase(lruKey);
            position.erase(lruKey);
        }

        keyData[key] = {value, 1};

        freqList[1].push_front(key);
        position[key] = freqList[1].begin();

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */