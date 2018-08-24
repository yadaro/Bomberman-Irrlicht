//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "MenuGame.hpp"

MenuGame::MenuGame()
{}

MenuGame::~MenuGame()
{}

std::vector<SuperEntity *> MenuGame::generate()
{
	std::vector<SuperEntity *> menu;
	Entitys::Rect *rect1 = new Entitys::Rect("./media/bomberman.png");
	Entitys::Rect *button1 = new Entitys::Rect("./media/square.jpg");
	Entitys::Rect *button2 = new Entitys::Rect("./media/square.jpg");
	Entitys::Txt *text1 = new Entitys::Txt("1 player");
	Entitys::Txt *text2 = new Entitys::Txt("2 player");

	rect1->setInfo(tools::Info<float>(
	    tools::v3<float>(600, 600, 0), // pos
	    tools::v3<float>(18, 14.5, 0), // dim
	    tools::v3<float>(0, 0, 0)      // deg or rotate
	));
	button1->setInfo(tools::Info<float>(
	    tools::v3<float>(575, 590, -0.01), // pos
	    tools::v3<float>(4, 1.2, 0),       // dim
	    tools::v3<float>(0, 0, 0)	  // deg or rotate
	));
	button2->setInfo(tools::Info<float>(
	    tools::v3<float>(620, 590, -0.01), // pos
	    tools::v3<float>(4, 1.2, 0),       // dim
	    tools::v3<float>(0, 0, 0)	  // deg or rotate
	));
	text1->setInfo(
	    tools::v2<float>(350, 550), // pos
	    tools::v2<float>(520, 600)  // dim
	);
	text2->setInfo(
	    tools::v2<float>(630, 550), // pos
	    tools::v2<float>(800, 600)  // dim
	);

	// save shapes
	menu.push_back(rect1);
	menu.push_back(button1);
	menu.push_back(button2);
	menu.push_back(text1);
	menu.push_back(text2);
	return menu;
}