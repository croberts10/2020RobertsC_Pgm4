/* Program #4 - BG Insurance
//
// Programmer:  Connor Roberts
//
// Class:  CS 2020, Spring 2023, 9:30-10:20
//
// Due Date: April 2, 2023
//
// Purpose: The memberList.h file is a file that declares the member functions of the memberList.cpp file.
*/

#pragma once
#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "memberNode.h"
using namespace std;

class memberList {
public:
    // Constructor
    memberList();

    // Destructor
    ~memberList();

    memberList& operator=(memberList& rhs);

    // Copy constructor
    memberList(const memberList& other);

    // Copy assignment
    memberList& operator=(memberList& rhs) const;

    // Pushback
    void PushBack(memberNode* currnode);

    // Add one member
    void AddOneMember(memberNode* currNode);

    // Remove one member
    void RemoveOneMember(int id);

    // Print member list
    void PrintMemberList() const;

    // Print members with a given policy and the average premium of those members
    void PrintPolicy(string policy);

    // Print members who have been with the company for equal to or more than the given year
    void PrintYear(int year);


    // Print the member with the lowest premium
    void PrintLowPremium();

private:
    memberNode* head; // Head pointer to the beginning of the list
    memberNode* tail; // Tail pointer to the end of the list


};
#endif