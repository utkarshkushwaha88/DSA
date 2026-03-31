#include<queue>
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int k = mat.size();
        
        vector<int> ans;
        
        // min heap -> {value, row, col}
        priority_queue<
            tuple<int,int,int>, 
            vector<tuple<int,int,int>>, 
            greater<tuple<int,int,int>>
        > pq;
        
        // push first element of each row
        for(int i = 0; i < k; i++){
            pq.push({mat[i][0], i, 0});
        }
        
        while(!pq.empty()){
            auto [val, r, c] = pq.top();
            pq.pop();
            
            ans.push_back(val);
            
            if(c + 1 < mat[r].size()){
                pq.push({mat[r][c+1], r, c+1});
            }
        }
        
        return ans;
    }
};