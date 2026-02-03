// Test document for Assignment 1, calculating transition energy using Bohr formula.
// Callum Williamson - 11399397.
//03/02/2026.

#include<iostream>
#include<iomanip>

int main()
{
    // Define constants.
    const double R = 13.6; // Rydberg constant in eV.
    const double eV_to_J = 1.602e-19; // Conversion factor from eV to Joules.

    // Define character for repetition of program.
    char repeat = 'y';
    do
    {
        // Requesting variables from user. Will need to implement checks for invalid inputs later.
        int units, Z, n_i, n_j; // Units calculation is printed in, atomic number, initial and final principal quantum numbers.

        std::cout << "Enter atomic number Z: ";
        while (!(std::cin >> Z) || Z < 1 || Z > 118)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter an integer between and including 1 and 118: ";
        }


        std::cout << "Enter initial quantum number n_i: ";
        std::cin >> n_i;
        std::cout << "Enter final quantum number n_j: ";
        std::cin >> n_j;
        std::cout << "Enter units (0 for eV, 1 for Joules): ";
        std::cin >> units;
        
        // Compute transition energy using Bohr formula.
        double E = R * Z * Z * ((1 / (n_j * n_j)) - (1 / (n_i * n_i))); // Transition energy in eV.

        // Convert to Joules if required and print result.
        // Look into asking for precision, need joules in standard form most likely.
        if (units == 1)
        {
            E = E * eV_to_J; // Convert eV to Joules, term is from UoM physical constants sheet.
            std::cout << std::fixed << std::setprecision(20);
            std::cout << "Transition energy: " << E << " J" << std::endl;
        }
        else
        {
            std::cout << std::fixed << std::setprecision(6);
            std::cout << "Transition energy: " << E << " eV" << std::endl;
        }
        // Ask user if they want to repeat the calculation.
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> repeat;
    } while (repeat == 'y');
    
}