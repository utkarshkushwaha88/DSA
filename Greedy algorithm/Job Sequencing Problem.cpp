class Solution {
public:
    
    // DSU Find with path compression
    int find(int x, vector<int> &parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({deadline[i], profit[i]});
        }

        // sort by profit descending
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        int maxDeadline = 0;
        for(auto &job : v){
            maxDeadline = max(maxDeadline, job.first);
        }

        // DSU parent
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++){
            parent[i] = i;
        }

        int cnt = 0;
        int totalProfit = 0;

        for(auto &job : v){
            int availableSlot = find(job.first, parent);

            if(availableSlot > 0){
                cnt++;
                totalProfit += job.second;

                // occupy this slot → merge with previous
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        return {cnt, totalProfit};
    }
};