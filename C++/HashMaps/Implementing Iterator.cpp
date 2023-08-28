#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int>map;
    map["abc1"] = 1;
    map["abc2"] = 2;
    map["abc3"] = 3;
    map["abc4"] = 4;
    map["abc5"] = 5;
    map["abc6"] = 6;
    unordered_map<string,int> :: iterator it = map.begin();
    while(it != map.end()) {
        cout << "key: " << it->first << " value: " << it->second << endl;
        ++it;
    }
}
