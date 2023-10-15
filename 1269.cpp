#include <vector>
using namespace std;

class Solution {
public:
    long long recursion(int remainingSteps, int arrLen, int currentPos, vector<vector<long long>>& memo) {
        if (currentPos < 0 || currentPos > arrLen - 1) {
            return 0;
        }

        if (remainingSteps == 0) {
            return (currentPos == 0) ? 1 : 0;
        }

        if (memo[currentPos][remainingSteps] != -1) {
            return memo[currentPos][remainingSteps];
        } else {
            long long left = recursion(remainingSteps - 1, arrLen, currentPos - 1, memo);
            long long stay = recursion(remainingSteps - 1, arrLen, currentPos, memo);
            long long right = recursion(remainingSteps - 1, arrLen, currentPos + 1, memo);
            memo[currentPos][remainingSteps] = (left + stay + right) % 1000000007LL;
        }

        return memo[currentPos][remainingSteps];
    }

    int numWays(int steps, int arrLen) {
        vector<vector<long long>> memo(min(arrLen, steps), vector<long long>(steps + 1, -1));
        long long res = recursion(steps, arrLen, 0, memo) % 1000000007LL;
        return static_cast<int>(res);
    }
};
