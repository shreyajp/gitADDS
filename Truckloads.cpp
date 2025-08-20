#include "Truckloads.h" 
#include <iostream>


    int Reverser::reverseDigitH(int value, int acc){
        if (value==0){
            return acc;
        }
        
        return reverseDigitH(value/10, acc+(value%10)*10);
    }

    int Reverser::reverseDigit(int value){

        return reverseDigitH(value, 0);

    }

    std::string reverseStringH(std::string characters, std::string reverseChar){
        if(characters.empty()){
            return reverseChar;
        }
        reverseChar.push_back(characters.back());
        characters.pop_back();
        return reverseStringH(characters, reverseChar);

    }

    std::string reverseString(std::string characters){
        return reverseStringH(characters, "");

    }

    int main(){
        std::string word = "poopypants";
        std::cout<<reverseString(word)<<std::endl;
    }