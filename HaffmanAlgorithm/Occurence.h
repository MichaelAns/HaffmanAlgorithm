#include <iostream>
#include <string>
#include <map>

#pragma once
class Occurence
{
private:
	std::map<char, int> _numberOfOccurence;
	std::string _source;
	void calculateNumberOfOccurence(std::string source);

public:
	Occurence();
	Occurence(std::string source);
	~Occurence() {}
	std::string getSource();
	std::map<char, int> getNumberOfOccurence();
	void printNumberOfOccurence();
	//std::map<char, int>* getNumberOfOccerence();
	//std::map<std::map<char, int>*, int>* getBaseEncode();
};

#include "Occurence.inl"

