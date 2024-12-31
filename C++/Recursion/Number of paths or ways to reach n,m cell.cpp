/*
Question: you are given a grid , and u are standing on 0,0 cell , and u can go in down or right direction ,
          if value of cell is 0, that means u can not got to that cell (it's blocked)
          Now print the number of possible paths/ways to reach n-1,m-1 th cell
*/

int n,m;

int vec[5][5];

// u can only go right or down 

int path(int i, int j) {
    if (i < 0 || j < 0 || vec[i][j] == 0) return 0;

    if (i == 0 && j == 0) return 1;

    return path(i-1, j) + path(i, j-1);
}


void solve() {
    cin >> n >> m;
    rep(i,n){
        rep(j,m)
            cin >> vec[i][j];
    }

    cout << path(n-1,m-1) << endl;


}
