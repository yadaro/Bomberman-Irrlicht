/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Serialize
*/

#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <unordered_map>
#include <fstream>

class Serialize {
public:
	Serialize(const std::unordered_map<std::string, int> &map
		, const std::string &file)  : _map(map), _file(file) {
		openFile();
		};
	~Serialize(){
		_buffFile.close();
	};

private:

	/**
	*** Variables  
	**/

	std::unordered_map<std::string, int>	_map;
	std::string				_file;
	std::ofstream				_buffFile;

	/**
	*** Functions Prototypes
	**/

	void openFile();
	void writeJSON();
};

#endif /* !SERIALIZE_HPP_ */
