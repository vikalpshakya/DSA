#define ll long long int

class Solution{

  private:
  // Time Complexity: O(n^2), Space Complexity: O(1)
    ll app1(ll arr[], ll N) {
    
        ll count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(arr[i] > arr[j]) count++;
            }
        }
        return count;
    }
    
// Time complexity: O(NLogN), Space complexity: O(n)



    ll cross_inversion(long long arr[], ll start, ll end) {
        ll mid = start + (end-start)/2;
        
        ll i = start;      // starting pointer on arr
        ll j = mid+1;      // mid pointer on arr
        ll k = start;      // pointer to copy element in output ans
        
        ll temp[end+1];
        ll count = 0;
        
        while(i <= mid and j <= end) {
            
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            
            else {
                temp[k++] = arr[j++];
                count += (mid-i+1);
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++]; 
        }
        
        while(j <= end) {
            temp[k++] = arr[j++];
        }
        
        
        for(ll i = start; i <= end; i++) {
            arr[i] = temp[i];
        }
        
        
        return count;
        
    }
    
    ll inversion_count (long long arr[], ll start, ll end) {
        if(start >= end) 
            return 0;
            
        ll mid = start + (end-start)/2;
        ll x = inversion_count(arr,start,mid);
        ll y = inversion_count(arr,mid+1,end);
        
        // cross inversions
        
        ll z = cross_inversion(arr,start,end);
        
        return (x + y + z); 
        
    }
    
  public:
    long long int inversionCount(long long arr[], long long N) {

        return inversion_count(arr, 0 , N-1);
    
    }

};
