#pragma once
#ifndef MEMBERNODE_H
#define MEMBERNODE_H
#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class memberNode {
public:
    // Set getter and setter functions for all data types, accessable by the user
    memberNode(int id, string name, string policy, int year, double premium, memberNode* next);
    ~memberNode();

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

