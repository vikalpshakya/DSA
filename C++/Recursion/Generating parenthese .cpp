// Time complexity : (2^n), Space complexity: O(2n) ~ O(n)  
// question link : https://leetcode.com/problems/generate-parentheses/ 
class Solution {
  private:
    vector<string> ans;
    void generate(string &str, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return ;
        }
        if(open > 0) {
            str.push_back('(');
            generate(str, open-1 , close);
            str.pop_back();  // backtracking , and finding other possible soulution to place the brackets 
        }

        // close > open means that , number of closed brackets should be less than open 
        // we have put '>' sign coz , we are subtracting 1 from N , everytime
        // so if the value of close is higher then it means that , number of closing brackets in out string is less

        if(close > 0 && close > open) { 
            str.push_back(')');         
            generate(str, open, close-1);
            str.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        generate(str, n, n);
        return ans;
    }
};
