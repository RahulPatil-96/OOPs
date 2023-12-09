#include <iostream>
#include <cstring>

bool isPalindrome(const std::string& str) 
{
    int length = str.length();
    
    for (int i = 0; i < length / 2; ++i) 
    {
      if (str[i] != str[length - i - 1]) 
        return false;
    }
    return true;
}

int main() 
{
    std::string input;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string sanitizedInput;
    for (char c : input) 
    {
      if (std::isalnum(c))
       sanitizedInput += std::tolower(c);
    }

    if (isPalindrome(sanitizedInput)) 
     std::cout << "The entered string is a palindrome." << std::endl;
    
    else 
     std::cout << "The entered string is not a palindrome." << std::endl;

    return 0;
}
