#include <iostream>
#include <string>

int main(){
    std::cout << "first name? ";

    std::string name;
    std::cin >> name;
    
    std::cout << "last name? ";
    std::string lname;
    std::cin >> lname;

    std::string full =  "* Hello, " + name + " " + lname + " *";
    std::string first(full.size(), '*');
    std::string last(full.size(), '*');
    
    std::cout << first << std::endl;
    std::cout << full << std::endl;
    std::cout << last << std::endl;

    return 0;
}