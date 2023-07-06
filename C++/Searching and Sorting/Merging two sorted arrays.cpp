void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){

   int j=0,i=0,k=0; // starting pointers of two input and one output arrays respectively

   while(i<size1&&j<size2) { // traversing in two given arrays simultaneously 
        if(arr1[i]<arr2[j])
        {
            ans[k++]=arr1[i++];
        }

        else{
            ans[k++]=arr2[j++];
            }
                         }
    while(i<size1){
        ans[k++]=arr1[i++];
    }
    while(j<size2){
        ans[k++]=arr2[j++]; 
    }
    }
