#include <iostream>
#include "Flight.h"

//  UDT2: Flight implementation 

Flight::Flight() : 
flightNumber("NA"), 
origin("NA"), 
destination("NA") 
{}

Flight::~Flight() 
{ 
    std::cout << "Deallocation of UDT `Flight`\n"; 
}

void Flight::updateDuration(float newDuration) 
{ 
    durationHours = newDuration; 
}

void Flight::boardPassenger(int count) 
{ 
    std::cout << "\t Preparing to board passengers.\n";

    // for-while loop instructions
    for (int i = 0; i < count; ++i)
    {
        ++numberOfPassengers;
        std::cout << "\t\t-Passenger " << (i + 1) << " boarded.\n";
    }
}

void Flight::showFlightInfo() const
{
    std::cout << "Flight: " << flightNumber
              << "\nFrom: " << origin
              << "\nTo: " << destination
              << "\nPassengers: " << numberOfPassengers
              << "\nDuration: " << durationHours << " hours\n";
}

//  UDT2's neted UDT: PassengerSeat implementation 
Flight::PassengerSeat::PassengerSeat() : 
seatNumber(1), 
passengerName("NA"), 
passengerID("NA") 
{}

Flight::PassengerSeat::~PassengerSeat() 
{ 
    std::cout << "Deallocation of UDT `PassengerSeat` that is nested inside of `Flight`\n"; 
}

void Flight::PassengerSeat::assignPassenger(const std::string& name, const std::string& id) 
{
    passengerName = name;
    passengerID = id;
}

void Flight::PassengerSeat::requestExtraLegroom(bool request) 
{ 
    // simulate malfuntions for the for-while loop requirements
    int count = 5;
    int malfunctions = 0;
    while (malfunctions != count) 
    {
        hasExtraLegroom = ! hasExtraLegroom;
        ++malfunctions;
    }
    // eventually, do the right thing
    hasExtraLegroom = request; 
}

void Flight::PassengerSeat::releaseSeat() 
{
    passengerName = "";
    passengerID = "";
    hasExtraLegroom = false;
}

void Flight::PassengerSeat::printDetailedMemberInfo() const 
{
    std::cout << "Version `INSIDE`\n"
              << "Flight::PassengerSeat() assigned to: " << this->passengerName
              << " (ID: " << this->passengerID << ")"
              << ", seat number: " << this->seatNumber
              << ", extra legroom: " << (this->hasExtraLegroom ? "Yes" : "No")
              << "\n(in case seat has been released, print to confirm passenger's name is null): \t"
              << this->passengerName
              << "\n\n";
}
