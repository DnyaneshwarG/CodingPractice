#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr0{1,2,3,4,5};
    std::array<std::string, 5> arr1 = {"string0", "string1", "string2", "string3"};
    
    std::cout << "\nInteger array is:" << std::endl;
    for (auto val: arr0) {
        std::cout << val << std::endl;
    }
    std::cout << "\nString array is:" << std::endl;
    for (auto val: arr1) {
        std::cout << val << std::endl;
    }
    return 0;
}