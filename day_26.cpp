
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

// https://leetcode-cn.com/problems/palindrome-permutation-lcci/
bool canPermutePalindrome(string s)
{
    uint16_t arr[128] = { 0 };
    bool hasOne = false;

    for (int i = 0; i < s.size(); i++) {
        arr[s[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        if (arr[i] % 2 == 1) {
            if (!hasOne) {
                hasOne = true;
                continue;
            } else {
                return false;
            }
        }

        if (arr[i] % 2 != 0)
            return false;
    }

    return true;
}

// https://leetcode-cn.com/problems/XltzEq/
bool isPalindrome(string s)
{
    if (s.size() == 0) return true;
    string strip;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
        }

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            continue;

        s[i] = ' ';
    }

    printf("new s: %s \r\n", s.data());

    int left = 0, right = s.size() - 1;

    while (left < right) {

        if (s[left] == ' ') {
            left++;
            continue;
        }

        if (s[right] == ' ') {
            right--;
            continue;
        }

        if (s[left] != s[right]) {
            printf("%c - %c \r\n", s[left], s[right]);
            return false;
        }

        left++;
        right--;
    }

    return true;
}

// https://leetcode-cn.com/problems/valid-palindrome/submissions/
// 同上

// https://leetcode-cn.com/problems/longest-palindrome/
int longestPalindrome(string s)
{
    uint16_t arr[128] = {0};
    int count = 0;
    bool hasOne = false;
    for (int i = 0; i < s.size(); i++) {
        arr[s[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        if (arr[i] % 2 == 0) {
            count += arr[i];
        } else {
            count += (arr[i] - 1);
            hasOne = true;
        }
    }

    if (hasOne) count++;

    return count;
}

// https://leetcode-cn.com/problems/RQku0D/
bool valid(const string& s, int left, int right) {

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

bool validPalindrome(string s) {

    int left = 0, right = s.size() - 1;

    while (left < right) {

        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            break;
        }
    }

    return valid(s, left+1, right) || valid(s, left, right-1);
}

// https://leetcode-cn.com/problems/valid-palindrome-ii/
// 同上

// https://leetcode-cn.com/problems/shortest-palindrome/
// 看不懂，记录一下
string shortestPalindrome(string s) {
    const int M = 1e9 + 7;

    int n = s.size();
    if (n <= 1) {
        return s;
    }
    int best = 0;

    int left = 0;
    int right = 0;
    long long base = 1;

    for (int i = 0; i < n; i++) {
        left = ((long long)left * 26 + s[i] - 'a') % M;
        right = ((long long)right + base * (s[i] - 'a')) % M;

        if (left == right) {
            best = i + 1;
        }
        base *= 26;
        base %= M;
    }

    string t = s.substr(best);
    std::reverse(t.begin(), t.end());

    return t + s;
}

int main() {
    /*
    printf("shortestPalindrome: %s \r\n", shortestPalindrome("aacecaaa").data());

    printf("validPalindrome: %d \r\n", validPalindrome("abc"));

    printf("longestPalindrome: %d \r\n", longestPalindrome("ccc"));

    printf("isPalindrome: %d \r\n", isPalindrome("A man, a plan, a canal:
    Panama"));

    printf("canPermutePalindrome: %d \r\n", canPermutePalindrome("code"));
    */
    return 0;
}
