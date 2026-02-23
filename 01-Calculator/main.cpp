#include <iostream>
#include <tuple>
#include <sstream>

std::tuple<int, int, char> getInput(){
    int num1, num2;
    char operation;
    std::tuple<int, int, char> data;
    std::string userInput;
    
    std::cout << "Introduce una operacion o 'exit' para salir: ";
    std::getline(std::cin, userInput);
    
    if (userInput == "exit"){
        data = {0, 0, 'X'};
        std::cout << "Hasta luego!" << std::endl;
    } else {
        std::stringstream ss(userInput);
        if (ss >> num1 >> operation >> num2){
            data = {num1, num2, operation};
        } else {
            data = {0, 0, 'E'};
            std::cout << "Formato inválido. Intenta con algo como '10 + 10'" << std::endl;
        }
    }
    return data;
}

void handleOperation(std::tuple<int, int, char> datos){
    std::tuple<int, int, char> data = datos;
    char op = std::get<2>(data);
    switch (op){
        case '+': {
            int result = std::get<0>(data) + std::get<1>(data);
            std::cout << "El resultado es " << result << std::endl;
            break;
        }
        case '-': {
            int result = std::get<0>(data) - std::get<1>(data);
            std::cout << "El resultado es " << result << std::endl;
            break;
        }
        case '*': {
            int result = std::get<0>(data) * std::get<1>(data);
            std::cout << "El resultado es " << result << std::endl;
            break;
        }
        case '/': {
            if (!(std::get<1>(data) == 0)){
                double result = static_cast<double>(std::get<0>(data)) / std::get<1>(data);
                std::cout << "El resultado es " << result << std::endl;
            } else {
                std::cout << "No se puede dividir entre 0" << std::endl;
            }
            break;
        }
        default:
            std::cout << "Operacion inválida." << std::endl;
    }
}

int main(){
    std::tuple<int, int, char> datos;
    while (true){
        datos = getInput();
        if (std::get<2>(datos) == 'X'){
            break;
        } else if (std::get<2>(datos) == 'E'){
            continue;
        } else {
            handleOperation(datos);
        }
    }
    return 0;
}
