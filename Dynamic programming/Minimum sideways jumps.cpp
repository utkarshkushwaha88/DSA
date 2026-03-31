                                //RECURSION

class Solution {
private:
    int solve(vector<int>& obstacles, int currlane, int currpos, int n) {
        
        if(currpos == n){
            return 0;
        }

        // move forward if no obstacle
        if(obstacles[currpos + 1] != currlane){
            return solve(obstacles, currlane, currpos + 1, n);
        }
        else {
            int ans = INT_MAX;

            // sideways jump
            for(int k = 1; k <= 3; k++){
                if(currlane != k && obstacles[currpos] != k){
                    ans = min(ans, 1 + solve(obstacles, k, currpos, n));
                }
            }
            return ans; 
        }
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        return solve(obstacles, 2, 0, n);
    }
};

                                    //MEMOIZATION

class Solution {
private:
    int solve(vector<int>& obstacles, int currlane, int currpos, int n,vector<vector<int>>&db) {
        
        if(currpos == n){
            return 0;
        }
        if(db[currlane][currpos]!=-1){
            return db[currlane][currpos];
        }
        // move forward if no obstacle
        if(obstacles[currpos + 1] != currlane){
            return solve(obstacles, currlane, currpos + 1, n,db);
        }
        else {
            int ans = INT_MAX;

            // sideways jump
            for(int k = 1; k <= 3; k++){
                if(currlane != k && obstacles[currpos] != k){
                    ans = min(ans, 1 + solve(obstacles, k, currpos, n,db));
                }
            }

            return db[currlane][currpos]=ans; 
        }
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>>db(4,vector<int>(obstacles.size(),-1));
        return solve(obstacles, 2, 0, n,db);
    }
};

                            //TABULATION

class Solution {
private:
    int solve(vector<int>& obstacles){
        int n = obstacles.size() - 1;
        const int INF = 1e9;

        vector<vector<int>> db(4, vector<int>(n + 1, INF));

        for(int i = 0; i <= 3; i++){
            db[i][n] = 0;
        }

        for(int currpos = n - 1; currpos >= 0; currpos--){
            for(int currlane = 1; currlane <= 3; currlane++){

                if(obstacles[currpos + 1] != currlane){
                    db[currlane][currpos] = db[currlane][currpos + 1];
                }
                else{
                    int ans = INF;

                    for(int k = 1; k <= 3; k++){
                        if(currlane != k && obstacles[currpos] != k){
                            ans = min(ans, 1 + db[k][currpos]);
                        }
                    }

                    db[currlane][currpos] = ans;
                }
            }
        }

        return min({db[2][0], 1 + db[1][0], 1 + db[3][0]});
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};


                            //SPACE OPTIIMIZED

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        const int INF = 1e9;

        vector<int> next(4, 0), curr(4, INF);

        // base case: at position n → 0 jumps
        for(int i = 1; i <= 3; i++){
            next[i] = 0;
        }

        for(int currpos = n - 1; currpos >= 0; currpos--){

            for(int currlane = 1; currlane <= 3; currlane++){

                // forward move
                if(obstacles[currpos + 1] != currlane){
                    curr[currlane] = next[currlane];
                }
                else{
                    int ans = INF;

                    // sideways jump
                    for(int k = 1; k <= 3; k++){
                        if(currlane != k && obstacles[currpos] != k){
                            ans = min(ans, 1 + curr[k]); 
                            // NOTE: use curr[k], not next[k]
                        }
                    }

                    curr[currlane] = ans;
                }
            }

            // move curr → next
            next = curr;
        }

        return min({next[2], 1 + next[1], 1 + next[3]});
    }
};