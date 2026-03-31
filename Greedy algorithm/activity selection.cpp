class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }

    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        int n = start.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({start[i], finish[i]});
        }

        sort(v.begin(), v.end(), cmp);

        int cnt = 1;
        int endTime = v[0].second;

        for(int i = 1; i < n; i++){
            if(v[i].first > endTime){ 
                cnt++;
                endTime = v[i].second;
            }
        }

        return cnt;
    }
};