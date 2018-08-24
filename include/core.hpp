//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _CORE_
# define _CORE_

#include <vector>
#include <stack>
#include "SuperEntity.hpp"
#include "MainMenu.hpp"
#include "MenuGame.hpp"
#include "IGraphic.hpp"
#include "Bomberman.hpp"

class Core
{
	enum Phase {
		GAME_1,
		GAME_2,
		SETTING,
		QUIT
	};
public:
	Core(unsigned int width, unsigned int height);
	~Core();
	void run();
private:
	Phase _runMenu(IGraphic *graph);
	Phase _runGame(IGraphic *graph, Phase phase);
	Phase _runMenuGame(IGraphic *graph);
	Bomberman _game;
	MainMenu _mainMenu;
	MenuGame _menuGame;
	std::stack<std::vector<SuperEntity *>> _stack;
	unsigned int _width;
	unsigned int _height;
};

#endif /* _CORE_ */
