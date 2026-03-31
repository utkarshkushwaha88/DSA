class Solution {
  public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second; 
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>>v;
        for(int i=0;i<start.size();i++){
            pair<int,int>p=make_pair(start[i],end[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        int count=1;
        
        int ansEnd=v[0].second;
        for(int i=1 ;i<v.size();i++){
            if(v[i].first>ansEnd){
                count++;
                ansEnd=v[i].second;
            }  
        }
        
        return count;
    }
};