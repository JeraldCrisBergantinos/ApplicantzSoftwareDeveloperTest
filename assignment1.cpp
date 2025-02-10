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
#include <sstream>
#include <iostream>

std::string reverse_words(const std::string &str)
{
    // TODO: Implement this function
    std::stringstream ssResult;
    std::stringstream ssCurrentWord;
    for (char c : str) {
        if (isalnum(c)) ssCurrentWord << c;
        else {
            std::string strWord = ssCurrentWord.str();
            std::reverse(strWord.begin(), strWord.end());
            ssResult << strWord << c;
            ssCurrentWord.str("");
        }
    }

    std::string strLastWord = ssCurrentWord.str();
    std::reverse(strLastWord.begin(), strLastWord.end());
    ssResult << strLastWord;

    return ssResult.str();
}

int main()
{
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    return 0;
}