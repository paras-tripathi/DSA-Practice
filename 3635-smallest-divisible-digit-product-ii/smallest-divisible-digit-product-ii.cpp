class Solution {
public:

    // factor[d] = number of prime factors {2,3,5,7}
    vector<vector<int>> factor = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    // Convert required prime factors into digits
    vector<int> getDigits(vector<int> cnt) {

        vector<int> digits(10, 0);

        // 2^3 -> 8
        digits[8] = cnt[0] / 3;
        cnt[0] %= 3;

        // 3^2 -> 9
        digits[9] = cnt[1] / 2;
        cnt[1] %= 2;

        // Remaining 2^2 -> 4
        digits[4] = cnt[0] / 2;
        cnt[0] %= 2;

        // Remaining 2
        digits[2] = cnt[0];

        // Remaining 3
        digits[3] = cnt[1];

        /*
            Important optimization:

            2 + 3 -> 6

            4 + 3 -> 2 + 6

            This makes the resulting number lexicographically smaller.
        */

        if (digits[2] == 1 && digits[3] == 1) {
            digits[2] = 0;
            digits[3] = 0;
            digits[6] = 1;
        }

        if (digits[3] == 1 && digits[4] == 1) {
            digits[3] = 0;
            digits[4] = 0;
            digits[2] = 1;
            digits[6] = 1;
        }

        digits[5] = cnt[2];
        digits[7] = cnt[3];

        return digits;
    }

    int countDigits(vector<int>& digits) {
        int res = 0;

        for (int d = 1; d <= 9; d++)
            res += digits[d];

        return res;
    }

    string construct(vector<int>& digits) {

        string ans;

        // Increasing order gives smallest number
        for (int d = 2; d <= 9; d++) {
            ans += string(digits[d], char('0' + d));
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // Required prime factors of t
        vector<int> need(4, 0);

        int primes[] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        // t contains a prime factor other than 2,3,5,7
        if (t != 1)
            return "-1";

        // Minimum digits needed
        vector<int> minDigits = getDigits(need);

        int minLen = countDigits(minDigits);
        int n = num.size();

        // If even the minimum representation is longer,
        // it is the answer.
        if (minLen > n) {
            return construct(minDigits);
        }

        // Count factors in num
        vector<int> prefix(4, 0);

        int firstZero = n;

        for (int i = 0; i < n; i++) {

            int d = num[i] - '0';

            if (d == 0 && firstZero == n)
                firstZero = i;

            for (int j = 0; j < 4; j++)
                prefix[j] += factor[d][j];
        }

        // num itself is valid
        if (firstZero == n) {

            bool ok = true;

            for (int j = 0; j < 4; j++) {
                if (prefix[j] < need[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        /*
            Try changing one digit.

            Start from the right because we want to keep
            the longest possible prefix unchanged.
        */

        for (int i = n - 1; i >= 0; i--) {

            int current = num[i] - '0';

            // Remove current digit from prefix
            for (int j = 0; j < 4; j++)
                prefix[j] -= factor[current][j];

            // If this is after the first zero, prefix would
            // already contain zero, so it is invalid.
            if (i > firstZero)
                continue;

            // Try the smallest larger digit
            for (int d = current + 1; d <= 9; d++) {

                vector<int> remaining(4);

                for (int j = 0; j < 4; j++) {

                    int available =
                        prefix[j] + factor[d][j];

                    remaining[j] =
                        max(0, need[j] - available);
                }

                vector<int> suffixDigits =
                    getDigits(remaining);

                int suffixLen =
                    countDigits(suffixDigits);

                int space =
                    n - i - 1;

                if (suffixLen <= space) {

                    string ans = num.substr(0, i);

                    ans += char('0' + d);

                    // Unused positions can be 1
                    ans += string(
                        space - suffixLen,
                        '1'
                    );

                    ans += construct(suffixDigits);

                    return ans;
                }
            }
        }

        /*
            No valid answer with the same length.
            Construct the smallest valid number with
            one additional digit.
        */

        return string(
            n + 1 - minLen,
            '1'
        ) + construct(minDigits);
    }
};