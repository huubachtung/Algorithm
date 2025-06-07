//Lexicographically Minimum String After Removing Stars
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> removed(n, false);
        vector<vector<int>> buckets(26);

        // 1) One pass: mark removals
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                // remove the star itself
                removed[i] = true;
                // find & remove the smallest char to its left
                for (int c = 0; c < 26; ++c) {
                    if (!buckets[c].empty()) {
                        removed[buckets[c].back()] = true;
                        buckets[c].pop_back();
                        break;
                    }
                }
            } else {
                // record this letter's index
                buckets[s[i] - 'a'].push_back(i);
            }
        }

        // 2) Rebuild result from all indices not marked removed
        string result;
        result.reserve(n);  // at most n chars
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

// Add a main function for testing
int main() {
    Solution solution;
    string test = "a*b*c";
    cout << "Input: " << test << endl;
    cout << "Output: " << solution.clearStars(test) << endl;
    return 0;
}