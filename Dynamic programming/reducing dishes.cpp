                                //RECURSION


class Solution {
private:
    int solve(vector<int>& satisfaction,int index,int time){
        if(index==satisfaction.size()){
            return 0;
        }
        int include=satisfaction[index]*(time+1) + solve(satisfaction,index+1,time+1);
        int exclude=0+solve(satisfaction,index+1,time);
        return max(include,exclude);

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);
    }
};

                            //MEMOIZATION
        
class Solution {
private:
    int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>>&db){
        if(index==satisfaction.size()){
            return 0;
        }
        if(db[index][time]!=-1){
            return db[index][time];
        }
        int include=satisfaction[index]*(time+1) + solve(satisfaction,index+1,time+1,db);
        int exclude=0+solve(satisfaction,index+1,time,db);
        return db[index][time]= max(include,exclude);

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>db(n+1,vector<int>(n+1,-1));
        return solve(satisfaction,0,0,db);
    }
};  


                            //TABULATION


class Solution {
private:
    int solve(vector<int>& satisfaction){
        int n = satisfaction.size();
        
        vector<vector<int>> db(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int time = index; time >= 0; time--){
                
                int include = satisfaction[index] * (time + 1) + db[index+1][time+1];
                int exclude = db[index+1][time];

                db[index][time] = max(include, exclude); 
            }
        }

        return db[0][0]; 
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};


                                    //SPACE OPTIMIZED

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for(int index = n-1; index >= 0; index--){
            for(int time = index; time >= 0; time--){
                int include = satisfaction[index] * (time + 1) + next[time+1];
                int exclude = next[time];
                curr[time] = max(include, exclude); 
            }
                next=curr;
        }

        return next[0];
    }
};


                            //SPACE OPTIMIZED TO O(1)


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int suffixSum = 0;
        int total = 0;

        for(int i = satisfaction.size() - 1; i >= 0; i--){
            suffixSum += satisfaction[i];

            if(suffixSum < 0) break;

            total += suffixSum;
        }

        return total;
    }
};


// 🔥 Comparison
// Approach	                Time	                    Space
// Recursion	            Exponential	                    O(n)
// Memoization	                O(n²)	                    O(n²)
// Tabulation	                O(n²)	                    O(n²)
// Space Opt DP	            O(n²)	                    O(n)
// Greedy (Best)	            O(n log n)	                O(1) 