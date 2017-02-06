#include <iostream>

int main() {
    int SIZE;
    std::cin >> SIZE;
    
    int * ptr = new int [SIZE];
    
    int firstItem= ptr[0];
    
    int x;
    ptr = &x;
    
    std::cout<<*ptr;
}
