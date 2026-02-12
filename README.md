Assignment 1 - The Bohr atom.

Callum Williamson 11399397

Please use the ass1_test.cpp file. I didn't want to change the name as I couldn't keep the commit history.

The brief is to write a C++ program to calculate the energy for a transition.

I first began by learning how to ask the user to enter the various variables and how to define constants (using double data types rather than floats due to ChatGPT suggestion).
This later extends to variables that decide what units the energy is returned in and whether to make another calculation.

The computation of the transistion energy in eV was programmed, followed by the output of it in either eV or Joules.
Then the decision to remain or leave the calulation loop was implemented.

The testing of and recovery for all user inputted variables was developed.

Output of transition energy in Joules was later changed to standard form.

An error due to integer division was fixed and the final decision of whether to continue to another calculation was cleaned up by changing the repeat variable to from a character to an integer.

A seperate function was implemented to return the transistion energy as requested by the rubric.

Two aspects beyond the skelaton code are that I developed a function to return the Hydrogen spectral series and the wavelength (light type).

Later I heavily overhauled validation so as not to accept e.g 1.11 or 1hello etc.

Declaration of AI: (ChatGPT 5.2 & Claude Haiku 4.5)
  - It helped me learn the basics of C++, for example how to output (```std::cout <<```)
  - It helped me understand the compiler configuration. I originally had strawberry pearl installed which was causing issues.
