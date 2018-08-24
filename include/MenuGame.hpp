//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _MENUGAME_
# define _MENUGAME_

#include <vector>
#include "SuperEntity.hpp"

class MenuGame {
public:
	MenuGame();
	~MenuGame();
	std::vector<SuperEntity *> generate();
      private:
};

#endif /* _MENUGAME_ */