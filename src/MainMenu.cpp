//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "MainMenu.hpp"
#include "SuperEntity.hpp"

MainMenu::MainMenu()
{}

MainMenu::~MainMenu()
{}

std::vector<SuperEntity *> MainMenu::generate(unsigned int width, unsigned int height)
{
	std::vector<SuperEntity *> menu;

	(void)width;
	(void)height;
	// declartion of shapes
	Entitys::Rect *rect1 = new Entitys::Rect("./media/bomberman.png");
	Entitys::Rect *button1 = new Entitys::Rect("./media/square.jpg");
	Entitys::Rect *button2 = new Entitys::Rect("./media/square.jpg");
	Entitys::Rect *button3 = new Entitys::Rect("./media/square.jpg");
	Entitys::Txt *text1 = new Entitys::Txt("Start");
	Entitys::Txt *text2 = new Entitys::Txt("Setting");
	Entitys::Txt *text3 = new Entitys::Txt("Quit");

	rect1->setInfo(tools::Info<float>(
		tools::v3<float>(600, 600, 0), // pos
		tools::v3<float>(18, 14.5, 0), // dim
		tools::v3<float>(0, 0, 0) // deg or rotate
	));
	button1->setInfo(tools::Info<float>(
		tools::v3<float>(600, 604, -0.01), // pos
		tools::v3<float>(4, 1.2, 0), // dim
		tools::v3<float>(0, 0, 0) // deg or rotate
	));
	button2->setInfo(tools::Info<float>(
		tools::v3<float>(600, 590, -0.01), // pos
		tools::v3<float>(4, 1.2, 0), // dim
		tools::v3<float>(0, 0, 0) // deg or rotate
	));
	button3->setInfo(tools::Info<float>(
		tools::v3<float>(600, 576.5, -0.01), // pos
		tools::v3<float>(2, 1.2, 0), // dim
		tools::v3<float>(0, 0, 0) // deg or rotate
	));
	text1->setInfo(
		tools::v2<float>(550, 450), // pos
		tools::v2<float>(655, 500) // dim
	);
	text2->setInfo(
		tools::v2<float>(520, 550), // pos
		tools::v2<float>(700, 600) // dim
	);
	text3->setInfo(
		tools::v2<float>(560, 640), // pos
		tools::v2<float>(640, 690) // dim
	);

	// save shapes
	menu.push_back(rect1);
	menu.push_back(button1);
	menu.push_back(button2);
	menu.push_back(button3);
	menu.push_back(text1);
	menu.push_back(text2);
	menu.push_back(text3);
	return menu;
}