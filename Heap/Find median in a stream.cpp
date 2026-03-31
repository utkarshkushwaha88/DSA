
                    // Time complexity:O(N log N)
                    // Space Complexity:O(N)

#include <queue>
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        
        priority_queue<int> maxHeap; // left side
        priority_queue<int, vector<int>, greater<int>> minHeap; // right side
        
        vector<double> ans;
        
        for(int num : arr){
            
            if(maxHeap.empty() || num <= maxHeap.top()){
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
            
            // balance heaps
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // calculate median
            if(maxHeap.size() == minHeap.size()){
                ans.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            }
            else{
                ans.push_back(maxHeap.top());
            }
        }
        
        return ans;
    }
};




                    //SIMILAR TO ABOVE IN LEET CODE 


#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // step 1: push into max heap
        left.push(num);
        
        // step 2: balance order
        right.push(left.top());
        left.pop();
        
        // step 3: maintain size property
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        
        if(left.size() == right.size()){
            return (left.top() + right.top()) / 2.0;
        }
        
        return left.top();
    }
};