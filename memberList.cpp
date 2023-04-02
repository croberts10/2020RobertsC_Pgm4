//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//****************************************************
#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include <iomanip>
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
memberList::~memberList() {
	memberNode* currNode = head;

	if (head) {
		while (currNode != nullptr) {
			int id = currNode->getId();
			currNode = currNode->getNext();
			RemoveOneMember(id);
		}
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

			PushBack(new memberNode(currNode->getId(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium(), nullptr));
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
		PushBack(new memberNode(currNode->getId(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium(), nullptr));
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
// Function: AddOneMember										   *
// This function adds a new member to the end of the linked list.  *
// *****************************************************************

void memberList::AddOneMember(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		currNode->setNext(head);
		head = currNode;
	}
	cout << currNode->getId() << " member added." << endl;
}

/// *****************************************************************
// Function: RemoveOneMember				                        *
// This function removes a member from the linked list by their ID. *
// ******************************************************************
void memberList::RemoveOneMember(int id) {
	memberNode* currNode = head;
	memberNode* prevNode = nullptr;

	if (head == nullptr) {
		cout << "The list is empty." << endl;
		return;
	}

	while (currNode != nullptr) {
		if (currNode->getId() == id) {
			if (currNode == head) { // if it's the head node
				head = currNode->getNext();
			}
			else {
				prevNode->setNext(currNode->getNext());
				if (currNode == tail) { // if it's the tail node
					tail = prevNode;
				}
			}
			cout << id << " member removed." << endl;
			delete currNode;
			return;
		}
		prevNode = currNode;
		currNode = currNode->getNext();
	}
	cout << id << " is not a member" << endl;
}

// *****************************************************************
// Function: PrintMemberList					                   *
// This function prints a list of all members and their stats      *
// *****************************************************************
void memberList::PrintMemberList() const {
	memberNode* currNode = head;

	cout << "===============================================================================" << endl;
	cout << left << setw(10) << "Id" << setw(25) << "Name" << setw(20) << "Policy" << setw(10) << "Premium" << setw(10) << "Years" << endl;
	cout << left << setw(10) << "--" << setw(25) << "----" << setw(20) << "------" << setw(10) << "-------" << setw(10) << "-----" << endl;

	while (currNode != nullptr) {
		cout << left << setw(10) << currNode->getId() << setw(25) << currNode->getName() << setw(20) << currNode->getPolicy() <<
			setw(10) << currNode->getPremium() << setw(10) << currNode->getYear() << endl;
		currNode = currNode->getNext();
	}

	cout << "===============================================================================" << endl;
}


// *****************************************************************
// Function: PrintPolicy						                   *
// This function prints a list of members with the given policy.   *
// *****************************************************************

void memberList::PrintPolicy(string policy) {
	memberNode* currNode = head;
	bool found = false;
	double totalPremiums = 0;
	int policyCount = 0;

	cout << "===============================================================================" << endl;
	cout << "All " << policy << " members" << endl;
	cout << "===============================================================================" << endl;
	cout << left << setw(10) << "Id" << setw(25) << "Name" << setw(20) << "Policy" << setw(10) << "Premium" << setw(10) << "Years" << endl;
	cout << left << setw(10) << "--" << setw(25) << "----" << setw(20) << "------" << setw(10) << "-------" << setw(10) << "-----" << endl;

	while (currNode != nullptr) {
		if (currNode->getPolicy() == policy) {
			policyCount++;
			totalPremiums += currNode->getPremium();
			cout << left << setw(10) << currNode->getId() << setw(25) << currNode->getName() << setw(20) << currNode->getPolicy() <<
				setw(10) << currNode->getPremium() << setw(10) << currNode->getYear() << endl;
		}
		currNode = currNode->getNext();
	}

	cout << "-------------------------------------------------------------------------------" << endl;

	if (policyCount == 0) {
		cout << "Sorry, no " << policy << " members" << endl;
	}
	else {
		cout << "The average " << policy << " premium is $" << (totalPremiums / policyCount) << endl;

	}
	cout << "===============================================================================" << endl;
}

// *****************************************************************
// Function: PrintYear							                   *
// This function Prints the list of members						   *
// that have at least a stated amount of years on their policy     *							
// *****************************************************************
void memberList::PrintYear(int year) {
	memberNode* currNode = head;
	bool found = false;

	cout << "===============================================================================" << endl;
	cout << "Members of at least " << year << " years" << endl;
	cout << "===============================================================================" << endl;
	cout << left << setw(10) << "Id" << setw(25) << "Name" << setw(20) << "Policy" << setw(10) << "Premium" << setw(10) << "Years" << endl;
	cout << left << setw(10) << "--" << setw(25) << "----" << setw(20) << "------" << setw(10) << "-------" << setw(10) << "-----" << endl;


	while (currNode != nullptr) {
		if ((currNode->getYear()) >= year) {
			found = true;
			cout << left << setw(10) << currNode->getId() << setw(25) << currNode->getName() << setw(20) << currNode->getPolicy() <<
				setw(10) << currNode->getPremium() << setw(10) << currNode->getYear() << endl;
			
		}
		currNode = currNode->getNext();
	}

	if (!found) {
		cout << "Sorry, no members with " << year << " or more years." << endl;
	}
}


// *****************************************************************
// Function: PrintLowestPremium									   *
// This function prints the name of and stats of the person with   *
// the lowest premium.											   *
// *****************************************************************
void memberList::PrintLowPremium() {
	memberNode* curr = head;
	memberNode* lowest = head;

	while (curr != nullptr) {
		if (curr->getPremium() < lowest->getPremium()) {
			lowest = curr;
		}
		curr = curr->getNext();
	}

	cout << "Member with the lowest premium: " << endl;
	cout << left << setw(10) << "Id" << setw(25) << "Name" << setw(20) << "Policy" << setw(10) << "Premium" << setw(10) << "Years" << endl;
	cout << left << setw(10) << "--" << setw(25) << "----" << setw(20) << "------" << setw(10) << "-------" << setw(10) << "-----" << endl;
	cout << left << setw(10) << lowest->getId() << setw(25) << lowest->getName() << setw(20) << lowest->getPolicy() <<
		setw(10) << lowest->getPremium() << setw(10) << lowest->getYear() << endl;
	cout << lowest->getName() << " has the lowest premium of " << lowest->getPremium() << " dollar(s)." << endl;
	cout << "===============================================================================" << endl;
}




