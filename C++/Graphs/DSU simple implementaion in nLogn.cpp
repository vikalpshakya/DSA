#include<bits/stdc++.h>
using namespace std;
// time complexity: O(nlogN)

class DSU {
    map<int,int>inSet;
    vector<int>customSet[1000];

    public: 
        DSU(int n) {
            customSet->resize(n+1);
            for(int i = 1; i<= n; i++) {
                inSet[i] = i;
                customSet[i].push_back(i);
            }
        }
        
        void merge(int u, int v ) {
            int set1 = inSet[u] , set2 = inSet[v];
            if(set1 == set2) return;

            if(customSet[set1].size() < customSet[set2].size()) {
                swap(set1,set2);
            }
            for(auto it: customSet[set2]) {
                inSet[it] = set1;
                customSet[set1].push_back(it);
            }
            customSet[set2].clear();
        }

        int find(int u) {
            return inSet[u];
        } 

        void checkIsSameComponent(int u, int v) {
            cout << ( find(u) == find(v) ? "Yes\n" : "No\n" ) ;
        }

};


int main() {
    int n,m; cin >> n >> m;

    DSU dsu(n);

    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;

        dsu.merge(u,v);
    }

    int queries; cin >> queries;

    dsu.merge(1,6);

    while(queries--) {
        int u,v; cin >> u >> v;

        dsu.checkIsSameComponent(u,v);
        // dsu.merge(u,v);
    }

}
