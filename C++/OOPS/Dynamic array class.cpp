#include <iostream>
using namespace std;
class DynamicArray {
 int *data ;
 int nextIndex;
 int capacity;

 public:

 DynamicArray(){
   data = new int[5]; //making a dynamic array where element need to be added
   nextIndex = 0;
   capacity = 5;
 }

 void add( int element){
   if(nextIndex == capacity){
     int *newData = new int[2*capacity]; // doubling the capacity of original data incase number
   for( int i =0 ;i<capacity;i++){ // copy elements from previous array to newly made array
     newData[i] = data[i] ;
   }
   delete data; // dellocating the previous array
   data = newData; // pointing data towards new array , so that further changes are reflected in
   capacity*=2;

 }
   data[nextIndex++] = element;
 }

 int get(int i){ // calling getter
   if(i<nextIndex){
     return data[i];
   }
   else{
     return -1;
   }
   }

 void add( int n , int element){ // for checking some conditions
   if(n<nextIndex){
     data[n]=element;
   }
   else if(n==nextIndex){
     add(element);
   }
   else{
     return;
   }
 }

 void print(){ // printing required array
   for( int i=0;i< nextIndex;i++){
     cout<<data[i]<<" ";
   }
     cout<<endl;
 }

};
int main() {
 DynamicArray d1;
 d1.add(10);
 d1.add(20);
 d1.add(30);
 d1.add(40);
 d1.add(50);
 d1.add(60);
 d1.print();
}
