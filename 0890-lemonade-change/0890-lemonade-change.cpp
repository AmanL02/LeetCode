class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] == 10 || bills[0] == 20) {
            return false;
        }

        unordered_map<int, int> mpp;
        int n = bills.size();

        for (int i = 0; i < n; i++) {
            if (bills[i] == 10) {
                if (mpp.find(5) != mpp.end() && mpp[5] > 0) {
                    mpp[5]--;
                    if (mpp[5] == 0) {
                        mpp.erase(5);
                    }
                } else {
                    return false;
                }
                mpp[bills[i]]++;
            } else if (bills[i] == 20) {
                if (mpp.find(10) != mpp.end() && mpp[10] > 0 &&
                    mpp.find(5) != mpp.end() && mpp[5] > 0) {
                    mpp[10]--;
                    mpp[5]--;
                    if (mpp[10] == 0) {
                        mpp.erase(10);
                    }
                    if (mpp[5] == 0) {
                        mpp.erase(5);
                    }
                } else if (mpp.find(5) != mpp.end() && mpp[5] >= 3) {
                    mpp[5] -= 3;
                    if (mpp[5] == 0) {
                        mpp.erase(5);
                    }
                } else {
                    return false;
                }
            } else {
                mpp[bills[i]]++;
            }
        }
        return true;
    }
};
