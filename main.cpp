#include <iostream>
#include <conio.h>

double temperature;
std::string currentScale;
std::string targetScale;


double convertTemperature(double temperature, std::string currentScale, std::string targetScale) {
    //conversion formula for C to F
if (currentScale == "C" && targetScale == "F") {
    return (9.0 / 5.0) * (temperature + 32);
    // convert F to C
} else if (currentScale == "F" && targetScale == "C") {
    return (5.0 / 9.0) * (temperature - 32);
} else if (currentScale == "F" && targetScale == "K") {
    return  (temperature -32) * 5.0/9.0 + 273.15;
} else if (currentScale == "K" && targetScale == "F") {
    return ( temperature - 273.15) * (9.0 / 5.0) + 32;
} else if (currentScale == "C" && targetScale == "K") {
    return ( temperature + 273.15);
} else if (currentScale == "K" && targetScale == "C") {
    return (temperature - 273.15);
    // else throw error
} else {
    throw std::invalid_argument("Unsupported temperature scale.  Please use C or F");
}
}

int main () {
    bool continueConverting = true;
    while (continueConverting) {
    std::cout << "Enter Temperature: ";
    std::cin >> temperature;

    std::cout << "Enter Scale (C, F or K): ";
    std::cin >> currentScale;

    std::cout << "Enter Target Scale (C, F or K): ";
    std::cin >> targetScale;

    double convertedTemperature = convertTemperature(temperature, currentScale, targetScale);

    std::cout << "The Converted Temperature is: " << convertedTemperature << std::endl;

    //here we ask user if they want to convert more, if not, exit
        std::cout << "Do you want to do any more conversions? (y/n) ";
        std::string answer;
        std::cin >> answer;

        continueConverting = (answer == "y" || answer == "Y");
}

std::cout << "Press any key to exit";
_getch();
    return 0;
}