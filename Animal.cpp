#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Animal.h"
using namespace std;

int main()
{
    int UserChoice;
    int random;

    vector<Animal*> container{ new Sheep(), new Cow(), new Frisian() }; // initiates new object of classes sheep, cow and frisian and adds them to vector container

    cout << "Enter the number of objects: ";
    cin >> UserChoice;

    //srand(time(NULL)); - stole from stackoverflow

    for (int a = 0; a < UserChoice; a++) // loop for user specified number of objects
    {
        random = rand() % container.size(); // random number generation
        Animal* ClonedAnimal = container[random]->clone(); // cloning animal
        container.push_back(ClonedAnimal); // adding cloned animal to container

        random = rand() % container.size();
        container[random]->speak(); // animal speaks
    }

    for (size_t a = 0; a < container.size(); a++) // deleting all objects in container
    {
        delete container[a];
    }

    return 0;
}
