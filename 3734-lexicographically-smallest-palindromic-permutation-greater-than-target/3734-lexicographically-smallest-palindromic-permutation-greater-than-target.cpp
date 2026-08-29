class Solution {
public:
    bool check(const vector<int>& count) {
        int odd_count = 0;
        for (int c : count) {
            if (c % 2 != 0) odd_count++;
        }
        return odd_count <= 1;
    }

    bool compare(const string& s1, const string& s2) {
        return s1 > s2;
    }

    string mirror(string left, char mid, int n) {
        string right = left;
        reverse(right.begin(), right.end());
        if (mid != 0) {
            return left + mid + right;
        }
        return left + right;
    }

    bool backtrack(int idx, int half_len, string& current_half, vector<int>& count, 
                   char mid_char, const string& target, bool is_greater, string& result) {
        if (idx == half_len) {
            string full_palindrome = mirror(current_half, mid_char, target.length());
            if (full_palindrome > target) {
                result = full_palindrome;
                return true; // Found the lexicographically smallest valid palindrome
            }
            return false;
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                char ch = 'a' + i;
                if (!is_greater && ch < target[idx]) continue;

                count[i]--;
                current_half.push_back(ch);

                bool next_is_greater = is_greater || (ch > target[idx]);
                if (backtrack(idx + 1, half_len, current_half, count, mid_char, target, next_is_greater, result)) {
                    return true;
                }

                current_half.pop_back();
                count[i]++;
            }
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        if (!check(count)) return "";

        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                mid_char = 'a' + i;
                count[i]--;
                break;
            }
        }

        for (int i = 0; i < 26; ++i) {
            count[i] /= 2;
        }

        int half_len = n / 2;
        string current_half = "";
        string result = "";

        backtrack(0, half_len, current_half, count, mid_char, target, false, result);

        return result;
    }
};