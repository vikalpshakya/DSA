
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& vec) {

        sort(vec.begin(),vec.end(),cmp);

        // for(auto it: vec) cout << it[0] << " " << it[1] << endl;

        priority_queue<int>pq;

        int ans = 0;
        int n = vec.size();
        int currDay = 0;

        for(int i = 0; i < n; i++) {
            if(vec[i][0] > vec[i][1]) continue;

            if(pq.empty()) {
                currDay = vec[i][0];
                pq.push(vec[i][0]);
                ans++;
            } 
            else {
                int top = pq.top();
                if(currDay + vec[i][0] <= vec[i][1]) {
                    ans++;
                    currDay += vec[i][0];
                    pq.push(vec[i][0]);
                }
                else if(vec[i][0] <= top) {
                    pq.pop();
                    currDay -= (top-vec[i][0]);
                    pq.push(vec[i][0]);
                }
            }
        }

        return ans;
    }
