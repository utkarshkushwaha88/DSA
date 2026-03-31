class Solution {
private:
    int checkHeight(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int left = checkHeight(root->left);
        if(left == -1) return -1;

        int right = checkHeight(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) {
            return -1;
        }

        return 1 + max(left, right);
    }

public:
    bool isBalanced(Node* root) {
        return checkHeight(root) != -1;
    }
};

// 📊 Complexity

// Time: O(n)
// Space: O(h) recursion stack

// Worst case: O(n) (skewed tree)
// Best case: O(log n) (balanced tree)


                //METHOD 2
                
                

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};