                    // TIME COMPLEXITY O(nlogk)
                    // SPACE COMPLEXITY O(k)
#include<queue>
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>h;
        int size=arr.size();
        for(int i=0;i<k;i++){
            h.push(arr[i]);
        }
        
        for(int i=k;i<size;i++){
            if(arr[i]<h.top()){
                h.pop();
                h.push(arr[i]);
            }
        }
        return h.top();
    }
};
