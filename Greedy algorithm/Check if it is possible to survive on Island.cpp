class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // Daily survival impossible
        if(M > N) return -1;
        
        // Apply weekly check ONLY if Sunday exists
        if(S >= 7 && (6 * N) < (7 * M)) return -1;
        
        int sunday = S / 7;
        int buyingDays = S - sunday;
        
        int totalFood = S * M;
        
        int ans = (totalFood + N - 1) / N; // ceil
        
        if(ans <= buyingDays) {
            return ans;
        } else {
            return -1;
        }
    }
};