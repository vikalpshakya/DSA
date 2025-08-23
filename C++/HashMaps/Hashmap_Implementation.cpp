#include<bits/stdc++.h>
using namespace std;

// using seperate chaining

// Avg case TC: O(1) 


class HashMap{
    private:
        int size = 17;                            // any prime number
        vector<list<pair<int,string>>>table;      // idx0 = List[{k,v} ..] , idx1 = List[{k,v}..]
        int currSize = 0;                         // stores the currentSize of the Map
    public:
        bool isEmpty();
        int hashFunction(int key);
        void insert(int key, string val);
        void remove(int key);
        string search(int key);
        void printMap();
        void rehash(); // optional

    HashMap() {
        table.resize(size);
    }
};

bool HashMap::isEmpty(){

    if(currSize == 0) cout << "Map is empty\n";
    return currSize == 0;
}

int HashMap::hashFunction(int key) {
    // return key%size;
    return (key ^ (key >> 16)) % size;  // gives better hashed value
}

void HashMap::insert(int key, string val) {
    int hash = hashFunction(key);
    auto &bucket = table[hash];
    auto bItr = begin(table[hash]);

    bool isAlreadyPresent = false;

    for(; bItr != end(table[hash]); bItr++) {
        if(bItr->first == key) {
            cout << "Key already present in the map \n";
            bItr->second = val;
            isAlreadyPresent = true;
            break;
        }
    }

    if(!isAlreadyPresent) {
        table[hash].push_back({key,val});
        cout << "Value inserted successfully\n";
        currSize++;
    }

    // optional
    double loadFactor = (double)currSize/size;  
    if(loadFactor >= 0.75) rehash(); 

}

void HashMap::remove(int key){
    int hash = hashFunction(key);
    auto &bucket = table[hash];
    auto bItr = begin(table[hash]);

    bool isPresent = false;

    for(; bItr != end(bucket); bItr++) {
        if(bItr -> first == key) {
            isPresent = true;
            table[hash].erase(bItr);
            break;
        }
    }

    if(!isPresent) cout << "Key not found\n";
    else currSize--;
}

string HashMap::search(int key) {
    int hash = hashFunction(key);
    auto &bucket = table[hash];
    auto bItr = begin(table[hash]);

    for(;bItr != end(bucket); bItr++) {
        if(bItr->first == key) {
            cout << "Key found -> " << bItr->second << endl;
            return bItr->second;
        }
    }

    return "Key not found\n";
}
void HashMap::printMap() {
    // cout << " HashMap \n";
    for(int i = 0; i < size; i++) {
        if(table[i].size() == 0) continue;

        for(auto it: table[i]) {
            cout << it.first << " " << it.second << endl;
        }
    }
}


void HashMap::rehash() {    // optional
    int oldSize = size;
    size = size * 2;
    vector<list<pair<int, string>>> newTable(size);

    for (int i = 0; i < oldSize; i++) {
        for (auto &p : table[i]) {
            int newHash = hashFunction(p.first);
            newTable[newHash].push_back(p);
        }
    }
    table = move(newTable);
}


int main() {
    HashMap mp;
    mp.insert(4,"Vikalp");
    mp.printMap();
    mp.remove(5);
    mp.search(4);
    mp.remove(4);
    mp.isEmpty();

}
