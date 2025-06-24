#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e6;

// Question:
// Find Min queries to check if any number can be found in the range 1 to n;
// in each query we can ask if the number is divible by k (selected number in the range or not)

vector<bool>isPrime;

void seive() {
    isPrime.assign(MAX+1,true);

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(int j = 2*i ; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void solve() {
   seive();
   int n; cin >> n;

    vector<int>primes;

    for(int i = 1; i <= n; i++) {
        if(isPrime[i]) primes.push_back(i);
    }

    vector<int>ans;

    /*
        EG for k = 6 in range 1-6,
         first we check if the smallest prime number devides k,
         ie.. prime no = 2, yes it devides 6
         so we would check if it divides with 4 also ? (why 4 ? because we are now iterating over powers of 2 untill our num is <= k)
         no 4 doesnt divide 6, so that means our k can be represented in other form ie. 2* x*y.. (where x , y are other prime number & their multiples) 

         now we move forward to other prime number ie.. 3
         does 3 divides 6 ? yes , now we will do the same things with the powers of 3.. but here we wont go forward bcs 3^2 = 9 which is bigger than 6
         
         so our current checks are 2,4,3 

        and next prime number is 5 
        we can apply a check on it as well , we would get a false


        So final answer = 2, 4, 3 ,5 
    */

   for(int i = 0; i < primes.size(); i++) {
        if(primes[i] <= n) {
            int temp = primes[i];
            while(temp <= n) {
                ans.push_back(temp);
                temp *= primes[i];
            }
        } else break;
   }
   

   cout << ans.size() << endl;
   for(auto it: ans ) cout << it << " ";


}

int main(){
    solve();
}