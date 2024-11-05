#include <iostream>
#include <cctype>
#include <algorithm> // for std::all_of

class Validator {
public:
    // Rule #1: String length must be at least 8 characters
    static constexpr int MinLength = 8;

    static bool hasMinLength(const std::string& password) {
        return password.length() >= MinLength;
    }

    // Rule #2: String must contain at least 1 uppercase letter
    static bool hasUppercase(const std::string& password) {
        return std::any_of(password.begin(), password.end(), [](char c) {
            return std::isupper(c);
        });
    }

    // Rule #3: String must contain at least 1 digit
    static bool hasDigit(const std::string& password) {
        return std::any_of(password.begin(), password.end(), [](char c) {
            return std::isdigit(c);
        });
    }

    // Overall validation method combining all rules
    static bool isValidPassword(const std::string& password) {
        return std::all_of(rules.begin(), rules.end(), [&](auto rule) {
            return rule(password);
        });
    }

/* hack, to check if it works - it does, but cheeky...and matches pattern
private:
    static const std::initializer_list<decltype(hasMinLength)*> rules;
};

const std::initializer_list<decltype(Validator::hasMinLength)*> Validator::rules = {
    &hasMinLength,
    &hasUppercase,
    &hasDigit
};
*/
private:
    // Corrected initializer_list type
    using RuleFunction = bool (*)(const std::string&);
    static const std::initializer_list<RuleFunction> rules;
};

// Corrected initializer_list definition
const std::initializer_list<Validator::RuleFunction> Validator::rules = {
    &hasMinLength,
    &hasUppercase,
    &hasDigit
};


int main() {
    int attempts = 3;

    while (attempts > 0) {
        std::string userPassword;

        // Get password from the user
        std::cout << "Enter your password: ";
        std::cin >> userPassword;

        // Validate the password
        if (Validator::isValidPassword(userPassword)) {
            std::cout << "Password is valid.\n";
            break; // Exit the loop if the password is valid
        } else {
            std::cout << "Invalid password. Please make sure it satisfies all the rules.\n";
            attempts--;

            if (attempts > 0) {
                std::cout << "You have " << attempts << " attempts remaining.\n";
            } else {
                std::cout << "You have run out of attempts. Exiting...\n";
            }
        }
    }

    return 0;
}
