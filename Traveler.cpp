#include <iostream>
#include "Traveler.h"

// UDT5: Traveler implementation 

Traveler::Traveler()
{
    favoriteBook.title  = "Unkown Book";
    favoriteBook.author = "Unknown Author";
}

Traveler::~Traveler()
{
    std::cout << "Deallocation of UDT `Traveler`\n";
}

// this should be two separate functions, but I'd like to keep it simple for now as per instructions #6 of project 5 part 1
// also the parameters have been passed by 'const reference' per instruction #7 of project 5 part 3
void Traveler::checkInAndshowItinerary(const std::string& passengerName, const std::string& passengerID)
{
    Flight::PassengerSeat tempSeat;
    tempSeat.assignPassenger(passengerName, passengerID);
    tempSeat.requestExtraLegroom(true); 

    bookedFlight.boardPassenger();

    std::cout << "\nTraveler " << passengerName 
              << " (ID: " << passengerID << ") has checked in.\n";

    std::cout << "\n--- Itinerary ---\n";
    std::cout << "Departure airport:\n";
    departureAirport.showAirportInfo();

    std::cout << "\nArrival airport:\n";
    arrivalAirport.showAirportInfo();

    std::cout << "\nBooked flight:\n";
    bookedFlight.showFlightInfo();
    std::cout << "-----------------\n";
}

void Traveler::finishChapter(char grade, bool enjoyed)
{
    // Use the nested Book::Chapter UDT to model finishing a chapter
    Book::Chapter chapter;
    chapter.gradeChapter(grade);
    chapter.reviewChapter(enjoyed);

    std::cout << "\nTraveler finished a chapter of the book: " 
              << favoriteBook.title << "\n"
              << "Chapter grade: " << chapter.chapterGrade << "\n"
              << "Enjoyment: " << (chapter.isEnjoyable ? "Yes" : "No") << "\n";
}


void Traveler::printDetailedMemberInfo() const
{
    std::cout << "Version `INSIDE`\n";
    std::cout << "Traveler()'s favorite book: " << this->favoriteBook.title 
              << " by " << this->favoriteBook.author << "\n";
    std::cout << "Traveler()'s flight: " << this->bookedFlight.flightNumber 
              << " (" << this->bookedFlight.airline << ") from " 
              << this->departureAirport.code << " to " 
              << this->arrivalAirport.code << "\n\n";
}

