#include <stdio.h> //sytem()

#include <iostream> // cin, cout
#include <string>

using namespace std;

enum CarModel
{
    kGol,
    kAmarok,
    kFox
};

class Car
{
public:
    string name_ = "Generic Car";
    virtual string ToggleAirConditioner() = 0;
    virtual string ToggleIgnition() = 0;
    virtual string ToggleFrontLight() = 0;
};

class Gol : public Car
{
public:
    Gol()
    {
        this->name_ = "Gol";
    }
    string ToggleAirConditioner() override
    {
        return "There's no AC in your Gol";
    }
    string ToggleIgnition() override
    {
        return "You try to start your Gol, but nothing happens";
    }
    string ToggleFrontLight() override
    {
        return "Front light toggled, but one of them is burned out.";
    }
};

class Amarok : public Car
{
public:
    Amarok()
    {
        this->name_ = "Amarok";
    }
    string ToggleAirConditioner() override
    {
        return "AC toggled";
    }
    string ToggleIgnition() override
    {
        return "Ignition toggled";
    }
    string ToggleFrontLight() override
    {
        return "Front light toggled";
    }
};

class Fox : public Car
{
public:
    Fox()
    {
        this->name_ = "Fox";
    }
    string ToggleAirConditioner() override
    {
        return "There's no AC";
    }
    string ToggleIgnition() override
    {
        return "Ignition toggled";
    }
    string ToggleFrontLight() override
    {
        return "Front lights toggled";
    }
};

/**
 * Implements a Car factory.
 * 
 * NOTE: As the factory needs to possibly return differents types of cars, 
 * this function's return type is a pointer to the super class Car.
 * 
 * @return pointer to a Car object, default is Gol
 */
Car *CreateCar(CarModel model)
{
    switch (model)
    {
    case kGol:
        return new Gol;

    case kAmarok:
        return new Amarok;

    case kFox:
        return new Fox;

    default:
        return new Gol;
    }
}

/**
 * Listens to keyboard and gets first typed character.
 * 
 * Reads keyboard buffer using cin.get() until its value is not a LINE_FEED
 * Finally, ignores line feed with cin.ignore()
 * 
 * @return an int representing a valid answer to any questions
 */
int GetOption()
{
    int option;
    do
    {
        option = cin.get();
    } while (option == 10);

    cin.ignore();
    return option - 48;
}

/**
 * Selects a car model
 * @return CarModel
*/
CarModel CarSelectionMenu()
{
    while (1)
    {
        system("clear");
        cout << "Choose a car model:\n";
        cout << "1 - Gol\n";
        cout << "2 - Amarok\n";
        cout << "3 - Fox\n";
        // cout << "Any key - Generic Car\n";

        switch (GetOption())
        {
        case 1:
            return kGol;

        case 2:
            return kAmarok;

        case 3:
            return kFox;
        }
    }
}

void UseCar(Car *car)
{
    cout << "1 - Toggle air conditioner\n";
    cout << "2 - Toggle ignition\n";
    cout << "3 - Toggle front lights\n";
    cout << "Any key - Select another car\n";
    while (1)
    {
        switch (GetOption())
        {
        case 1:
            cout << car->ToggleAirConditioner() << endl;
            break;

        case 2:
            cout << car->ToggleIgnition() << endl;
            break;

        case 3:
            cout << car->ToggleFrontLight() << endl;
            break;

        default:
            return;
        }
    }
}

int main()
{
    Car *MyCar;

    while (1)
    {
        MyCar = CreateCar(CarSelectionMenu());
        cout << "What do you wanna do with your " << MyCar->name_ << "?\n\n";
        UseCar(MyCar);
    }
    return 0;
}