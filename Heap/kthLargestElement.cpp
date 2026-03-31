// Time complexity  O(n log k)
// Space Complexity  O(k)
#include<queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> h;
        int size = nums.size();
        for(int i=0;i<k;i++){
            h.push(nums[i]);
        }
        for(int i=k;i<size;i++){
            if(nums[i]>h.top()){
                h.pop();
                h.push(nums[i]);
            }
        }
        return h.top();
    }
};