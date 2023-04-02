//******************************************************
// Program: memberListClient.cpp				       *
// Client program to use the memberNode and memberList *
// classes                                             *
//******************************************************
#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

memberNode* CreatecurrNode();
ifstream infile;				//file variable declared globally
//no need to pass as a parameter

int main() {

	infile.open("memberData.txt");		//open file for input

	memberList MyListOfmembers;			//memberList Object
	int yrs;
	int choice, Delid;					//input variables for processing the list
	string policy;
	memberNode* currNode;				//pointer to current node to be added to the list

	infile >> choice; // get a menu choice before entering the loop		

	while (choice != 7)					//loop until 7 is entered
	{
		if (choice == 1) {				//Add a newly created node to the front of the list
			currNode = CreatecurrNode();
			MyListOfmembers.AddOneMember(currNode);   //TODO: write the code to call the AddOneMember member function for your list

		}
		else if (choice == 2) {			//Finds and deletes a node based on the integer entered
			infile >> Delid;
			MyListOfmembers.RemoveOneMember(Delid);   //TODO: write the code to call the RemoveOneMember member function for your list
		}
		else if (choice == 3) {
			MyListOfmembers.PrintMemberList();   //TODO: write the code to call the PrintMemberList member function for your list
		}
		else if (choice == 4) {
			infile.ignore();	//TODO: write the code skip the new line character
			getline(infile, policy);
			MyListOfmembers.PrintPolicy(policy);   //TODO: write the code to call the PrintPolicy member function for your list
		}
		else if (choice == 5) {
			infile >> yrs;
			MyListOfmembers.PrintYear(yrs);    //TODO: write the code to call the PrintYear member function for your list
		}
		else if (choice == 6) {
			MyListOfmembers.PrintLowPremium();   //TODO: write the code to call the PrintLowPremium member function for your list
		}
		infile >> choice;				// get a menu choice in the loop	
	}

	return 0;
}

//-----------------------------------------------------
// Function: CreatecurrNode
// Create a node with member data
// Returns a pointer to that current node
//-----------------------------------------------------
memberNode* CreatecurrNode()
{
	memberNode* currNode;		//local pointer for the dynamic node that will be created
	string name;
	int id;
	string policy;
	int year;
	int premium;


	//input those variables to popluate your node.
	infile >> id;
	infile.ignore();
	getline(infile, name);
	getline(infile, policy);
	infile >> premium;
	infile >> year;

	//add those variables as arguments to populate your node.
	currNode = new memberNode(id, name, policy, premium, year, nullptr);

	return currNode;   //TODO write the code to return the pointer that points to the dynamic node

}