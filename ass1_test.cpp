// Test document for Assignment 1, calculating transition energy using Bohr formula.
// Callum Williamson - 11399397.
// 03/02/2026.

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
        while (!(std::cin >> Z) || Z < 1 || Z > 118) // Input validation for atomic number.
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input for atomic number Z. Enter an integer between and including 1 and 118: ";
        }

        std::cout << "Enter initial principal quantum number n_i: ";
        while (!(std::cin >> n_i) || n_i < 1) // Input validation for initial principal quantum number (I beleive there is no upper limit?).
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');   
            std::cout << "Invalid input for initial principal quantum number n_i. Enter a positive integer, greater than or equal to 1: ";
        }

        std::cout << "Enter final principal quantum number n_j: ";
        while (!(std::cin >> n_j) || n_j < 1 || n_j > n_i) // Input validation for final principal quantum number.
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // Perhaps should specify that n_j must be less than n_i for a transition to occur first.
            // Also is the below sentance too long?
            std::cout << "Invalid input for final principal quantum number n_j. Enter a positive integer, greater than or equal to 1 and that is less than n_i: ";
        }

        std::cout << "Enter units (0 for eV, 1 for Joules): ";
        while (!(std::cin >> units) || (units != 0 && units != 1)) // Input validation for units choice.
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input for units. Enter 0 for eV or 1 for Joules: ";
        }
        
        // Compute transition energy using Bohr formula.
        double E = R * Z * Z * ((1.0 / (n_j * n_j)) - (1.0 / (n_i * n_i))); // Transition energy in eV.

        // Convert to Joules if required and print result.
        if (units == 1)
        {
            E = E * eV_to_J; // Convert eV to Joules, term is from UoM physical constants sheet.
            //std::cout << std::fixed << std::setprecision(20);
            //std::cout << "Transition energy: " << E << " J" << std::endl;
            std::cout << std::scientific << std::setprecision(3) << "Transition energy: " << E << " J" << std::endl; // Print in scientific notation as well, as per assignment specification.
        }
        else
        {
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "Transition energy: " << E << " eV" << std::endl;
        }
        // Ask user if they want to repeat the calculation.
        std::cout << "Do you want to perform another calculation? (y/n): ";
        while (!(std::cin >> repeat) || (repeat != 'y' && repeat != 'n')) // Input validation for repeat choice.
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 'y' to perform another calculation or 'n' to exit: ";
        }
    } while (repeat == 'y');
    
}