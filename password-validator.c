/*PASSWORD VALIDATOR BY ARYAN ROSHAN*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototype for password validation
int isValid(char *password);

int main() {
    char pass[200];
    printf("Enter your password: "); // Asks user to enter a password, accepts up to 200 characters
    fgets(pass, 200, stdin); // Read the password from user input

    size_t length = strlen(pass); // Calculate the length of the input string AKA password

    // Check if the last character is a newline character and remove it
    if (length > 0 && pass[length - 1] == '\n') {
        pass[length - 1] = '\0';
    }

    // Call the isValid function to check if the password is valid
    if (isValid(pass)) {
        printf("Password is valid.\n"); // Print message if the password is valid
    } else {
        printf("Password is invalid.\n"); // Prin message if the password is invalid
    }

    return 0;
}

// Function to validate a password
int isValid(char *password) {
    int has_lower = 0; // Checks for lowercase letters
    int has_upper = 0; // Checks for uppercase letters
    int has_spl = 0;   // Checks for special characters
    int has_digit = 0; // Checks for digits
    size_t length = strlen(password); // Calculate the length of the password

    // Check if the password length is less than 10 characters
    if (length < 10) {
        return 0; // Return 0 (false) if the password is too short
    }

    // Loop to go through each character in the password
    for (size_t i = 0; i < length; i++) {
        
        if (isupper(password[i])) { // Checks if the character is an uppercase letter
            has_upper = 1;
        } 
        else if (islower(password[i])) { // Check if the character is a lowercase letter
            has_lower = 1;
        } 
        else if (isdigit(password[i])) { // Check if the character is a digit
            has_digit = 1;
        } 
        else if (ispunct(password[i])) { // Check if the character is a special character
            has_spl = 1;
        }
    }

    
    return has_upper && has_lower && has_digit && has_spl; // Return 1 (true) if all the required conditions are met
}
