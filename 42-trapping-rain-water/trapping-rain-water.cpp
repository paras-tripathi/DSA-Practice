class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();
                int width = i - left - 1;
                int waterHeight = min(height[left], height[i]) - height[bottom];

                ans += width * waterHeight;
            }

            st.push(i);
        }

        return ans;
    }
};