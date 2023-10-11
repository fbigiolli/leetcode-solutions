#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int j = 0; j < nums.size(); j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i != j && nums[i] + nums[j] == target)
                {
                    res.push_back(j);
                    res.push_back(i);
                    return res; 
                }
            }
        }
        return res; 
    }
};