// Test document for Assignment 1, calculating transition energy using Bohr formula.
// Callum Williamson - 11399397.
// 09/02/2026.

#include<iostream>
#include<iomanip>
#include<string>

double return_transition_energy(int Z, int n_i, int n_j)
{
    // Function to return transistion energy in eV.
    const double R = 13.6; // Rydberg constant in eV.
    return R * Z * Z * ((1.0 / (n_j * n_j)) - (1.0 / (n_i * n_i))); // Transition energy in eV.
}

std::string hydrogen_spectral_series(int Z, int n_j)
{
    // Function to return the name of the spectral series for a given final principal quantum number n_j.
    switch (n_j)
    {
        case 1:
            return "The Hydrogen spectral series is the Lyman series.";
        case 2:
            return "The Hydrogen spectral series is the Balmer series.";
        case 3:
            return "The Hydrogen spectral series is the Paschen series.";
        case 4:
            return "The Hydrogen spectral series is the Brackett series.";
        case 5:
            return "The Hydrogen spectral series is the Pfund series.";
        default:
            return "This is a higher order hydrogen spectral series, n_j > 5."; // For n_j greater than 5, as there are no named series beyond Pfund.
    }
}

void wavelength(double energy)
{
    // Function to return the wavelength of the transition in nm and the type of light emitted based on the wavelength.

    // Calculation of wavelength.
    const double h = 4.136e-15; // Planck's constant in eVs.
    const double c = 3e8; // Speed of light in m/s.
    double lambda = (h * c) / energy; // Wavelength in meters.
    lambda = lambda * 1e9; // Convert wavelength to nm.

    // Determine the type of light.
    std::string band;
    if (lambda < 0.01 ) band = "Gamma ray";
    else if (lambda < 10) band = "X-ray";
    else if (lambda < 400) band = "Ultraviolet";
    else if (lambda < 700) band = "Visible light";
    else if (lambda < 1e6) band = "Infrared";
    else if (lambda < 1e9) band = "Microwave";
    else band = "Radio wave";

    std::cout << "Wavelength: " << lambda << " nm (" << band << ")" << std::endl;
}

int main()
{
    // Define constants.
    const double R = 13.6; // Rydberg constant in eV.
    const double eV_to_J = 1.602e-19; // Conversion factor from eV to Joules.

    // Define int for repetition of program.
    int repeat = 1;
    do
    {
        // Requesting variables from user.
        int units, Z, n_i, n_j; // Units calculation is printed in, atomic number, initial and final principal quantum numbers.

        std::cout << "Enter atomic number Z: ";
        bool valid_Z = 0; // Define bool for validility of Z.
        while (!valid_Z) // Input validation for atomic number.
        {
            bool input_okay = !(!(std::cin >> Z));
            bool Z_okay = !(Z < 1 || Z > 118);
            // Below checks that there are no extra characters after the integer input for Z, which would indicate an invalid input.
            bool cin_okay = std::cin.peek() == 10 || std::cin.peek() == EOF; // Check if the next character is a newline (10) or end of file (EOF), which would indicate that there are no extra characters after the integer input.
            valid_Z = input_okay && Z_okay && cin_okay;

            if (!valid_Z)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input for atomic number Z. Enter an integer between and including 1 and 118: ";
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }

        std::cout << "Enter initial principal quantum number n_i: ";
        bool valid_n_i = 0; // Define bool for validity of n_i.
        while (!valid_n_i) // Input validation for n_i.
        {
            bool input_okay = !(!(std::cin >> n_i));

            bool n_i_okay = !(n_i < 2); // Initial principal quantum number must be greater than or equal to 2 for a transition to occur, as n_j must be less than n_i.
            // Below checks that there are no extra characters after the integer input for n_i, which would indicate an invalid input.
            bool cin_okay = std::cin.peek() == 10 || std::cin.peek() == EOF; // Check if the next character is a newline (10) or end of file (EOF), which would indicate that there are no extra characters after the integer input.
            valid_n_i = input_okay && n_i_okay && cin_okay;

            if (!valid_n_i)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input for initial principal quantum number n_i. Enter a positive integer, greater than 1: ";
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }

        std::cout << "Enter final principal quantum number n_j: ";
        bool valid_n_j = 0; // Define bool for validity of n_j.
        while (!valid_n_j) // Input validation for n_i.
        {
            bool input_okay = !(!(std::cin >> n_j));
            bool n_j_okay = !(n_j < 1 || n_j >= n_i); // Final principal quantum number must be greater than or equal to 1 and less than n_i for a transition to occur.
             // Below checks that there are no extra characters after the integer input for n_j, which would indicate an invalid input.
            bool cin_okay = std::cin.peek() == 10 || std::cin.peek() == EOF; // Check if the next character is a newline (10) or end of file (EOF), which would indicate that there are no extra characters after the integer input.
            valid_n_j = input_okay && n_j_okay && cin_okay;

            if (!valid_n_j)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input for final principal quantum number n_j. Enter a positive integer, greater than or equal to 1 and less than n_i: ";
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }

        std::cout << "Enter units (0 for eV, 1 for Joules): ";
        bool valid_units = 0; // Define bool for validity of units choice.
        while (!valid_units) // Input validation for units choice.
        {
            bool input_okay = !(!(std::cin >> units));
            bool units_okay = (units == 0 || units == 1);
            // Below checks that there are no extra characters after the integer input for units, which would indicate an invalid input.
            bool cin_okay = std::cin.peek() == 10 || std::cin.peek() == EOF; // Check if the next character is a newline (10) or end of file (EOF), which would indicate that there are no extra characters after the integer input.
            valid_units = input_okay && units_okay && cin_okay;
            
            if (!valid_units)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input for units. Enter 0 for eV or 1 for Joules: ";
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        
        // Compute transition energy.
        double E = return_transition_energy(Z, n_i, n_j); // Transition energy in eV, using function defined above.

        // Convert to Joules if required and print result.
        if (units == 1)
        {
            double E_J = E * eV_to_J; // Convert eV to Joules, term is from UoM physical constants sheet.
            //std::cout << std::fixed << std::setprecision(20);
            //std::cout << "Transition energy: " << E << " J" << std::endl;
            std::cout << std::scientific << std::setprecision(3) << "Transition energy: " << E_J << " J" << std::endl; // Print in scientific notation as well, as per assignment specification.
            std::cout << std::fixed << std::setprecision(3); // Resetting formatting to the same as if eV was chosen, for consistency in later outputs.
        }
        else
        {
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "Transition energy: " << E << " eV" << std::endl;
        }

        // Print the name of the spectral series for a hydrogenic atom, if Z = 1.
        if (Z == 1)
        {
            std::cout << hydrogen_spectral_series(Z, n_j) << std::endl;
        }

        // Print the wavelength of the transition and the type of light emitted.
        wavelength(E);

        // Ask user if they want to repeat the calculation.
        std::cout << "Do you want to perform another calculation? (0 for no, 1 for yes): ";
        while (!(std::cin >> repeat) || (repeat != 0 && repeat != 1)) // Input validation for repeat choice.
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 0 to exit or 1 to perform another calculation: ";
        }
        
        // Print a separator for readability if the user chooses to repeat.
        std::cout << "---------------------------------------------------------------------\n";
    } while (repeat == 1);
    std::cout << "Program exited. Thank you.";
}