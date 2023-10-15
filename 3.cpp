#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,string::iterator> counter;
        int maxSize = 0;
        int currentSize = 0;
        auto it = s.begin();
        while (it != s.end())
        {
            auto c = *it;
            if (counter.count(c) != 0)
            {
                if (currentSize > maxSize)
                {
                    maxSize = currentSize;
                }
                it = counter.at(c);
                it++;
                counter.clear();
                currentSize = 1;
                counter.insert({*it,it});
            }
            else
            {
                counter.insert({c,it});
                currentSize++;
            }
            it++;
        }

        maxSize = (maxSize > currentSize) ? maxSize : currentSize;
        return maxSize;
    }
};
