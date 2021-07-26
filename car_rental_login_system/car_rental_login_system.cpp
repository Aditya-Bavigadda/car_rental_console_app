#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Ferrari_Car
{
    public:
        std::string Name;
        std::string engine;
        int year;
        int horespower;
        bool four_wheel_drive;
        int base_price;
        int top_speed;
};

void registration_process(std::vector<std::string> unnacceptable_words)
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


//error isn't being called
void car_interaction(std::string owner) //allows user to buy or sell cars
{
    std::ifstream file(owner); //opens file of user
    std::vector<std::string> user_details;
    for (size_t i = 0; i < 9; i++) //gets the details on the note we have on the user
    {
        std::string read_from_file = "";
        std::getline(file, read_from_file);
        if (read_from_file != "") //if something is read, then push back
        {
            user_details.push_back(read_from_file);
        }
    }
    if (user_details.size() == 2)
    {
        std::cout << "Do you want to rent a car? Please type Yes or No\n";
        //if no, exit application
        //if yes, show them AVAILABLE cars and say if they type in car name, you will show them stats and confirm if they want to rent this car
    }
    else
    {
        std::cout << "Do you want to return your " << user_details[2] << "? Please type Yes or No\n";
        //if no, exit application
        //if yes, return car and ask if they want to rent another car
    }
    //could have time rented?
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


int main()
{
    while (true)
    {
        std::cout << "1. Login\n2. Register\n"; //gives options for choices
        std::string choice; //will recieve choice, would have made integer, but string provides for any input
        std::cout << "your choice: ";
        std::cin >> choice; //recieves choice
        std::vector<std::string> unnacceptable_words = { " ", "_", "*", "&", "=", "'", "-", "\"", "-","+",",", "<", ">", "." };
        if (choice == "1")
        {
            login_process();
        }
        else if (choice == "2")
        {
            registration_process(unnacceptable_words);
        }
        else
        {
            std::cout << "\ninvalid statement\n";
        }

    }
}