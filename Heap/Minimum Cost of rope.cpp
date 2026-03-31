                //method 1
                // Time ComplexityO(n log n)
                // Space Complexity:O(n)

#include<queue>
class Solution {
  public:
    int minCost(vector<int>& arr) {
      
        priority_queue<int, vector<int>, greater<int>>h;
        int size=arr.size();
        if(size==1 || size==0){
            return 0;
        }
        for(int i=0;i<size;i++){
            h.push(arr[i]);
        }
        int sum=0;
        while(h.size() > 1){
            int first=h.top();
            h.pop();
            int second=h.top();
            h.pop();
            int cost=first+second;
            sum=sum+cost;
            h.push(cost);
        }
          return sum;
    }
};