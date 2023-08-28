#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> map;
    
    // insertion 
    pair<string,int>p ("abc" , 1);
    map.insert(p);
    // Another method of insertion
    map["xyz"] = 2;
    
    //Find or acess
    cout << map["abc"] << endl;  // in this case , IF INCASE string "abc" is not present in the map , then this wil automaticlly insert "abc" in the map and print default value as 0
    cout << map.at("abc") << endl;
    
    //size
    cout << map.size() << endl;
    
    //check presence
    cout << map.count("abc") << endl;  // returns 1 if the element with key K is present in the map
    
}
