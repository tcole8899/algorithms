#include <iostream>

bool palindrome(char*);

int main(){
    std::cout << "Enter a word" << std::endl;
    char *word;
    std::cin >> word;

    bool answer = palindrome(word);
    if( answer == false){
        std::cout << "no";
    }
    else{
        std::cout << "yes";
    }


    return 0;
}

bool palindrome(char *a){
    int length;

    for(length = 0; a[length]; ++length);
    
    for(int i = 0; i < length/2; ++i){
        if(a[i] != a[length - i - 1])
            return false;
        
    }

    return true;
}