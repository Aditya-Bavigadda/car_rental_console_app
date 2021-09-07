#include "access.h"
#include "string.h"
#include "cars.h"

void returning_process(std::vector<std::string> user_details)
{
    std::string user_answer;
    std::cin >> user_answer; //gets the user answer if they want to return their car

    if (stringLower(user_answer) == "yes")
    {
        std::ofstream file(user_details[0]);
        file << user_details[0] << "\n" << user_details[1]; //recreates user file as empty
        std::ofstream file1(user_details[2]); //recreate car file as empty
        std::cout << "Thank you for returning your car\n"; //thank the user for logging in
    }
    else if (stringLower(user_answer) == "no")
    {
        std::cout << "Okay, thank you for logging in\n";
    }
    else 
    {
        std::cout << "Invalid answer, redirecting back to starting page\n";
    }
}

void registration_process(std::vector<char> unnacceptable_words)
{
    bool exit_loop = false;
    std::string username;
    std::string password;
    do //is stuck in a loop until the inputs are acceptable
    {
        char variablecatcher = 0; //is used to catch an exception in the username
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears cin cooldown, as the program was skipping over this line
        std::cout << "\nUsername: ";
        std::getline(std::cin, username); //gets username
        std::cout << "\nPassword: ";
        std::getline(std::cin, password); //gets password
        for (char i = 0; i < unnacceptable_words.size(); i++)
        {
            if (username.find(unnacceptable_words[i]) != std::string::npos) //sees if there are unnacceptable sequences in username
            {
                std::cout << "the \"" << unnacceptable_words[i] << "\" is not allowed in username, please press enter to try again\n";
                variablecatcher = 1;
            }
            if (password.find(unnacceptable_words[i]) != std::string::npos) //sees if there are unnacceptable sequences in username
            {
                std::cout << "the \"" << unnacceptable_words[i] << "\" is not allowed in password, please press enter to try again\n";
                variablecatcher = 1;
            }
        }
        variablecatcher == 0 ? exit_loop = true : exit_loop = false;
    } while (exit_loop == false);
    std::cout << "congrats, you have been registered\n";
    std::ofstream file(username); //creates new file for every user that is registered
    file << username << "\n" << password; //add username and password to file
}

void login_process()
{
    std::string username, password;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears cin cooldown, as the program was skipping over this line
    std::cout << "\nUsername: ";
    std::getline(std::cin, username); //gets username
    std::cout << "\nPassword: ";
    std::getline(std::cin, password); //gets password
    std::ifstream file(username); //opens file with username login
    std::string user, pass; //used to get data from the file
    std::getline(file, user); //gets username on first line
    std::getline(file, pass); //gets password on next line
    if (user == username && pass == password) //mini hotfix, is meant to be && but username isn't being read
    {
        std::cout << "you have logged in, welcome " << username << "\n";
        car_interaction(user); //allows user to buy or sell cars
    }
    if (user != username || pass != password)
    {
        std::cout << "invalid username or password\n";
    }
}

