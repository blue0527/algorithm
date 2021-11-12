
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// https://leetcode-cn.com/problems/length-of-last-word
int lengthOfLastWord(string s) {

    int length = 0;

    for (int i = s.size()-1; i >= 0; i--) {

        if (s[i] != ' ') {
            length++;
        } else if (length != 0) {
            return length;
        }
    }

    return length;
}

// https://leetcode-cn.com/problems/number-of-segments-in-a-string
int countSegments(string s) {

    int num = 0;
    bool hasWord = false;

    for (int i = 0; i < s.size(); i++) {

        if ((s[i] != ' ')) {
            hasWord = true;
        } else if (hasWord) {
            num++;
            hasWord = false;
        }
    }

    if (hasWord)
        num++;

    return num;
}

// https://leetcode-cn.com/problems/check-if-numbers-are-ascending-in-a-sentence
bool areNumbersAscending(string s) {

    int last = 0, temp = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] >= '0' && s[i] <= '9') {
            temp = temp*10 + (s[i] - '0');
        } 
        if ((s[i] == ' ' || (i == s.size() - 1)) && temp != 0) {
            if (temp <= last) 
                return false;

            last = temp;
            temp = 0;
        }
    }

    return true;
}
    
// https://leetcode-cn.com/problems/number-of-valid-words-in-a-sentence
// [a-z]+-?[a-z]+[!.,]?
int countValidWords(string sentence) {
        
    int count = 0;
    bool hasWord = false, has2D = false, isValid = true, lastIsSpace = false;

    for (int i = 0; i < sentence.size(); i++) {

        if (sentence[i] == ' ') {

            if (i != 0 && !lastIsSpace && isValid) {
                count++;
            }
                
            has2D = false;
            isValid = true;
            lastIsSpace = true;

            continue;
        }

        lastIsSpace = false;

        if (!isValid)
            continue;

        if (sentence[i] >= '0' && sentence[i] <= '9') {
            isValid = false;
            continue;
        }

        if (sentence[i] == '-') {  
            
            if (has2D || i == 0 || i == sentence.size() - 1 ||
                    (sentence[i-1] < 'a' || sentence[i-1] > 'z') || 
                    (sentence[i+1] < 'a' || sentence[i+1] > 'z')) {
                isValid = false;
                continue;
            }

            has2D = true;
        }
        
        if ((sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',') && 
                ((i != sentence.size() - 1 && sentence[i+1] != ' '))) {
            isValid = false;
            continue;
        }
    }

    if (!lastIsSpace && isValid) 
        count++;

    return count;
}

// https://leetcode-cn.com/problems/truncate-sentence
string truncateSentence(string s, int k) {

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == ' ' && --k == 0) {
            return s.substr(0, i);
        }
    }

    return s;
}

// https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
bool checkOnesSegment(string s) {

    for (int i = 1; i < s.size(); i++) {
        if (s[i] > s[i-1])
            return false;
    }

    return true;
}

// https://leetcode-cn.com/problems/validate-ip-address/
// ipv4 /^()(\d|[1-9]\d|1\d\d|2([0-4]\d|5[0-5]))\.){4}$/
// ipv6 /^(([\da-fA-F]{1,4}):){8}$/
bool isIPV4(string queryIP) {

    bool isWord = false;
    int  v4Num = 0, v4Sum = 0, part = 0;
    char curr;

    for (int i = 0; i < queryIP.size(); i++) {
        
        curr = queryIP[i];

        if (curr == ':') 
            return false;

        if (curr != '.') {
            if (++v4Num > 3 || (v4Num > 1 && v4Sum == 0)
                || (curr < '0' || curr > '9')) {
                return false;
            }
            
            v4Sum = v4Sum*10 + (curr - '0');
            isWord = true;
        }


        if (curr == '.' && i == queryIP.size() - 1)
            return false;

        if (curr == '.' || i == queryIP.size() - 1) {

            if (!isWord || v4Sum > 255)
                return false;

            isWord = false;
            part++;
            v4Sum = 0;
            v4Num = 0;
        } 

        if (part > 4)
            return false;
    
    }

    return part == 4;
}

bool isIPV6(string queryIP) {

    bool isWord = false;
    int  v6Num = 0, part = 0;
    char curr;

    // ipv4
    for (int i = 0; i < queryIP.size(); i++) {
        
        curr = queryIP[i];

        if (curr == '.') 
            return false;

        if (curr != ':') {
            if (++v6Num > 4 ||
                   (curr < '0' || curr > '9') && 
                   (curr < 'a' || curr > 'f') && 
                   (curr < 'A' || curr > 'F')) {
                return false;
            }
            
            isWord = true;
        }

        if (curr == ':' && i == queryIP.size() - 1)
            return false;

        if (curr == ':' || i == queryIP.size() - 1) {

            if (!isWord)
                return false;

            isWord = false;
            part++;
            v6Num = 0;
        } 

        if (part > 8)
            return false;
    
    }

    return part == 8;
}


string validIPAddress(string queryIP) {

    if (isIPV4(queryIP))
        return "IPv4";
    else if (isIPV6(queryIP))
        return "IPv6";
    else    
        return "Neither";
        
}

int main() {

    /*
    printf("validIPAddress: %s \r\n", validIPAddress("01.01.01.01").data());

    printf("checkOnesSegment: %d \r\n", checkOnesSegment("1001"));

    printf("truncateSentence: %s \r\n", truncateSentence("chopper is not a tanuki", 5).data());

    printf("countValidWords: %d \r\n", countValidWords("cat and  dog"));

    printf("areNumbersAscending: %d \r\n", areNumbersAscending("hello world 5 x 5"));

    printf("countSegments: %d \r\n", countSegments("Hello, my name is John"));

    printf("lengthOfLastWord: %d \r\n", lengthOfLastWord("Hello World"));
    */

    return 0;
}