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
        int top_speed;
        //int base_price; maybe
        Ferrari_Car();
        Ferrari_Car(std::string Name, std::string engine, int year, int horespower, bool four_wheel_drive, int top_speed)
        {
            Name = this->Name;
            engine = this->engine;
            year = this->year;
            horespower = this->horespower;
            four_wheel_drive = this->four_wheel_drive;
            top_speed = this->top_speed;
        }
};
//bunch of avaliable ferrari cars
Ferrari_Car Superfast{ "Ferrari 812 Superfast", "6.5L V12", 2017, 789, false, 340};
Ferrari_Car GTS{ "Ferrari 812 GTS", "6.2L nat asp V12", 2019, 789, false, 338};
Ferrari_Car Stradale{ "Ferrari SF90 Stradale", "4.0L TT V8 + 3 electric", 2019, 989, true, 340};
Ferrari_Car SFSpider{ "Ferrari SF90 Spider", "4.0L TT V8 + 3 electric", 2020, 989, false, 340};
Ferrari_Car Tributo{ "Ferrari F8 Tributo", "3.9L twin-turbo V8", 2019, 710, false, 340};
Ferrari_Car F8Spider{ "Ferrari F8 Spider", "3.9L twin-turbo V8", 2019, 710, false, 340};
Ferrari_Car Roma{ "Ferrari Roma", "3.9L twin-turbo V8", 2020, 612, false, 320};
Ferrari_Car Portofino{ "Ferrari Portofino M", "3.9L twin-turbo V8", 2017, 612, false, 320};
Ferrari_Car MonzaSP1{ "Ferrari Monza SP1", "6.5 L nat asp V12", 2019, 810, false, 299};
Ferrari_Car MonzaSP2{ "Ferrari Monza SP2", "6.5 L nat asp V12" , 2019, 810, false, 299};

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

void renting_process() //user can rent a car
{
    std::string user_answer;
    std::cin >> user_answer;
    std::vector<std::string> carlist = { "Ferrari 812 Superfast", "Ferrari 812 GTS", "Ferrari SF90 Stradale", "Ferrari SF90 Spider", "Ferrari F8 Tributo", "Ferrari F8 Spider", "Ferrari Roma", "Ferrari Portofino M", "Ferrari Monza SP1", "Ferrari Monza SP2" };
    if (user_answer == "yes" || user_answer == "Yes") //if user answers yes
    {
        std::string available_car;
        int i = 0;
        for (i; i < 9; i++)
        {
            std::vector<std::string> availablecars; //holds an array of the cars that are available to be rented
            std::ifstream myfile(carlist[i], std::fstream::app); //creates file of the car if not created and opens it if it is
            std::getline(myfile, available_car); //reads from file, if it has extra words then car is not available
            if (available_car == "") //if there is nothing read
            {
                availablecars.push_back(available_car);
            }
            if (availablecars.size() == 0) //if the size is nothign
            {
                std::cout << "There are no cars available, please check again later\n";
                exit; //exits the void
            }
            else
            {
                std::cout << "The " << availablecars[i] << " is available\n";
            }
        }
    }
    else if (user_answer == "no" || user_answer == "No") //if user answers no
    {
        std::cout << "Okay, thank you for logging in\n";
    }
    else
    {
        std::cout << "Invalid answer, redirecting back to starting page\n";
    }
    //if no, exit application
     //if yes, show them AVAILABLE cars and say if they type in car name, you will show them stats and confirm if they want to rent this car
}

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
        renting_process();
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