/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Deserialize
*/

#include "Deserialize.hpp"

std::unordered_map<std::string, int> Deserialize::getMap() const
{
	return (_map);
}

void Deserialize::fillMap()
{
	std::string buf;
	std::pair<std::string, int> tmp;
	for (;buf != "}", getline(_file, buf);) {
		if (buf == "}")
			break ;
		tmp.first = buf.substr(1, buf.find_last_of("\"") - 1);
		tmp.second = atoi(buf.substr(buf.find_last_of(":") + 1).c_str());
		std::cout << tmp.second;
	}
}

void Deserialize::parser()
{
	std::string buf;

	while (!_file.eof()) {
		getline(_file, buf);
		if (buf == "\"pos\": {")
			fillMap();
	}	
}

void Deserialize::openFile()
{
	_file.open(_save);
	if (_file.is_open()) {
		parser();
	}
	else {
		//throw
	}
}

int main(int argc, char const *argv[])
{
	Deserialize t("oklm");
	return 0;
}
