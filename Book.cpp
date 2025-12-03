#include <iostream>
#include "Book.h"

// UDT1: Book implementation

Book::Book() : 
publicationYear(2024), 
title("Dieter Rams: As Little Design as Possible"), 
author("Sophie Lovell") 
{}

Book::~Book() 
{
    std::cout << "Class `Book` is now destroyed" << "\n";
}

void Book::updatePrice(float newPrice) 
{
    price = newPrice;

    // simulate some price fluctuations
    if (newPrice < price)
    {
        for (float p = price; p > newPrice; p -= 0.5f)
            price = p;
    }
    else
    {
        for (float p = price; p < newPrice; p += 0.5f)
            price = p;
    }    
}

void Book::updateEdition(int newEdition) 
{
    edition = newEdition;
}

void Book::showBookInfo() const
{
    std::cout << "```\n";
    std::cout << "Book: " << Book::title 
              << "\nAuthor: "  << Book::author 
              << "\nPublished in: "  << Book::publicationYear 
              << "\nPrice: "  << Book::price 
              << "\nEdition: "  << Book::edition << "\n";
    std::cout << "```\n";

}

// UDT1's Nested Class: Book::Chapter implementation


Book::Chapter::Chapter() : 
readingTimeHours(0.2f), 
summary("NA") 
{}

Book::Chapter::~Chapter() 
{
    std::cout << "Class `Chapter` that is nested inside of `Book` is now destroyed" << "\n";
}

void Book::Chapter::reviewChapter(bool status)
{
    isEnjoyable = status;

    // this is just to use the for/while loop, as per the instructions
    char previousGrade = chapterGrade;
    for (int i = 0; i < 9; ++i) 
    {
        if (i % 5 == 0)
        {
            chapterGrade = 'A';
        }
        else if (i % 3 == 0) 
        {
            chapterGrade = 'D';
        } 
        else 
        {
            chapterGrade = 'C';
        }
    }

    if (chapterGrade == previousGrade) 
        chapterGrade = 'O';
}

void Book::Chapter::updateSummary(const std::string& newSummary)
{
    summary = newSummary;
}

void Book::Chapter::gradeChapter(char grade)
{
    chapterGrade = grade;
}

void Book::Chapter::printDetailedMemberInfo() const
{
    std::cout << "Version `INSIDE`\n"
              << "Book::Chapter() summary: " << this->summary
              << "\nEnjoyable: " << (this->isEnjoyable ? "Yes" : "No")
              << "\nGrade (final/in the end): " << this->chapterGrade << "\n\n";
}
