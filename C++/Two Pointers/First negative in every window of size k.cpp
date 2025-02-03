// problem link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
            
        int n = arr.size();
        vector<int>ans;
        
        queue<int>q;
        
        int start = 0, end = 0;
        
        while(end < n) {
            if(arr[end] < 0) q.push(arr[end]);
            
            int windowSize = end-start+1;
            
            if(windowSize < k) end++;
            else if(windowSize == k ) {
                if(q.empty()) ans.push_back(0);
                
                else{
                    ans.push_back(q.front());
                    if(arr[start] == q.front()) q.pop();
                }
                start++;
                end++;
            }
        }
        
        return ans;
        
    }
