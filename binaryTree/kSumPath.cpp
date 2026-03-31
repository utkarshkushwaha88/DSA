class Solution {
private:
    void solve(Node* root, long long currSum, int k, 
               unordered_map<long long,int>& mp, int &count) {
        
        if(root == NULL) return;

        // Add current node to prefix sum
        currSum += root->data;

        // If currSum itself equals k
        if(currSum == k)
            count++;

        // Check if (currSum - k) was seen before
        if(mp.find(currSum - k) != mp.end()) {
            count += mp[currSum - k];
        }

        // Store current prefix sum
        mp[currSum]++;

        // Recurse
        solve(root->left, currSum, k, mp, count);
        solve(root->right, currSum, k, mp, count);

        // Backtrack
        mp[currSum]--;
    }

public:
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        int count = 0;
        solve(root, 0, k, mp, count);
        return count;
    }
};
⏱ Time Complexity
O(N)

Each node visited once.

📦 Space Complexity
O(N)

For hashmap + recursion stack.


            //METHOD 2

class Solution {
private:
    void solve(TreeNode* root,int targetSum,int &count,vector<int>&path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        solve(root->left,targetSum,count,path);
        solve(root->right,targetSum,count,path);
        long long int size=path.size();
        long long int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum){
                count++;
            }
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
         int count=0;
        vector<int> path;
        solve(root,targetSum,count,path);
        return count;
    }
};

Total complexity:

O(N²)