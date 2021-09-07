#include "cars.h"

std::ostream& operator << (std::ostream& output, Ferrari_Car car) //allows us to print the car stats
{
    output << "\nName: " << car.Name << "\nEngine type: " << car.engine << "\nYear made: " << car.year << "\nHorsepower: " << car.horsepower << "\nFour Wheel Drive: " << std::boolalpha << car.four_wheel_drive << "\nTop Speed: " << car.top_speed << "km/h\n";
    return output;
}


void rent_car(std::vector<std::string> availablecars, std::string owner, std::vector<std::string> carlist)
{
   bool exit = false; //allows the loop below to be exited, only occurs if car is rented or no cars are available
   if (availablecars.size() == 0)
   {
       exit = true;
   }
   else
   {
        std::cout << "Choose an car to see its stats and if the car is available, you can rent it: \n";
   }
    while(exit == false) //rents the given car
    {
        std::string car_to_view = "";
        std::getline(std::cin, car_to_view); //gets the car that the user wants to hire
        std::string car_name;
        if (stringLower(car_to_view) == "Ferrari 812 Superfast")
        {
            std::cout << Superfast;
            car_name = "Ferrari 812 Superfast"; //sets the car name that the program needs to find
        }
        else if (stringLower(car_to_view) == "Ferrari 812 GTS")
        {
            std::cout << GTS;
            car_name = "Ferrari 812 GTS";
        }
        else if (stringLower(car_to_view) == "Ferrari SF90 Stradale")
        {
            std::cout << Stradale;
            car_name = "Ferrari SF90 Stradale";
        }
        else if (stringLower(car_to_view) == "Ferrari SF90 Spider")
        {
            std::cout << SFSpider;
            car_name = "Ferrari SF90 Spider";
        }
        else if (stringLower(car_to_view) == "Ferrari F8 Tributo")
        {
            std::cout << Tributo;
            car_name = "Ferrari F8 Tributo";
        }
        else if (stringLower(car_to_view) == "Ferrari F8 Spider")
        {
            std::cout << F8Spider;
            car_name = "Ferrari F8 Spider";
        }
        else if (stringLower(car_to_view) == "Ferrari Roma")
        {
            std::cout << Roma;
            car_name = "Ferrari Roma";
        }
        else if (stringLower(car_to_view) == "Ferrari Portofino M")
        {
            std::cout << Portofino;
            car_name = "Ferrari Portofino M";
        }
        else if (stringLower(car_to_view) == "Ferrari Monza SP1")
        {
            std::cout << MonzaSP1;
            car_name = "Ferrari Monza SP1";
        }
        else if (stringLower(car_to_view) == "Ferrari Monza SP2")
        {
            std::cout << MonzaSP2;
            car_name = "Ferrari Monza SP2";
        }
        if (std::find(availablecars.begin(), availablecars.end(), car_name) != availablecars.end()) //if the car is available
        {
            std::cout << "Do you want to rent this car? Please type yes or no\n";
            std::string rent_car;
            std::getline(std::cin, rent_car); //gets the car that the user wants to rent
            if (stringLower(rent_car) == "yes")
            {
                std::fstream file(car_name, std::ios::app);
                file << owner; //in the car file, says the car has been taken by this user
                std::cout << "Well done, the car has been succesfully rented\n";
                std::fstream file2(owner, std::ios::app);
                file2 << "\n" << car_name; //puts the car name in the user file
                exit = true; //allows the loop to be exited
            }
            else if (stringLower(rent_car) == "no")
            {
                std::cout << "Okay, please type another car's name to view its stats\n"; //if user does not want to rent this car
            }
            else
            {
                std::cout << "Invalid answer, please type a car's name to view its stats\n";
            }
        }
        else if(std::find(carlist.begin(), carlist.end(), car_name) != carlist.end())//if the car exists but is unavailable
        {
            std::cout << "This car is unavailable, so you can not rent it, please type another car to view its stats: \n";
        }
        else
        {
            std::cout << "That is not a valid car name, please type out the car name fully\n";
        }
    }
}


void renting_process(std::string owner) //user can rent a car
{
    std::string user_answer;
    std::cin >> user_answer;
    std::vector<std::string> carlist = { "Ferrari 812 Superfast", "Ferrari 812 GTS", "Ferrari SF90 Stradale", "Ferrari SF90 Spider", "Ferrari F8 Tributo", "Ferrari F8 Spider", "Ferrari Roma", "Ferrari Portofino M", "Ferrari Monza SP1", "Ferrari Monza SP2" };
    if (user_answer == "yes" || user_answer == "Yes") //if user answers yes
    {
        std::vector<std::string> availablecars; //holds an array of the cars that are available to be rented
        for (int current_car_from_carlist = 0; current_car_from_carlist < carlist.size(); ++current_car_from_carlist)
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears cin cooldown, as the program was skipping over this line
        rent_car(availablecars, owner, carlist);
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
        returning_process(user_details);
    }
}
