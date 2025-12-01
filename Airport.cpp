#include <iostream>
#include "Airport.h"

// UDT3: Airport implementation 

Airport::Airport() : 
code("NA"), 
city("NA"), 
annualPassengers(0.0) 
{}

Airport::~Airport() 
{ 
    std::cout << "Deallocation of UDT `Airport`\n"; 
}

void Airport::addRunway(int count) 
{
    for (int i = 0; i < count; ++i)
    {
        ++totalRunways;
        std::cout << "The `" << code << "` Airport just added a new runway! Total runways as of date: " << totalRunways << "\n";
    }

}

void Airport::updateAnnualPassengers(double newCount) 
{ 
    annualPassengers = newCount; 
}

void Airport::showAirportInfo() const
{
    std::cout << "Airport (code): " << code
              << "\nCity: " << city
              << "\nTotal Runways: " << totalRunways
              << "\nAnnual Passengers: " << annualPassengers
              << "\nInternational: " << (isInternational ? "Yes" : "No") << "\n";
}
