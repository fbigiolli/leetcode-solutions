#include <vector>

using namespace std;

class Solution {
public:
    int INF = 10000000;
    int N;

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() - 1,-1);
        int startFrom0 = recursion(cost,memo,0,false);
        for (int i = 0; i < memo.size(); i++)
        {
            memo[i] = -1;
        }
        
        int startFrom1 = recursion(cost,memo,1,true);

        return min(startFrom0,startFrom1);
    }

    int recursion(vector<int>& cost, vector<int>& memo, int pos, bool twoSteps){

        if (pos == cost.size() && twoSteps)
        {
            return 0;
        }

        if (pos >= cost.size()) // fuera de rango, no tiene sentido la solucion
        {
            return INF;
        }

        if (pos == cost.size() - 1) // llegue a la ultima posicion, tengo que dar el ultimo paso sumando el costo
        {
           return cost[pos];
        }

        if (memo[pos] != -1)
        {
            return memo[pos];
        }
        
        else
        {
            int oneStep = recursion(cost,memo,pos+1,false);
            int twoSteps = recursion(cost,memo,pos+2,true); 
            int res = min(cost[pos] + oneStep, cost[pos] + twoSteps);
            memo[pos] = res;
        }
        
        return memo[pos];
    }

};