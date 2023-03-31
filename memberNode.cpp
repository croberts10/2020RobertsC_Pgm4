#include <iostream>
#include "memberNode.h"

using namespace std;

// Constructor
memberNode::memberNode(int id, string name, string policy, int year, double premium, memberNode* next) {
    this->id = id;
    this->name = name;
    this->policy = policy;
    this->year = year;
    this->premium = premium;
    this->next = nullptr;
}

// Destructor
memberNode::~memberNode() {};

// Getter and Setter functions

int memberNode::getId() const {
    return this->id;
}

void memberNode::setId(int id) {
    this->id = id;
}

string memberNode::getName() const {
    return this->name;
}

void memberNode::setName(string name) {
    this->name = name;
}

string memberNode::getPolicy() const {
    return this->policy;
}

void memberNode::setPolicy(string policy) {
    this->policy = policy;
}

int memberNode::getYear() const {
    return this->year;
}

void memberNode::setYear(int year) {
    this->year = year;
}

double memberNode::getPremium() const {
    return this->premium;
}

void memberNode::setPremium(double premium) {
    this->premium = premium;
}

memberNode* memberNode::getNext() const {
    return this->next;
}

void memberNode::setNext(memberNode* next) {
    this->next = next;
}