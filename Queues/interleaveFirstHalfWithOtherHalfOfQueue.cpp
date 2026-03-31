class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        vector<int> ans;
        int n=q.size();
        int i=0;
        int  j=n/2;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        while(i<j && j<n){
            q.push(ans[i]);
            q.push(ans[j]);
            i++;
            j++;
        }
        
    }
};