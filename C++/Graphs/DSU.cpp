// Union by rank 

// Overall TC: O(n) 
// TC: per query = O(\alpha(n)) the inverse Ackermann function, which grows very slowly.In fact it grows so slowly,that it doesn't exceed  4 n  
 
class DSU {
    vector<int>parent,size,rank;
    public:
        DSU(int n) {
            parent.resize(n+1);
            rank.assign(n+1,0);

            for(int i = 0; i <= n; i++) parent[i] = i;

        }

        int findU_parent(int x) {  // find ultimate parent
            if(x == parent[x]) return x;
            return parent[x] = findU_parent(parent[x]);  // path compression 
        }

        void merge(int x, int y) {
            int prX = findU_parent(x), prY = findU_parent(y);
            if(rank[prX] > rank[prY]) 
                parent[prY] = prX;
            else if(rank[prX] < rank[prY])
                parent[prX] = prY;
            else {
                parent[prY] = prX;
                rank[prY]++;
            }
            
        }

        bool check(int x, int y) {
            return findU_parent(x) == findU_parent(y);
        }
};
