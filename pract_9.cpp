#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to print the original string followed by the reversed string using a stack
void printOriginalAndReversedString(string str)
{
    stack<char> s;

    // Push all characters of the string onto the stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // Print the original string
    cout << "Original string: " << str << endl;

    // Print the reversed string
    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Function to check whether the given string is a palindrome or not
bool isPalindrome(string str)
{
    stack<char> s;

    // Push all characters of the string onto the stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // Check if the string is a palindrome
    for (int i = 0; i < str.length(); i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main()
{
    string str = "madam";
    printOriginalAndReversedString(str);

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
