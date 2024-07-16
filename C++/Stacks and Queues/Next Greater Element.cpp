// problem link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#define ll long long
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        vector<ll>ans(n,-1);
        stack<ll>st;
        
        for(int i = 0 ; i < n; i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            ll num = arr[i];
            while(!st.empty() && arr[st.top()] < num ){
                ans[st.top()] = num;
                st.pop();
            }
            st.push(i);
        
        }
        return ans;
    
    }
};
