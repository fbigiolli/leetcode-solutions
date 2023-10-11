#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> trustPerPerson(n + 1,vector<int>(2,0));
        for (auto trustPair:trust)
        {
            int p1 = trustPair[0];
            int p2 = trustPair[1];

            trustPerPerson[p1][0]++;
            trustPerPerson[p2][1]++;
        }

        int res = -1;
        for (int i = 0; i < trustPerPerson.size(); i++)
        {
            if(trustPerPerson[i][0] == 0 && trustPerPerson[i][1] == n - 1) res = i;
        }

        return res;
    }
};