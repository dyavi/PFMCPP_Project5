#include <iostream>
#include "Airline.h"

// UDT4: Airline implementation 

Airline::Airline()
{
    mainFlight.airline = "UFO";
    originAirport.code = "NA";
    destinationAirport.code = "NA";
}

Airline::~Airline()
{
    std::cout << "Deallocation of UDT `Airline`\n";
}

void Airline::scheduleRoute(const std::string& originCode, const std::string& destCode)
{
    // Set airport codes for origin/destination for simplicity
    originAirport.code = originCode;
    destinationAirport.code = destCode;

    // and tie the flight's origin/destination to the airport codes for simplicity
    mainFlight.origin = originAirport.code;
    mainFlight.destination = destinationAirport.code;

    std::cout << "Airline scheduled route from " 
              << originAirport.code << " to " 
              << destinationAirport.code << "\n";
}

void Airline::showAirlineInfo() const
{
    std::cout << "\n=== Airline Information ===\n";
    std::cout << "Main flight details:\n";
    mainFlight.showFlightInfo();

    std::cout << "\nOrigin airport details:\n";
    originAirport.showAirportInfo();

    std::cout << "\nDestination airport details:\n";
    destinationAirport.showAirportInfo();
    std::cout << "===========================\n";
}

// AirlineWrapper class definition per instruction #4 of project 5 part 3.
struct AirlineWrapper
{
    AirlineWrapper(Airline* _airline) : airlinePtr(_airline) { }
    ~AirlineWrapper() { delete airlinePtr; }
    Airline* airlinePtr = nullptr;
};

