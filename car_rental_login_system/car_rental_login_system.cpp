#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<ios>
#include <algorithm>

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
            this->Name = Name;
            this->engine = engine;
            this->year = year;
            this->horespower = horespower;
            this->four_wheel_drive = four_wheel_drive;
            this->top_speed = top_speed;
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

std::ostream& operator << (std::ostream& output, Ferrari_Car car) //allows us to print the car stats
{
    output << "\nName: " << car.Name << "\nEngine type: " << car.engine << "\nYear made: " << car.year << "\nHorsepower: " << car.horespower << "\nFour Wheel Drive: " << std::boolalpha << car.four_wheel_drive << "\nTop Speed: " << car.top_speed << "km/h\n";
    return output;
}

void rent_car(std::vector<std::string> availablecars, std::string car_name, bool car_chosen, std::string owner)
{
    if (std::find(availablecars.begin(), availablecars.end(), car_name) != availablecars.end()) //if the car is available
    {
        std::cout << "Do you want to rent this car? Please type yes or no\n";
        std::string rent_car;
        std::getline(std::cin, rent_car);
        if (rent_car == "yes" || rent_car == "Yes")
        {
            std::fstream file(car_name, std::ios::app);
            file << owner;
            std::cout << "Well done, the car has been succesfully rented\n";
            std::fstream file2(owner, std::ios::app);
            file2 << "\n" << car_name;
            car_chosen = true;
        }
        else if (rent_car == "no" || rent_car == "No")
        {
            std::cout << "Okay, please type another car's name to view its stats\n";
        }
        else
        {
            std::cout << "Invalid answer, please type a car's name to view its stats\n";
        }
    }
    else //if not
    {
        std::cout << "This car is unavailable, so you can not rent it, please type another car to view its stats: \n";
    }
}

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

void renting_process(std::string owner) //user can rent a car
{
    std::string user_answer;
    std::cin >> user_answer;
    std::vector<std::string> carlist = { "Ferrari 812 Superfast", "Ferrari 812 GTS", "Ferrari SF90 Stradale", "Ferrari SF90 Spider", "Ferrari F8 Tributo", "Ferrari F8 Spider", "Ferrari Roma", "Ferrari Portofino M", "Ferrari Monza SP1", "Ferrari Monza SP2" };
    if (user_answer == "yes" || user_answer == "Yes") //if user answers yes
    {
        int current_car_from_carlist = 0;
         std::vector<std::string> availablecars; //holds an array of the cars that are available to be rented
        for (current_car_from_carlist; current_car_from_carlist < carlist.size(); ++current_car_from_carlist)
        {
            std::string available_car = "";
            std::ifstream myfile(carlist[current_car_from_carlist], std::fstream::app); //creates file of the car if not created and opens it if it is
            std::getline(myfile, available_car); //reads from file, if it has extra words then car is not available
            if (available_car == "") //if there is nothing read
            {
                availablecars.push_back(carlist[current_car_from_carlist]);
                std::cout << "The " << carlist[current_car_from_carlist] << " is available\n";
            }
            else
            {
                std::cout << "The " << carlist[current_car_from_carlist] << " is taken by a person with the username " << available_car << ".\n";
            }
        }
        bool car_chosen = false;
        std::cout << "Choose an car to see its stats and if the car is available, you can rent it: \n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears cin cooldown, as the program was skipping over this line
        while(true) //used to show properties of cars and uses the overloaded "std::cout <<" operator
        {
            std::string car_to_view = "";
            std::getline(std::cin, car_to_view);
            if (car_to_view == "Ferrari 812 Superfast" || car_to_view == "ferrari 812 superfast")
            {
                std::cout << Superfast;
                rent_car(availablecars, "Ferrari 812 Superfast", car_chosen, owner); //goes through the renting process
                if (car_chosen == true) //for some reason, the loop wasn't breaking
                {
                    break;
                }
            }
            else if(car_to_view == "Ferrari 812 GTS" || car_to_view == "ferrari 812 gts" || car_to_view == "ferrari 812 GTS")
            {
                std::cout << GTS;
                rent_car(availablecars, "Ferrari 812 GTS", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari SF90 Stradale" || car_to_view == "ferrari sf90 stradale" || car_to_view == "ferrari SF90 stradale")
            {
                std::cout << Stradale;
                rent_car(availablecars, "Ferrari SF90 Stradale", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari SF90 Spider" || car_to_view == "ferrari sf90 spider" || car_to_view == "ferrari SF90 spider")
            {
                std::cout << SFSpider;
                rent_car(availablecars, "Ferrari SF90 Spider", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari F8 Tributo" || car_to_view == "ferrari f8 tributo" || car_to_view == "ferrari F8 tributo")
            {
                std::cout << Tributo;
                rent_car(availablecars, "Ferrari F8 Tributo", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari F8 Spider" || car_to_view == "ferrari f8 spider" || car_to_view == "ferrari F8 spider")
            {
                std::cout << F8Spider;
                rent_car(availablecars, "Ferrari F8 Spider", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari Roma" || car_to_view == "ferrari roma")
            {
                std::cout << Roma;
                rent_car(availablecars, "Ferrari Roma", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari Portofino M" || car_to_view == "ferrari portofino m" || car_to_view == "ferrari portofino M")
            {
                std::cout << Portofino;
                rent_car(availablecars, "Ferrari Portofino M", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari Monza SP1" || car_to_view == "ferrari monza sp1" || car_to_view == "ferrari monza SP1")
            {
                std::cout << MonzaSP1;
                rent_car(availablecars, "Ferrari Monza SP1", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else if (car_to_view == "Ferrari Monza SP2" || car_to_view == "ferrari monza sp2" || car_to_view == "ferrari monza SP2")
            {
                std::cout << MonzaSP2;
                rent_car(availablecars, "Ferrari Monza SP2", car_chosen, owner);
                if (car_chosen == true)
                {
                    break;
                }
            }
            else 
            {
                std::cout << "That is not a valid car name, please type out the car name fully\n\n";
            }
        }
        if (availablecars.size() == 0) //if the size is nothign
        {
            std::cout << "There are no cars available, please check again later\n";
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
        renting_process(owner);
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