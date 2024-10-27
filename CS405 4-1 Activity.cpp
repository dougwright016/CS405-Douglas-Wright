// CS405 4-1 Activity.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::runtime_error("Another error!");
    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;
    try {
        if (do_even_more_custom_application_logic())
        {

            std::cout << "More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::runtime_error& x) {
        std::cout << x.what() << std::endl;
    }
    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw (std::invalid_argument("Custom exceptions error!"));
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::runtime_error("Error: Divided by 0");
    }
    else {
        return (num / den);
    }
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0.0;
    std::string undef = "undefined";
    auto result = 0.0f;
    try {
        result = divide(numerator, denominator);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "divide(" << numerator << ", " << denominator << ") = ";
    if (denominator == 0) {
        std::cout << undef << std::endl;
    }
    else {
        std::cout << result << std::endl;
    }

}

int main()
{
    std::cout << "Exception Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (std::invalid_argument& y) {
        std::cout << y.what();
    }
    catch (std::exception& z) {
        std::cout << "Additional exception error!";
    }
    catch (std::logic_error& a) {
        std::cout << "Uncaught exception error!";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu