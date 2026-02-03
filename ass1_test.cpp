// Test document for Assignment 1, calculating transition energy using Bohr formula.
// Callum Williamson - 11399397.
//03/02/2026.

#include<iostream>
#include<iomanip>

int main()
{
    // Define constants.
    const double R = 13.6; // Rydberg constant in eV.
    
    // Requesting variables from user. Will need to implement checks for invalid inputs later.
    int units, Z, n_i, n_j; // Units calculation is printed in, atomic number, initial and final principal quantum numbers.

    std::cout << "Enter atomic number Z: ";
    std::cin >> Z;
    std::cout << "Enter initial quantum number n_i: ";
    std::cin >> n_i;
    std::cout << "Enter final quantum number n_j: ";
    std::cin >> n_j;
    std::cout << "Enter units (0 for eV, 1 for Joules): ";
    std::cin >> units;
    


}