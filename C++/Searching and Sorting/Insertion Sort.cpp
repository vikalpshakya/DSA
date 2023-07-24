// Time complexity O(N^2) space complexity O(1)

void insertionSort(int *input, int size){
  for (int i=1;i<size;i++){
    int current=input[i],j;
    for(j=i-1;j>=0;j--){
      if (input[j] > current) {
        input[j + 1] = input[j];
      } else
        break;
    }input[j+1]=current;
  }  
}
