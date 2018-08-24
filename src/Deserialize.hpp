/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Deserialize
*/

#ifndef DESERIALIZE_HPP_
#define DESERIALIZE_HPP_

#include <iostream>
#include <fstream>
#include <unordered_map>

class Deserialize {
public:
	Deserialize(std::string const &save) :_save(save) {
		openFile();
	};
	~Deserialize() {
		_file.close();
	};
	std::unordered_map<std::string, int> getMap() const ;

private:
	std::string _save;
	std::ifstream _file;
	std::unordered_map<std::string, int> _map;
	void openFile();
	void fillMap();
	void parser();
};

#endif /* !DESERIALIZE_HPP_ */
