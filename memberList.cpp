//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//****************************************************
#include "memberNode.h"
#include "memberList.h"

#include <iostream>
using namespace std;

//****************************************************
// Function: memberList  (Constructor)               *
// This function set the head and tail to nullptr    *
//****************************************************
memberList::memberList()
{

	head = nullptr;
	tail = nullptr;

}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(memberList& rhs) {
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(currNode->getName(), currNode->getId(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium()));
			currNode = currNode->getNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: memberList(memberList& rhs)                   *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList::memberList(const memberList& rhs) {
	memberNode* currNode = rhs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(currNode->getName(), currNode->getId(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium()));
		currNode = currNode->getNext();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->setNext(currNode);
		tail = currNode;
	}
}
// *****************************************************************
// Function: addOneMember										   *
// This function adds a new member to the end of the linked list.  *
// *****************************************************************

void memberList::addOneMember(memberNode* currNode) {
	PushBack(currNode);
}

// Function: removeOneMember
// This function removes a member from the linked list by their ID.
void memberList::removeOneMember(int id) {
	memberNode* currNode = head;
	memberNode* prevNode = nullptr;
	while (currNode != nullptr) {
		if (currNode->getId() == id) {
			if (prevNode == nullptr) { // if it's the head node
				head = currNode->getNext();
			}
			else {
				prevNode->setNext(currNode->getNext());
			}
			if (currNode == tail) { // if it's the tail node
				tail = prevNode;
			}
			delete currNode;
			break;
		}
		prevNode = currNode;
		currNode = currNode->getNext();
	}
}


// Function: PrintPolicy
// This function prints a list of members with the given policy.
void memberList::PrintPolicy(string policy) {
	memberNode* curr = head;
	double total_premium = 0;
	int count = 0;
	bool found = false;

	cout << "Members with policy: " << policy << endl;
	cout << "ID\tName\tPolicy\tYear\tPremium" << endl;

	while (curr != nullptr) {
		if (curr->getPolicy() == policy) {
			cout << curr->getId() << "\t" << curr->getName() << "\t" << curr->getPolicy() << "\t" << curr->getYear() << "\t" << curr->getPremium() << endl;
			total_premium += curr->getPremium();
			count++;
			found = true;
		}
		curr = curr->getNext();
	}

	if (!found) {
		cout << "No members found with policy: " << policy << endl;
	}
	else {
		cout << "Average premium of members with policy " << policy << ": $" << total_premium / count << endl;
	}
}

// Function: PrintYear
// This function prints a list of members who have been with the company for equal to or more than the given year.
void memberList::PrintYear(int year) {
	memberNode* curr = head;
	bool found = false;

	cout << "Members who have been with the company for " << year << " or more years:" << endl;
	cout << "ID\tName\tPolicy\tYear\tPremium" << endl;

	while (curr != nullptr) {
		if ((2023 - curr->getYear()) >= year) {
			cout << curr->getId() << "\t" << curr->getName() << "\t" << curr->getPolicy() << "\t" << curr->getYear() << "\t" << curr->getPremium() << endl;
			found = true;
		}
		curr = curr->getNext();
	}

	if (!found) {
		cout << "No members found who have been with the company for " << year << " or more years." << endl;
	}
}

// Function: printLowPremium
// This function prints the entire member list.
void memberList::printLowPremium() {
	memberNode* curr = head;
	memberNode* lowest = head;

	while (curr != nullptr) {
		if (curr->getPremium() < lowest->getPremium()) {
			lowest = curr;
		}
		curr = curr->getNext();
	}

	cout << "Member with the lowest premium:" << endl;
	cout << "ID\tName\tPolicy\tYear\tPremium" << endl;
	cout << lowest->getId() << "\t" << lowest->getName() << "\t" << lowest->getPolicy() << "\t" << lowest->getYear() << "\t" << lowest->getPremium() << endl;
}

void memberList::swap(memberList& first, memberList& second)
{
}



