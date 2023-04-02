#pragma once
#ifndef MEMBERNODE_H
#define MEMBERNODE_H
#pragma once

#include <iostream>
/* Program #4 - BG Insurance
//
// Programmer:  Connor Roberts
//
// Class:  CS 2020, Spring 2023, 9:30-10:20
//
// Due Date: April 2, 2023
//
// Purpose: The memberNode.h file is a file that declares the member functions of the memberList.cpp file.
*/

#include <cstdlib>
#include <string>
using namespace std;

class memberNode {
public:
    // Set getter and setter functions for all data types, accessable by the user
    memberNode(int id, string name, string policy, int year, double premium, memberNode* next);
    ~memberNode();
    memberNode();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    string getPolicy() const;
    void setPolicy(string policy);

    int getYear() const;
    void setYear(int year);

    double getPremium() const;
    void setPremium(double premium);

    memberNode* getNext() const;
    void setNext(memberNode* next);

private:
    // private data for each node
    int id;
    string name;
    string policy;
    int year;
    double premium;
    memberNode* next;
};

#endif  // MEMBERNODE_H

