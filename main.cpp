/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4

 Don't #include what you don't use

 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.

 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'

 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )

 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 

 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.

 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h

 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.

 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */





/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"


int main()
{

    std::cout << "=================================== Testing UDT1: `Book` and its nested UDT: `Chapter` ===================================\n";

    std::cout << "\n********************************\nExample 1. `Book` Instance #1\n********************************\n" ;

    BookWrapper book1( new Book() );

    std::cout << "\nBook1 Info before being updated (price and edition will be updated):\n";

    book1.bookPtr->showBookInfo();
    book1.bookPtr->updatePrice(29.99f);
    book1.bookPtr->updateEdition(2);

    std::cout << "\nBook1 Info after being updated:\n";

    book1.bookPtr->showBookInfo();

    std::cout << "\n********************************\nExample 2. `Book` Instance #2\n********************************\n" ;

    BookWrapper book2( new Book() );

    book2.bookPtr->title = "Atomic Habits";
    book2.bookPtr->author = "James Clear";
    book2.bookPtr->publicationYear = 2018;
    book2.bookPtr->price = 18.88f;  

    std::cout << "\nBook2 Info before being updated (price and edition will be updated):\n";

    book2.bookPtr->showBookInfo();
    book2.bookPtr->updatePrice(22.50f);
    book2.bookPtr->updateEdition(2);

    std::cout << "\nBook2 Info after being updated:\n";

    book2.bookPtr->showBookInfo();

    std::cout << "\n";

    std::cout << "\n********************************\nExample 3. `Book::Chapter` Instance #1\n********************************\n" ;

    Book::Chapter chapter1;

    chapter1.updateSummary("Chapter 1 shows some really cool designs!.");

    std::cout << "Original assumed grade before reading: B" << "\n";

    chapter1.gradeChapter('B');
    chapter1.reviewChapter(true);

    std::cout << "Version `OUTSIDE`\n"
              << "Chapter1 summary: " << chapter1.summary
              << "\nEnjoyable: " << (chapter1.isEnjoyable ? "Yes" : "No")
              << "\nGrade (final/in the end): " << chapter1.chapterGrade << "\n\n";

    chapter1.printDetailedMemberInfo();

    std::cout << "\n********************************\nExample 4. `Book::Chapter` Instance #2\n********************************\n" ;

    Book::Chapter chapter2;

    chapter2.updateSummary("Chapter 2 introduces identity-based habits and small wins.");

    std::cout << "Original assumed grade (before reading): C" << "\n";

    chapter2.gradeChapter('C');
    chapter2.reviewChapter(true);

    std::cout << "Version `OUTSIDE`\n"
              << "Chapter2 summary: " << chapter2.summary
              << "\nEnjoyable: " << (chapter2.isEnjoyable ? "Yes" : "No")
              << "\nGrade (final/in the end): " << chapter2.chapterGrade << "\n\n";

    chapter2.printDetailedMemberInfo();

    std::cout << "=================================== Finished testing UDT1: `Book` and its nested UDT: `Chapter` =================================== \n\n";


    std::cout << "=================================== Testing UDT2: `Flight` and its nested UDT: `PassengerSeat` ===================================\n";

    std::cout << "\n********************************\nExample 5. `Flight` Instance #1\n********************************\n" ;

    FlightWrapper flight1( new Flight() );

    // Initialize flight1
    flight1.flightPtr->flightNumber = "AA101";
    flight1.flightPtr->airline      = "American Airlines";
    flight1.flightPtr->origin       = "JFK";
    flight1.flightPtr->destination  = "LAX";

    // Call all member functions on flight1
    flight1.flightPtr->boardPassenger(2);
    flight1.flightPtr->updateDuration(6.0f);       
    flight1.flightPtr->showFlightInfo();

    std::cout << "\n********************************\nExample 6. `Flight` Instance #2\n********************************\n" ;

    FlightWrapper flight2( new Flight() );

    flight2.flightPtr->flightNumber = "DL220";
    flight2.flightPtr->airline      = "Delta Air Lines";
    flight2.flightPtr->origin       = "ATL";
    flight2.flightPtr->destination  = "SFO";

    flight2.flightPtr->boardPassenger(4);
    flight2.flightPtr->updateDuration(5.0f);
    flight2.flightPtr->showFlightInfo();

    std::cout << "\n********************************\nExample 7. `Flight::PassengerSeat` Instance #1\n********************************\n" ;

    Flight::PassengerSeat seat1;

    seat1.seatNumber = 12;
    seat1.seatClass  = 'E'; // Economy
    seat1.assignPassenger("Mr. Johnson", "ALC12345");

    std::cout << "Version `OUTSIDE`\n"
              << "Seat1 originally assigned to: " << seat1.passengerName
              << " (ID: " << seat1.passengerID << ")"
              << ", seat number: " << seat1.seatNumber
              << ", extra legroom: " << (seat1.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat1.printDetailedMemberInfo();

    seat1.requestExtraLegroom(true);

    std::cout << "Version `OUTSIDE`\n"
              << "After 30 mins this passenger requested extra legroom: " << seat1.passengerName
              << " (ID: " << seat1.passengerID << ")"
              << ", seat number: " << seat1.seatNumber
              << ", extra legroom: " << (seat1.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat1.printDetailedMemberInfo();

    seat1.releaseSeat(); 

    std::cout << "Version `OUTSIDE`\n"
              << "Seat1 after release, passenger name: \"" 
              << seat1.passengerName << "\"\n\n";

    seat1.printDetailedMemberInfo();

    std::cout << "\n********************************\nExample 8. `Flight::PassengerSeat` Instance #2\n********************************\n" ;

    Flight::PassengerSeat seat2;

    seat2.seatNumber = 3;
    seat2.seatClass  = 'B'; 

    seat2.assignPassenger("Esther Smith", "BOB98765");
    seat2.requestExtraLegroom(true);

    std::cout << "Version `OUTSIDE`\n"
              << "Seat2 assigned to: " << seat2.passengerName
              << " (ID: " << seat2.passengerID << ")"
              << ", seat number: " << seat2.seatNumber
              << ", seat class: " << seat2.seatClass
              << ", extra legroom: " << (seat2.hasExtraLegroom ? "Yes" : "No")
              << "\n";

    seat2.printDetailedMemberInfo();

    seat2.releaseSeat();

    std::cout << "Version `OUTSIDE`\n"
              << "Seat2 after release, passenger name: \"" 
              << seat2.passengerName << "\"\n\n";

    seat2.printDetailedMemberInfo();


    std::cout << "=================================== Finished testing UDT2: `Flight` and its nested UDT: `PassengerSeat` ===================================\n";

    std::cout << "\n=================================== Testing UDT3: `Airport ` (no nested UDT here) ===================================\n";

    std::cout << "\n********************************\nExample 9. `Airport` Instance #1\n********************************\n" ;

    AirportWrapper airport1( new Airport() );

    // Initialize airport1: JFK, New York
    airport1.airportPtr->code = "JFK";
    airport1.airportPtr->city = "New York";
    airport1.airportPtr->isInternational = true;
    airport1.airportPtr->totalRunways = 4;

    airport1.airportPtr->updateAnnualPassengers(75000000.0);
    airport1.airportPtr->showAirportInfo();   

    std::cout << "After adding one more runaway to the airport...\n";

    airport1.airportPtr->addRunway();         
    airport1.airportPtr->showAirportInfo(); 

    std::cout << "\n********************************\nExample 10. `Airport` Instance #2\n********************************\n" ;

    AirportWrapper airport2( new Airport() );
    airport2.airportPtr->code = "LAX";

    airport2.airportPtr->city = "Los Angeles";
    airport2.airportPtr->isInternational = true;

    airport2.airportPtr->updateAnnualPassengers(88900000.0);
    airport2.airportPtr->showAirportInfo();
    airport2.airportPtr->addRunway(2);

    std::cout << "After adding two more runaway to the airport...\n";

    airport2.airportPtr->showAirportInfo();

    std::cout << "\n=================================== Finished testing UDT3: `Airport ` (no nested UDT here) ===================================\n";

    std::cout << "\n=================================== Testing UDT4: `Airline` ===================================\n";

    std::cout << "\n********************************\nExample 11. `Airport` Instance #1\n********************************\n" ;

    AirlineWrapper airline1( new Airline() );

    airline1.airlinePtr->mainFlight.flightNumber = "AA101";
    airline1.airlinePtr->mainFlight.airline      = "American Airlines";
    airline1.airlinePtr->mainFlight.boardPassenger(6);

    airline1.airlinePtr->originAirport.code      = "JFK";
    airline1.airlinePtr->originAirport.city      = "New York";
    airline1.airlinePtr->originAirport.annualPassengers = 75000000.0;

    airline1.airlinePtr->destinationAirport.code = "LAX";
    airline1.airlinePtr->destinationAirport.city = "Los Angeles";
    airline1.airlinePtr->destinationAirport.annualPassengers = 88900000.0;

    airline1.airlinePtr->scheduleRoute("JFK", "LAX");
    airline1.airlinePtr->showAirlineInfo();

    std::cout << "\n********************************\nExample 12. `Airport` Instance #2\n********************************\n" ;

    AirlineWrapper airline2( new Airline() );

    airline2.airlinePtr->mainFlight.flightNumber = "DL220";
    airline2.airlinePtr->mainFlight.airline      = "Delta Air Lines";

    airline2.airlinePtr->mainFlight.boardPassenger(5);

    airline2.airlinePtr->originAirport.code      = "ATL";
    airline2.airlinePtr->originAirport.city      = "Atlanta";
    airline2.airlinePtr->originAirport.annualPassengers = 5670000.0;

    airline2.airlinePtr->destinationAirport.code = "SFO";
    airline2.airlinePtr->destinationAirport.city = "San Francisco";
    airline2.airlinePtr->destinationAirport.annualPassengers = 10348000.0;

    airline2.airlinePtr->scheduleRoute("ATL", "SFO");
    airline2.airlinePtr->showAirlineInfo();

    std::cout << "\n=================================== Finished testing UDT4: `Airline` ===================================\n";

    std::cout << "\n=================================== Testing UDT5: `Traveler` ===================================\n";

    std::cout << "\n********************************\nExample 13. `Airport` Instance #1\n********************************\n" ;

    TravelerWrapper traveler1( new Traveler() );

    traveler1.travelerPtr->favoriteBook.title  = "The 7 Habits of Highly Effective People";
    traveler1.travelerPtr->favoriteBook.author = "Stephen R. Covey";

    traveler1.travelerPtr->bookedFlight.flightNumber = "AA101";
    traveler1.travelerPtr->bookedFlight.airline      = "American Airlines";
    traveler1.travelerPtr->bookedFlight.origin       = "NY";
    traveler1.travelerPtr->bookedFlight.destination  = "LA";

    traveler1.travelerPtr->departureAirport.code     = "JFK";
    traveler1.travelerPtr->departureAirport.city     = "New York";
    traveler1.travelerPtr->departureAirport.annualPassengers = 20678970.0;

    traveler1.travelerPtr->arrivalAirport.code       = "LAX";
    traveler1.travelerPtr->arrivalAirport.city       = "Los Angeles";
    traveler1.travelerPtr->arrivalAirport.annualPassengers = 10678000.0;

    traveler1.travelerPtr->checkInAndshowItinerary("Chuck Norris", "HWC176545");
    traveler1.travelerPtr->finishChapter('A', true);

    std::cout << "Version `OUTSIDE`\n";
    std::cout << "Traveler1's favorite book: " << traveler1.travelerPtr->favoriteBook.title 
              << " by " << traveler1.travelerPtr->favoriteBook.author << "\n";
    std::cout << "Traveler1's flight: " << traveler1.travelerPtr->bookedFlight.flightNumber 
              << " (" << traveler1.travelerPtr->bookedFlight.airline << ") from " 
              << traveler1.travelerPtr->departureAirport.code << " to " 
              << traveler1.travelerPtr->arrivalAirport.code << "\n\n";

    traveler1.travelerPtr->printDetailedMemberInfo();


    std::cout << "\n********************************\nExample 14. `Airport` Instance #2\n********************************\n" ;

    TravelerWrapper traveler2( new Traveler() );

    traveler2.travelerPtr->favoriteBook.title  = "Sapiens: A Brief History of Humankind";
    traveler2.travelerPtr->favoriteBook.author = "Yuval Noah Harari";

    traveler2.travelerPtr->bookedFlight.flightNumber = "DL220";
    traveler2.travelerPtr->bookedFlight.airline      = "Delta Air Lines";
    traveler2.travelerPtr->bookedFlight.origin       = "ATL";
    traveler2.travelerPtr->bookedFlight.destination  = "SF";

    traveler2.travelerPtr->departureAirport.code     = "ATL";
    traveler2.travelerPtr->departureAirport.city     = "Atlanta";
    traveler2.travelerPtr->departureAirport.annualPassengers = 234232.0;

    traveler2.travelerPtr->arrivalAirport.code       = "SFO";
    traveler2.travelerPtr->arrivalAirport.city       = "San Francisco";
    traveler2.travelerPtr->arrivalAirport.annualPassengers = 534232.0;

    traveler2.travelerPtr->checkInAndshowItinerary("Dua Lee", "BOB98765");
    traveler2.travelerPtr->finishChapter('B', true);

    std::cout << "Traveler2's favorite book: " << traveler2.travelerPtr->favoriteBook.title 
              << " by " << traveler2.travelerPtr->favoriteBook.author << "\n";
    std::cout << "Traveler2's flight: " << traveler2.travelerPtr->bookedFlight.flightNumber 
              << " (" << traveler2.travelerPtr->bookedFlight.airline << ") from " 
              << traveler2.travelerPtr->departureAirport.code << " to " 
              << traveler2.travelerPtr->arrivalAirport.code << "\n\n";

    traveler2.travelerPtr->printDetailedMemberInfo();

    std::cout << "\n=================================== Finished testing UDT5: `Traveler` ===================================\n";

    std::cout << "good to go!" << std::endl;
}

