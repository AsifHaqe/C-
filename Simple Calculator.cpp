#include <iostream>
#include <limits>
double add(double num1, double num2){
    return num1 + num2;
}
double subtract(double num1, double num2){
    return num1 - num2;
}
double multiply(double num1,double num2){
    return num1 * num2;
}
double divide(double num1,double num2){
    if(num2 == 0){
        std :: cout << "Error :Divide by zero" << std::endl;
        return 0;
    }
    return num1/num2;
}
int main(){
    double num1,num2;
    char operation;
    while(true){
        std :: cout << "Enter the first number :";
        while(!(std :: cin >> num1)){
            std :: cout << "Invalid input. please Input a number";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Enter operation (+, -, *, /), or 'q' to quit: ";
        std::cin >> operation;
    
    if(operation == 'q'){
        std :: cout << "Exiting calculator." << std:: endl;
        break;
    }
    if(operation != '+' && operation != '-' && operation != '*' && operation != '/'){
        std :: cout << "Invalid input. please enter a number :" << std::endl;
        continue;
    }
    std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    double result;
    switch (operation) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                std::cout << "Error: Invalid operation." << std::endl;
                continue; 
        }

    
        std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }
}

