#pragma once
#include <string>
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak(void) = 0; // virtual function for speak
    virtual Animal* clone(void) = 0; // adding clone as a virtual function
    virtual ~Animal() {} // adding a virtual destructor
};

class Sheep : public Animal // defining class Sheep from base class animal
{
public:
    void speak(void) override {
        cout << "Sheep says: \t\tbaa!" << endl;
    }
    Animal* clone(void) override  // clone object of sheep 
    { 
        return new Sheep(*this); 
    }
};

class Cow : public Animal // defining class cow from base class Animal
{
public:
    void speak(void) override {
        cout << "Cow says: \t\tmoo!" << endl;
    }
    Animal* clone(void) override  // clone object of cow
    { 
        return new Cow(*this); 
    } 
};

class Frisian : public Cow // multi inheritance class deriving from Cow deriving from Animal
{
public:
    void speak(void) override {
        cout << "Frisian Cow says: \tmoo (in black and white)!" << endl; 
    }
    Animal* clone(void) override // clone object of frisian
    { 
        return new Frisian(*this); 
    } 
};
