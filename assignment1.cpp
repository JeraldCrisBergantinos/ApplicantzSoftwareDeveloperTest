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

// Function to reverse string.
// Sample Input: String; 2be reversed...
// Sample Output: gnirtS; eb2 desrever...
std::string reverse_words(const std::string &str)
{
    std::stringstream result_stream;
    std::stringstream current_word_stream;
    for (char c : str)
    {
        if (isalnum(c)) // Check if the character is alphanumeric (letter or word).
        {
            // Alphanumeric. Append the current character.
            current_word_stream << c;
        }
        else {
            // Non-alphanumeric. Reverse the current word and append it to the result.
            std::string current_word = current_word_stream.str();
            std::reverse(current_word.begin(), current_word.end());
            result_stream << current_word << c; // Append also the current character.
            current_word_stream.str(""); // Clear the current word.
        }
    }

    // Handle the last word if it exists in case
    // the string doesn't end with a non-alphanumeric character
    if (!current_word_stream.str().empty())
    {
        std::string last_word = current_word_stream.str();
        std::reverse(last_word.begin(), last_word.end());
        result_stream << last_word;
    }

    return result_stream.str();
}

void additional_tests()
{

}

int main()
{
    // Original test
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");

    additional_tests();

    return 0;
}
