/*
 * Phrase.hpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
 */

#ifndef PHRASE_HPP_
#define PHRASE_HPP_

#include <iostream>
using namespace std;

class Phrase{
	friend class TNode;
	friend class BST;
	friend class Abbr;
	string abbr;
	string meaning;
public:
	Phrase(string s,string longer);
	Phrase();
};




#endif /* PHRASE_HPP_ */
