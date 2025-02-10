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

    std::cout << str << " " << result_stream.str() << std::endl;

    return result_stream.str();
}

// Function declaration for additional tests.
void additional_tests();

int main()
{
    // Original test
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");

    additional_tests();

    return 0;
}

void additional_tests()
{
    // Additional basic tests
    std::string test_str1 = "Another test123 string.";
    assert(reverse_words(test_str1) == "rehtonA 321tset gnirts.");

    std::string test_str2 = "LastWord";
    assert(reverse_words(test_str2) == "droWtsaL");

    std::string test_str3 = "";
    assert(reverse_words(test_str3) == "");

    std::string test_str4 = "  Leading and trailing spaces  ";
    assert(reverse_words(test_str4) == "  gnidaeL dna gniliart secaps  ");

    std::string test_str5 = "Mixed123;Chars!456";
    assert(reverse_words(test_str5) == "321dexiM;srahC!654");

    // Edge cases

    // Numbers only
    std::string test_str6 = "12345";
    assert(reverse_words(test_str6) == "54321");

    // Special characters only
    std::string test_str7 = ";;,...";
    assert(reverse_words(test_str7) == ";;,...");

    // String starting with a special character
    std::string test_str8 = "!Word";
    assert(reverse_words(test_str8) == "!droW");

    // Consecutive special characters
    std::string test_str9 = "Word;;;Another";
    assert(reverse_words(test_str9) == "droW;;;rehtonA");

    // Numbers and special characters mixed
    std::string test_str10 = "123;abc!456";
    assert(reverse_words(test_str10) == "321;cba!654");
}
