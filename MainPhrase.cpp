/*
 * MainPhrase.cpp
 *
 *  Created on: Apr 19, 2020
 *      Author: 13027
 */

#include <iostream>
#include "Abbr.hpp"
using namespace std;

int main() {
	/*
	cout <<"******Part 2 - testing left***********"<<endl;
	Abbr *abbr = new Abbr("Testleft.txt",2);
	cout << "************************************" << endl;
	abbr->tree->clearTree();
	delete abbr;
	cout <<endl<< "********* Part3: Testing right *********" << endl;
	abbr = new Abbr("Testright.txt",2);
	cout << "********End Part 3 *****************" << endl;

	abbr->tree->clearTree();
	delete abbr;
	cout << endl<<"********* Part 5: Testing leftright ********" << endl;
	abbr = new Abbr("TestLeftRight.txt",2);
	cout << "**********End Part 5 ***************" << endl;

	cout <<endl<<"***********Part 6:  Testing Find ************" << endl;
	TNode *tmp = abbr->tree->find("LY");
	tmp->printNode();

	tmp = abbr->tree->find("SAA");
	tmp->printNode();

	tmp = abbr->tree->find("DMI");
	tmp->printNode();
	cout << "**********End Part 6 **************************" << endl;

	cout << endl<<"*********Part 7: Testing Remove***************************" << endl;
	cout << "Removing no kids ('LY')"<< endl;
	abbr->tree->remove("LY");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();

	cout << "************************************" << endl;
	cout << "Removing one kid ('SAA')"<< endl;
	abbr->tree->remove("SAA");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();

	cout << "************************************" << endl;
	cout << "Removing two kid ('DMI')"<< endl;
	abbr->tree->remove("DMI");
	abbr->tree->printTreeIO();
	abbr->tree->printTreePre();
	abbr->tree->printTreePost();
	cout <<"************End Part 7 *******************" << endl;
	*/

	cout << "*************************Part 8 *********************" <<endl;
	//abbr->tree->clearTree();

	//delete abbr;
	cout << "********* Testing leftright ********" << endl;
	Abbr *abbrTree = new Abbr("abbr.txt",1);
	abbrTree->Interface();

	return 0;

}


