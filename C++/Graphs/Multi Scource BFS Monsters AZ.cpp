/*

PROBLEM STATEMENT :-

  You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well.
  Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
  Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. 
  Your plan has to work in any situation; even if the monsters know your path beforehand
                  
  First, print "YES" if your goal is possible, and "NO" otherwise.
  If your goal is possible, also print the length of the shortest path that you'll follow.

*/


#include<bits/stdc++.h>
#define int long long
#define SHAKYA ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e18
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n, m;
vector<vector<char>> vec;
vector<vector<int>> dist;
vector<vector<bool>> visited;

int delR[] = {1, -1, 0, 0};
int delC[] = {0, 0, 1, -1};

bool isValid(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < m && vec[r][c] != '#');
}

void solve() {
    cin >> n >> m;

    vec.assign(n, vector<char>(m, '#'));
    dist.assign(n, vector<int>(m, inf));
    visited.assign(n, vector<bool>(m, false));

    pair<int, int> a;

    queue<pair<int, int>> q;

    rep(i, n) {
        rep(j, m) {
            char c; cin >> c;
            vec[i][j] = c;

            if (c == 'M') {
                q.push({i, j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
            if (c == 'A') {
                a.first = i;
                a.second = j;
            }
        }
    }

   
    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int r = front.first, c = front.second;

        for (int i = 0; i < 4; i++) {
            int newR = delR[i] + r;
            int newC = delC[i] + c;

            if (isValid(newR, newC) && !visited[newR][newC]) {
                q.push({newR, newC});
                dist[newR][newC] = dist[r][c] + 1;
                visited[newR][newC] = true;
            }
        }
    }

    vector<vector<int>> dist1(n, vector<int>(m, inf));
    vector<vector<bool>> visited1(n, vector<bool>(m, false));

    q.push(a);
    dist1[a.first][a.second] = 0;
    visited1[a.first][a.second] = true;


    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int r = front.first, c = front.second;

        for (int i = 0; i < 4; i++) {
            int newR = delR[i] + r;
            int newC = delC[i] + c;

            if (isValid(newR, newC) && !visited1[newR][newC]) {
                q.push({newR, newC});
                dist1[newR][newC] = dist1[r][c] + 1;
                visited1[newR][newC] = true;
            }
        }
    }

    int ans = inf;

    rep(i, n) {
        rep(j, m) {
            if ((j == 0 || i == 0 || i == n - 1 || j == m - 1) && vec[i][j] != '#' && dist1[i][j] < dist[i][j]) {
                ans = min(ans, dist1[i][j]);
            }
        }
    }

    if (ans == inf) {
        cout << "NO";
    } else {
        cout << "YES\n" << ans;
    }
}

signed main() {
    SHAKYA
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}
