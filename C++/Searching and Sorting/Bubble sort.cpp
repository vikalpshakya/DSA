// Time complexity O(N^2) space complexity O(1) 


void bubbleSort(int *input, int size) {

  for (int  i=0 ; i < size -1 ; i++){
     for (int j = 0; j < size - 1 - i; j++) {
       if (input[j] > input[j + 1]) {
         swap(input[j], input[j + 1]);
       }
     }
  }
}
