#include<bits/stdc++.h>
class PriorityQueue {
    vector<int> pq;

   public:

    void insert(int element) {   
        pq.push_back(element);
        int currIndex = pq.size()-1;
        while (currIndex > 0) {
          int parentIndex = (currIndex - 1) / 2;
          if (pq[parentIndex] > pq[currIndex])
            return;
          swap(pq[parentIndex], pq[currIndex]);
        }
    }

    int getMax() {
        if(isEmpty()){
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        if(isEmpty()) return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int currIndex = 0;
        int rightChild = currIndex*2 + 2;
        int leftChild = currIndex*2 + 1;
        while(leftChild < pq.size()){
            int pi = currIndex; 
            if(pq[pi] < pq[leftChild])
                pi = leftChild;
            if(pq[pi] < pq[rightChild])
                    pi = rightChild;
           
            if(pi==currIndex) break;
            swap(pq[pi],pq[currIndex]);
            currIndex = pi;
            leftChild = currIndex*2 + 1;
            rightChild = currIndex*2 + 2;
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return getSize() == 0;
    }
};
