class Solution {
public:
map<int, int> memo; 
    int tribonacci(int n) {
        if (memo.find(n) != memo.end()) { 
            return memo[n];
        }

        int result;
        if (n == 0) {
            result = 0;
        } else if (n == 1 || n == 2) {
            result = 1;
        } else {
            result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }

        memo[n] = result;
        return result;
    }
    
};