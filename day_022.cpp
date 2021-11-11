
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
string replaceSpace(string s)
{
    string ret;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ret += "%20";
        } else {
            ret += s[i];
        }
    }

    return ret;
}

// https://leetcode-cn.com/problems/sparse-array-search-lcci/
int findString(vector<string> &words, string s)
{
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "") {
            continue;
        } else if (words[i] ==  s) {
            return i;
        }
    }

    return -1;
}

// https://leetcode-cn.com/problems/word-pattern/
bool wordInArr(string* arr, int size, string s)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == s) {
            return true;
        }
    }

    return false;
}

bool wordPattern(string pattern, string s)
{
    s += " ";
    string arr[26] = {""};
    string temp = "";

    int index = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (index >= pattern.size())
                return false;

            if (arr[pattern[index] - 'a'] == "")
            {
                if (wordInArr(arr, 26, temp))
                {
                    return false;
                }

                arr[pattern[index] - 'a'] = temp;
            }
            else if (arr[pattern[index] - 'a'] != temp)
            {
                return false;
            }

            index++;
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    if (index != pattern.size())
        return false;

    return true;
}

// https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
string freqAlphabets(string s)
{
    string ret;

    for (int i = s.size() - 1; i >= 0; ) {
        if (s[i] == '#') {
            ret = (char)((s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1 + 'a') + ret;
            i -= 3;
        } else {
            ret = (char)(s[i] - '1' + 'a') + ret;
            i--;
        }
    }

    return ret;
}

// https://leetcode-cn.com/problems/number-of-strings-that-appear-as-substrings-in-word/
int numOfStrings(vector<string> &patterns, string word)
{
    int ret = 0;

    for (int i = 0; i < patterns.size(); i++) {
        if (word.find(patterns[i]) != string::npos) 
            ret++;
    }

    return ret;
}

int main()
{
    /*
    vector<string> strArray;
    strArray.push_back("a");
    strArray.push_back("b");
    strArray.push_back("c");

    printf("numOfStrings: %d \r\n", numOfStrings(strArray, "aaaaabbbbb"));

    printf("freqAlphabets: %s \r\n", freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#").data());

    printf("wordPattern: %d \r\n", wordPattern("aaa", "aa aa aa aa"));

    vector<string> strArray;
    strArray.push_back("at");
    strArray.push_back("");
    strArray.push_back("");
    strArray.push_back("");
    strArray.push_back("ball");
    strArray.push_back("");
    strArray.push_back("");
    strArray.push_back("car");
    strArray.push_back("");
    strArray.push_back("");
    strArray.push_back("dad");
    strArray.push_back("");
    strArray.push_back("");

    printf("replaceSpace: %d \r\n", findString(strArray , "ball"));

    printf("replaceSpace: %s \r\n", replaceSpace("We are happy.").data());
    */
}