class Solution {
public:
    class BIT {
    public:
        vector<int> bit;

        BIT(int n) {
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx < bit.size()) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                idx -= idx & -idx;
            }
            return ans;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {

            if (nums[i] == target)
                pref[i + 1] = pref[i] + 1;
            else
                pref[i + 1] = pref[i] - 1;
        }

        vector<int> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        BIT ft(all.size());

        long long ans = 0;

        for (int x : pref) {

            int idx = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;

            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};