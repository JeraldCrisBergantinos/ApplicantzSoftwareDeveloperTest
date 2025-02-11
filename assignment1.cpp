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
#include <vector>
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
    std::vector< std::pair<std::string, std::string> > reverse_words_list;

    // Additional basic tests
    reverse_words_list.push_back(std::make_pair("Another test123 string.", "rehtonA 321tset gnirts."));
    reverse_words_list.push_back(std::make_pair("LastWord", "droWtsaL"));
    reverse_words_list.push_back(std::make_pair("", ""));
    reverse_words_list.push_back(std::make_pair("  Leading and trailing spaces  ", "  gnidaeL dna gniliart secaps  "));
    reverse_words_list.push_back(std::make_pair("Mixed123;Chars!456", "321dexiM;srahC!654"));

    // Edge cases

    // Numbers only
    reverse_words_list.push_back(std::make_pair("12345", "54321"));

    // Special characters only
    reverse_words_list.push_back(std::make_pair(";;,...", ";;,..."));

    // String starting with a special character
    reverse_words_list.push_back(std::make_pair("!Word", "!droW"));

    // Consecutive special characters
    reverse_words_list.push_back(std::make_pair("Word;;;Another", "droW;;;rehtonA"));

    // Numbers and special characters mixed
    reverse_words_list.push_back(std::make_pair("123;abc!456", "321;cba!654"));

    // Longer string
    reverse_words_list.push_back(std::make_pair(
        "This is a longer string with multiple words and some special characters like ,.!?; and numbers 12345.",
        "sihT si a regnol gnirts htiw elpitlum sdrow dna emos laiceps sretcarahc ekil ,.!?; dna srebmun 54321.")
    );

    // Control characters
    reverse_words_list.push_back(std::make_pair("Word\tAnother\nLine", "droW\trehtonA\neniL"));

    // Do the actual test.
    for (const auto& reverse_words_pair : reverse_words_list) {
        const std::string original_str = reverse_words_pair.first;
        const std::string reversed_expected_str = reverse_words_pair.second;
        const std::string reversed_actual_str = reverse_words(original_str);
        if (reversed_actual_str != reversed_expected_str) // Compare the actual and expected reverse.
        {
            // Not the same. Display an error.
            std::cerr << "Failed. Original: " << original_str << ", Expected Reversed: " << reversed_expected_str << ", Actual Reversed: " << reversed_actual_str << std::endl;
        }
    }
}
