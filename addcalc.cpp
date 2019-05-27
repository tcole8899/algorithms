#include <iostream>


int main(){
    std::cout << "enter 1st number ";
    int number1;
    std::cin >> number1;

    std::cout << "enter an operator ";
    char op;
    std::cin >> op;


    std::cout << "enter 2nd number ";
    int number2;
    std::cin >> number2;

    switch (op)
    {
    case '+': std::cout << "Answer = " << number1 + number2 << std::endl;
        break;
    case '-': std::cout << "Answer = " << number1 - number2 << std::endl;
        break;
    case '*': std::cout << "Answer = " << number1 * number2 << std::endl;
        break;
    case '/': std::cout << "Answer = " << number1 / number2 << std::endl;
        break;
    default: std::cout << "Not a valid operator" << std::endl;
        break;
    }
    

    return 0;
}