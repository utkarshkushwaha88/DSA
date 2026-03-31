class Solution {
public:
    static bool cmp(pair<double, pair<int,int>> a,
                    pair<double, pair<int,int>> b){
        return a.first > b.first; // sort by value/weight ratio
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        vector<pair<double, pair<int,int>>> v;

        // store (value/weight, (value, weight))
        for(int i = 0; i < val.size(); i++){
            double perUnitValue = (double)val[i] / wt[i];
            v.push_back({perUnitValue, {val[i], wt[i]}});
        }

        sort(v.begin(), v.end(), cmp);

        double totalValue = 0.0;

        for(int i = 0; i < v.size(); i++){
            int currVal = v[i].second.first;
            int currWt  = v[i].second.second;

            if(currWt <= capacity){
                totalValue += currVal;
                capacity -= currWt;
            }
            else{
                // take fraction
                totalValue += (double)capacity * v[i].first;
                break;
            }
        }

        return totalValue;
    }
};