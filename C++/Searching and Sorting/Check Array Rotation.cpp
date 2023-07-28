#include <bits/stdc++.h>
int arrayRotateCheck(int *input, int size)
{
    int x= *max_element (input,input+size),y;
    if(size==0){
        return 0;
    }
    else if (input[size-1]==x){
        return 0;
    }
    else
    for ( int i = 0; i < size ; i++) {
        if (input[i] == x){
                y=i;
        }
    }
return y+1;

}
// You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' (K is greater than 0) in the right hand direction.
// Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
