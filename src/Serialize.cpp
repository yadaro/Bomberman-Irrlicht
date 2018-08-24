/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Serialize
*/

#include <iostream>
#include "Serialize.hpp"

void Serialize::writeJSON()
{
	int i = 0;
	_buffFile << "{ \n\"pos\": {\n";
	for (auto it : _map) {
		i++;
		_buffFile << "\"";
		_buffFile << it.first;
		_buffFile << "\"";
		_buffFile << " : ";
		_buffFile << it.second;
		if (_map.size() != i) {
		_buffFile << ",\n";
		}
	}
	_buffFile << "}\n}";
}

void Serialize::openFile()
{
	_buffFile.open(_file);
	if (!_buffFile.is_open()) {
		std::cout << "open failed";
		return ;
	}
	writeJSON();
}

int main(int argc, char const *argv[])
{
	std::unordered_map<std::string, int> test;
	test.insert(std::make_pair("first", 12));
	test.insert(std::make_pair("second", 12));
	Serialize r(test, "oklm");
	return 0;
}
