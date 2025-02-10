// Assignment 1
// PROBLEM DEFINITION
// ------------------
// Reverse each word in the input string.
// The order of the words will be unchanged.
// A word is made up of letters and/or numbers.
// Other characters (spaces, punctuation) will not be reversed.

// NOTES
// ------
// Write production quality code
// We prefer clarity over performance (though if you can achieve both - great!)
// You can use the language that best highlights your programming ability
// the template below is in C++
// A working solution is preferred (assert in main() should succeed)
// Bonus points for good tests

#include <string>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <iostream>

std::string reverse_words(const std::string &str)
{
    // TODO: Implement this function
    std::string strResult;
    std::string strCurrentWord;
    for (char c : str) {
        if (isalnum(c)) strCurrentWord += c;
        else {
            if (!strCurrentWord.empty()) {
                std::reverse(strCurrentWord.begin(), strCurrentWord.end());
                strResult += strCurrentWord;
                strCurrentWord = "";
            }
            strResult += c;
        }
    }

    return strResult;
}

int main()
{
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    return 0;
}