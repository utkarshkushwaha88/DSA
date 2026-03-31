            //METHOD 1
            //TIME COMPLEXITY :O(n2logn)
            //SPACE COMPLEXITY:O(n2)

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int>sumStore;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                sumStore.push_back(sum);
            }
        }
        sort(sumStore.begin(),sumStore.end());
        int size=sumStore.size();
        return sumStore[size-k];
    }
};



                        //METHOD 2
                        //TIME COMPLEXITY:O(N2LOGN)
                        //SPACE COMPLEXITY:O(K)

// User function Template for C++
#include<queue>

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> h;
        vector<int>sumStore;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(h.size()<k){
                    h.push(sum);
                }
                else{
                    if(sum>h.top()){
                        h.pop();
                        h.push(sum);
                    }
                }
            }
        }
        return h.top();
        
    }
};
