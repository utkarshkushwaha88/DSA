            //method 1
            //Time complexity:O((n+m) log(n+m))
#include<queue>
class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int>h;
        for(int i=0;i<n;i++){
            h.push(a[i]);
        }
        for(int i=0;i<m;i++){
            h.push(b[i]);
        }
        vector<int>ans;
        while(!h.empty()){
                ans.push_back(h.top());
                h.pop();
        }
        return ans;
        
        
    }
};


                //method 2
                // Time complexity:O(n + m)
                // Space complexity:O(n + m)

class Solution {
private:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])
            largest = left;

        if(right < n && arr[right] > arr[largest])
            largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;

        // Step 1: combine both heaps
        for(int i = 0; i < n; i++)
            ans.push_back(a[i]);

        for(int i = 0; i < m; i++)
            ans.push_back(b[i]);

        int size = ans.size();

        // Step 2: build max heap
        for(int i = size/2 - 1; i >= 0; i--){
            heapify(ans, size, i);
        }

        return ans;
    }
};