/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters. */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        string subset = "";
        vector<string> result;
        dfs(digits, subset, 0, result);
        return result;
    }

private:
    unordered_map<char, string> M = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(string& digits, string& subset, int index, vector<string>& result) {
        if (subset.size() == digits.size()) {
            result.push_back(subset);
            return;
        }

        string& str = M[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            subset.push_back(str[i]);
            dfs(digits, subset, index + 1, result);
            subset.pop_back();
        }
    }
};
