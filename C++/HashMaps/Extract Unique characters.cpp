#include<bits/stdc++.h>
/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the length of the input string
*/

string uniqueChar(string str) {
	unordered_set<char >mp;
	string ans = "";
	for(int i = 0; i < str.length(); i++){

			mp.insert(str[i]);
			ans+=str[i];
		}
	}
	return ans;
}
