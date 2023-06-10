// time: O(logn)
int binarySearch(int *input, int n, int val)
{
    int s=0,l=n-1;
    int m=(s+l)/2;
    
    while(s<=l){
         m=(s+l)/2;
        
        if(val<input[m]){
            l=m-1;
        }
        else if(val>input[m]){
            s=m+1;
        }
        else 
            return m;
    
               }
    return -1;
}
