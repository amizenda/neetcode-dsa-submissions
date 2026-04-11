class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> checker;
        for(int x : nums) {
            if(checker.count(x)) return true;
            checker.insert(x);
        }

        return false;
    }
};