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
    void addOneMember(memberNode* currNode);

    // Remove one member
    void removeOneMember(int id);


    // Print member list
    void printMemberList() const;

    // Print members with a given policy and the average premium of those members
    void printPolicy(const string& policy) const;

    // Print members who have been with the company for equal to or more than the given year
    void printYear(int year) const;

    // Print the member with the lowest premium
    void printLowPremium();

private:
    memberNode* head; // Head pointer to the beginning of the list
    memberNode* tail; // Tail pointer to the end of the list


};
#endif