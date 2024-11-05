#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>

int main() {
    // Hardcoded vector of 5 string_view literals with sv suffix
    auto emailAddresses = std::vector<std::string_view>{
        "user1@example.com",
        "user2@gmail.com",
        "user5@company.co.uk",
        "user3@hotmail.com",
        "user4@yahoo.com",
    };

    // Lambda function to remove email addresses ending with ".co.uk"; endsWith is C++20 you prefer...
    // cf. https://en.cppreference.com/w/cpp/string/basic_string/ends_with
    auto removeCoUk = [](auto email) {
        return email.substr(email.length() - 6) == ".co.uk";
    };

    // Use erase-remove idiom with the lambda to remove ".co.uk" addresses
    emailAddresses.erase(
        std::remove_if(emailAddresses.begin(), emailAddresses.end(), removeCoUk),
        emailAddresses.end()
    );

    // Display the filtered email addresses
    std::cout << "Filtered Email Addresses:\n";
    for (const auto& email : emailAddresses) {
        std::cout << email << '\n';
    }

    return 0;
}
