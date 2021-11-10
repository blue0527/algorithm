
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square
bool squareIsWhite(string coordinates)
{
    return ((coordinates[0] - 'a') % 2) ^ ((coordinates[1] - '1') % 2);
}

// https://leetcode-cn.com/problems/nGK0Fy/
int calculate(string s)
{
    /*
    int x = 1, y = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') {
            x = 2*x + y;
        } else {
            y = 2*y + x;
        }
    }

    return x + y;
    */

   return 1 << s.size();
}

// https://leetcode-cn.com/problems/final-value-of-variable-after-performing-operations/
int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][1] == '+') 
            x++;
        else
            x--;
    }

    return x;
}

// https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters/
int countGoodSubstrings(string s)
{
    int count = 0;

    for (int i = 0; i < (int)s.size() - 2; i++) {
        if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2])
            count++;
    }

    return count;
}

// https://leetcode-cn.com/problems/detect-capital/
bool isCapital(char c) {
    return c >= 'A' && c <= 'Z';
}

bool detectCapitalUse(string word) {

    bool isFirstCapital = isCapital(word[0]);
    bool hasLowercase = !isFirstCapital;
    bool hasCapital = false;

    for (int i = 1; word[i]; i++) {

        if (isCapital(word[i])) {
            if (hasLowercase)
                return false;
            hasCapital = true;
        } else {
            if (hasCapital)
                return false;
            hasLowercase = true;
        }
    }

    return true;
}

// https://leetcode-cn.com/problems/to-lower-case/
/*
大写变小写、小写变大写 : 字符 ^= 32;
大写变小写、小写变小写 : 字符 |= 32;
小写变大写、大写变大写 : 字符 &= -33;
*/
string toLowerCase(string s)
{
    string ret;

    for (int i = 0; s[i]; i++) {
        ret += ( isCapital(s[i]) ? (char)(s[i] + 32) : s[i] );
    }

    return ret;
}

// https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/
bool isVowels(char c) {
    char cArr[] = "aeiouAEIOU";

    for (int i = 0; cArr[i]; i++) {
        if (c == cArr[i]) 
            return true;
    }

    return false;
}

bool halvesAreAlike(string s) {

    int leftSum = 0, rightSum = 0;
    int mid = s.size() / 2;

    for (int i = 0; s[i]; i++) {

        if (isVowels(s[i])) {
            if (i < mid) 
                leftSum++;
            else
                rightSum++;
        }
    }

    return leftSum == rightSum;
}

// https://leetcode-cn.com/problems/replace-all-digits-with-characters/
string replaceDigits(string s)
{
    for (int i = 1; s.size(); i += 2) {
        s[i] = s[i-1] + (s[i] - '0');
    }

    return s;
}

// https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/
void pushIfNoExist(vector<string>& arr, string str) {

    bool flag = false;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == str)
            flag = true;
    }

    if (!flag) {
        arr.push_back(str);
    }
}

int numDifferentIntegers(string word)
{
    vector<string> arr;
    string str = "";

    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= '0' && word[i] <= '9') {
            
            if (str[0] == '0')  {
                str = word[i];
            } else {
                str += word[i];
            }

        } else {
            if (str.size() != 0) {
                pushIfNoExist(arr, str);
            }
            str = "";
        }
    }

    if (str.size() != 0)  {
        pushIfNoExist(arr, str);
    }

    return arr.size();
}

int main()
{
    /*
    printf("numDifferentIntegers: %d \r\n", numDifferentIntegers("167278959591294"));

    printf("replaceDigits: %s \r\n", replaceDigits("m3g6w0q8z0s1c7").data());

    printf("halvesAreAlike: %d \r\n", halvesAreAlike("AbCdEfGh"));

    printf("toLowerCase: %s \r\n", toLowerCase("Hello").data());

    printf("detectCapitalUse: %d \r\n", detectCapitalUse("AAA"));

    printf("countGoodSubstrings: %d \r\n", countGoodSubstrings("x"));

    vector<string> strArray;
    strArray.push_back("X++");
    strArray.push_back("++X");
    strArray.push_back("--X");
    strArray.push_back("X--");
    printf("finalValueAfterOperations: %d \r\n", finalValueAfterOperations(strArray));

    printf("calculate: %d \r\n", calculate("AB"));

    printf("squareIsWhite: %d \r\n", squareIsWhite("c7"));
    */

    return 0;
}