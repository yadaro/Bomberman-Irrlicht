//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _MAINMENU_
# define _MAINMENU_

#include <vector>
#include "SuperEntity.hpp"

class MainMenu {
public:
	MainMenu();
	~MainMenu();
	std::vector<SuperEntity *> generate(unsigned int, unsigned int);
private:
};

#endif /* _MAINMENU_ */