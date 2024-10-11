// Probelem link: https://www.codechef.com/SNCKPB17/problems/SNSOCIAL

#include<bits/stdc++.h>
#define int long long
#define SHAKYA ios_base::sync_with_stdio(false);cin.tie(NULL);
#define s second
#define f first
using namespace std; 

int n,m;
int delR[] = {1,-1,0,0,-1,1,-1,1};
int delC[] = {0,0,1,-1,-1,1,1,-1};

bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}



void solve() {

    cin >> n >> m;

    vector<vector<int>>grid(n,vector<int>(m));
    vector<vector<int>>level(n,vector<int>(m,0));
    vector<vector<bool>>visited(n,vector<bool>(m,false));

    int maxi = 0 ;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            maxi = max(maxi,grid[i][j]);
        }
    }

     // bfs on all nodes with maximum value

     queue<pair<int,int>>q; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == maxi) {
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        auto front = q.front();
        q.pop();

        int r = front.f, c = front.s;

        for(int i = 0; i < 8; i++) {
            int newR  = r + delR[i];
            int newC = c + delC[i];

            if(isValid(newR,newC) && !visited[newR][newC]) {
                q.push({newR,newC});
                level[newR][newC] = level[r][c]+1;
                visited[newR][newC] = true;
            }
        }
    }

    int ans = 0;

    for(auto &it: level) {
        for(auto &i : it) {
            ans = max(ans,i);
        }
    }

    cout << ans << endl;


}


signed main(){
    SHAKYA
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
