
class LFUCache {
public:
    int capacity;   // Max cache size
    int currSize;   // Current cache size
    int minFreq;    // Tracks minimum frequency

    unordered_map<int, pair<int,int>> keyToValFreq; // Key -> {value, frequency}

    // Frequency -> list of keys (most recent at front, least recent at back)
    unordered_map<int, list<int>> freqToKeys;

    // Key -> iterator pointing to its position inside freqToKeys[freq]
    unordered_map<int, list<int>::iterator> keyToIter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }


    void updateFrequency(int key) {
        int freq = keyToValFreq[key].second;

        // Remove key from current frequency list
        freqToKeys[freq].erase(keyToIter[key]);

        // Increase key's frequency
        keyToValFreq[key].second++;

        int newFreq = freq + 1;

        // Push most recently used element at the FRONT
        freqToKeys[newFreq].push_front(key);

        // Update iterator mapping
        keyToIter[key] = freqToKeys[newFreq].begin();

        // If old list was empty and it was the minFreq -> increment minFreq
        if (freqToKeys[freq].empty() && freq == minFreq) {
            minFreq++;
        }
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) 
            return -1;

        int value = keyToValFreq[key].first;
        updateFrequency(key);
        return value;
    }

    void put(int key, int value) {

        // Case 1: Key already exists -> update value & freq
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        // Case 2: Cache full -> remove LFU key (least recently used = BACK of list)
        if (currSize == capacity) {
            int keyToRemove = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();

            keyToValFreq.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
            currSize--;
        }

        // Case 3: Insert new key with freq = 1 (at front)
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();

        minFreq = 1;  // Reset minFreq to 1 for new key
        currSize++;
    }
};
