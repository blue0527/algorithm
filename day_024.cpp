
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

// https://leetcode-cn.com/problems/is-unique-lcci/
bool isUnique(string astr) {

    int flag = 0;
    for(int i = 0; i < astr.size(); i++) {
        if (flag & (1 << (astr[i] - 'a'))) 
            return false;

        flag |= (1 << (astr[i] - 'a')); 
    }

    return true;
}

// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
char firstUniqChar(string str) {

    if (str.size() == 0) return ' ';

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < str.size(); i++) {
        flag[str[i] - 'a']++;
    }

    for(int i = 0; i < str.size(); i++) {
        if (flag[str[i] - 'a'] == 1) 
            return str[i];
    }

    return ' ';
}

// https://leetcode-cn.com/problems/ransom-note/
bool canConstruct(string ransomNote, string magazine) {

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < magazine.size(); i++) {
        flag[magazine[i] - 'a']++;
    }

    for(int i = 0; i < ransomNote.size(); i++) {
        if (flag[ransomNote[i] - 'a'] == 0)
            return false;

        flag[ransomNote[i] - 'a']--;
    }

    return true;
}

// https://leetcode-cn.com/problems/jewels-and-stones/
int numJewelsInStones(string jewels, string stones) {

    uint16_t lowercase[26] = { 0 }, uppercase[26] = { 0 };
    int count = 0;  

    for(int i = 0; i < jewels.size(); i++) {
        if (jewels[i] >= 'a')
            lowercase[jewels[i] - 'a']++;
        else
            uppercase[jewels[i] - 'A']++;
    }

    for(int i = 0; i < stones.size(); i++) {
        if (stones[i] >= 'a' && lowercase[stones[i] - 'a'] != 0)
            count++;
        else if (stones[i] < 'a' && uppercase[stones[i] - 'A'] != 0)
            count++;
    }

    return count;
}

// https://leetcode-cn.com/problems/check-permutation-lcci/
bool CheckPermutation(string s1, string s2) {

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < s1.size(); i++) {
        flag[s1[i] - 'a']++;
    }

    for(int i = 0; i < s2.size(); i++) {
        if (flag[s2[i] - 'a'] == 0)
            return false;

        flag[s2[i] - 'a']--;
    }

    return true;
}

// https://leetcode-cn.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
bool areOccurrencesEqual(string s) {

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < s.size(); i++) {
        flag[s[i] - 'a']++;
    }

    int count = 0;
    for(int i = 0; i < 26; i++) {
        if (flag[i] != 0) {
            if (count == 0) {
                count = flag[i];
            } else if (count != flag[i]) {
                return false;
            }
        }
    }

    return true;
}

// https://leetcode-cn.com/problems/valid-anagram/
bool isAnagram(string s, string t) {

    if (s.size() != t.size()) return false;

    if (strcmp(s.data(), t.data()) == 0) return false;

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < s.size(); i++) {
        flag[s[i] - 'a']++;
    }

    for(int i = 0; i < t.size(); i++) {
        if (flag[t[i] - 'a'] == 0)
            return false;

        flag[t[i] - 'a']--;
    }

    return true;
}

// https://leetcode-cn.com/problems/dKk3P7/
bool isAnagram1(string s, string t) {

    if (s.size() != t.size()) return false;

    if (strcmp(s.data(), t.data()) == 0) return false;

    uint16_t flag[26] = { 0 };
    for(int i = 0; i < s.size(); i++) {
        flag[s[i] - 'a']++;
    }

    for(int i = 0; i < t.size(); i++) {
        if (flag[t[i] - 'a'] == 0)
            return false;

        flag[t[i] - 'a']--;
    }

    return true;
}

// https://leetcode-cn.com/problems/check-if-the-sentence-is-pangram/
bool checkIfPangram(string sentence) {

    uint32_t flag = 0;
    for(int i = 0; i < sentence.size(); i++) {
        flag |= (1 << (sentence[i] - 'a'));
    }

    printf("%x \r\n", flag);

    return flag == 0x3ffffff;
}

// https://leetcode-cn.com/problems/kth-distinct-string-in-an-array/
string kthDistinct(vector<string>& arr, int k) {
    
    map<string, int> map;

    for (int i = 0; i < arr.size(); i++) {
        map[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (map[arr[i]] == 1 && --k == 0) 
            return arr[i];
    }

    return "";
}

int main() {

    /*

    vector<string> strArray;
    strArray.push_back("d");
    strArray.push_back("b");
    strArray.push_back("c");
    strArray.push_back("b");
    strArray.push_back("c");
    strArray.push_back("a");
    printf("kthDistinct: %s \r\n", kthDistinct(strArray, 2).data());

    printf("checkIfPangram: %d \r\n", checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));

    printf("isAnagram: %d \r\n", isAnagram("a", "a"));

    printf("isAnagram: %d \r\n", isAnagram("ab", "a"));

    printf("areOccurrencesEqual: %d \r\n", areOccurrencesEqual("aaabb"));

    printf("CheckPermutation: %d \r\n", CheckPermutation("abc", "bad"));

    printf("numJewelsInStones: %d \r\n", numJewelsInStones("z", "ZZ"));

    printf("canConstruct: %d \r\n", canConstruct("aa", "aab"));

    printf("firstUniqChar: %c \r\n", firstUniqChar("leetcode"));

    printf("isUnique: %d \r\n", isUnique("leetcode"));
    */

    return 0;
}
