                                //Recursion
class Solution {
private:
    int solve(int& n, vector<int>& days, vector<int>& costs, int index){
        if(index >= n){
            return 0;
        }

        // 1-day pass
        int option1 = costs[0] + solve(n, days, costs, index + 1);

        // 7-day pass
        int i = index;
        for(; i < n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solve(n, days, costs, i);

        // 30-day pass
        i = index;
        for(; i < n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solve(n, days, costs, i);

        return min(option1, min(option2, option3));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n, days, costs, 0);
    }
};


                                //memoization

                                //S.C:-O(1)because db array is maximum length of 365 which is constant
class Solution {
private:
    int solve(int& n, vector<int>& days, vector<int>& costs,vector<int>& db, int index){
        if(index >= n){
            return 0;
        }
        if(db[index]!=-1){
            return db[index];
        }
        // 1-day pass
        int option1 = costs[0] + solve(n, days, costs,db, index + 1);

        // 7-day pass
        int i = index;
        for(; i < n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solve(n, days, costs,db, i);

        // 30-day pass
        i = index;
        for(; i < n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solve(n, days, costs,db, i);

        return db[index]= min(option1, min(option2, option3));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        vector<int>db(n+1,-1);
        return solve(n, days, costs,db, 0);
    }
};

                    //Tabulation
                    //T.C:-O(n2)

class Solution {
private:
    int solve(int& n, vector<int>& days, vector<int>& costs){
        vector<int>db(n+1,INT_MAX);
        db[n]=0;
        for(int k=n-1;k>=0;k++){
        // 1-day pass
        int option1 = costs[0] + db[k+1];

        // 7-day pass
        int i = k;
        for(; i < n && days[i] < days[k] + 7; i++);
        int option2 = costs[1] + db[i];

        // 30-day pass
        i = k;
        for(; i < n && days[i] < days[k] + 30; i++);
        int option3 = costs[2] + db[i];

        db[k]= min(option1, min(option2, option3));
        }
        return db[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        return solve(n, days, costs);
    }
};



                                //SPACE OPTIMIZED
                                //S.C:-O(1)
                                //T.C:-O(N)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;

        queue<pair<int,int>> monthly;
        queue<pair<int,int>> weekly;

        for(int day : days){

            // remove expired 30-day passes
            while(!monthly.empty() && monthly.front().first + 30 <= day){
                monthly.pop();
            }

            // remove expired 7-day passes
            while(!weekly.empty() && weekly.front().first + 7 <= day){
                weekly.pop();
            }

            // add new passes starting today
            weekly.push({day, ans + costs[1]});
            monthly.push({day, ans + costs[2]});

            // update answer
            ans = min({ans + costs[0], weekly.front().second, monthly.front().second});
        }

        return ans;
    }
};

