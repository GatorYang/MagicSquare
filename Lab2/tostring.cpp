#include <iostream>

int main()
{
    // converting in to a string
    std::string myStr = "hello";
    int num = 2;
    num = num * 3;
    myStr += std::to_string(num);
    std::cout << myStr << std::endl;
    
    //converting string int
    std::string numStr = "1337";
    num = std::stoi(numStr);
    std::cout << num << std::endl;
}