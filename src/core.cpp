//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <unistd.h>
#include <iostream>
#include "core.hpp"
#include "tools.hpp"
#include "libirrlicht.hpp"
#include "Bomberman.hpp"

Core::Core(unsigned int width, unsigned int height)
	: _width(width),
	  _height(height)
{
	_stack.push(_mainMenu.generate(width, height));
}

Core::~Core()
{
}

void Core::run()
{
	IGraphic *graph = new libIrrlicht;
	Core::Phase phase;

	graph->createWindow(tools::v2<int>(_width, _height), "Indie");
	graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
	while (_stack.empty() != true)
	{
		phase = _runMenu(graph);
		switch (phase) {
			case Phase::GAME_1: case Phase::GAME_2:
				_stack.push(_game.generate(_game.createMap(phase + 1),
					_width, _height));
				_runGame(graph, phase);
				break;
			case Phase::QUIT:
				return;
			default:
				break;
		}
	}
}

Core::Phase Core::_runMenu(IGraphic *graph)
{
	graph->draw_all(_stack.top());
	graph->playMusic("./media/bomberman-theme-remix.ogg");
	while (graph->isRun() != false) {
		if (graph->isMouseClicked() == true) {
			if (graph->getPosMouse().x > 470 && graph->getPosMouse().x < 730
				&& graph->getPosMouse().y > 437 && graph->getPosMouse().y < 514) {
				graph->deleteAll();
				_stack.push(_menuGame.generate());
				return _runMenuGame(graph);
			} else if (graph->getPosMouse().x > 470 && graph->getPosMouse().x < 730
				&& graph->getPosMouse().y > 530 && graph->getPosMouse().y < 608) {
				graph->deleteAll();
				return Phase::SETTING;
			} else if (graph->getPosMouse().x > 470 && graph->getPosMouse().x < 730
				&& graph->getPosMouse().y > 625 && graph->getPosMouse().y < 700) {
				graph->deleteAll();
				return Phase::QUIT;
			}
		}
		graph->displayAll();
	}
	return Phase::QUIT;
}

Core::Phase Core::_runMenuGame(IGraphic *graph)
{
	graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
	graph->draw_all(_stack.top());
	while (graph->isRun()) {
		if (graph->isMouseClicked() == true) {
			if (graph->getPosMouse().x > 350 && graph->getPosMouse().x < 550
				&& graph->getPosMouse().y > 520 && graph->getPosMouse().y < 600) {
				graph->deleteAll();
				_stack.pop();
				return Phase::GAME_1;
			} else if (graph->getPosMouse().x > 630 && graph->getPosMouse().x < 800
				&& graph->getPosMouse().y > 550 && graph->getPosMouse().y < 600) {
				graph->deleteAll();
				_stack.pop();
				return Phase::GAME_2;
			}
		}
		graph->displayAll();
	}
	return Phase::GAME_1;
}

Core::Phase Core::_runGame(IGraphic *graph, Phase phase)
{
	std::vector<Bomberman::PlayerInput> inputs = {
		Bomberman::NONE, Bomberman::NONE, Bomberman::NONE, Bomberman::NONE};
	int z = 0, q = 0, s = 0, d = 0;

	graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
	graph->draw_all(_stack.top());
	while (graph->isRun() != false) {
		if (graph->isKeyPressed("z")) {
			z++;
			if (z == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::UP;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_1, Bomberman::PlayerInput::UP);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_1));	
				z = 0;
			}
		} else if (graph->isKeyPressed("q")) {
			q++;
			if (q == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::LEFT;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_1, Bomberman::PlayerInput::LEFT);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_1));
				q = 0;
			}
		} else if (graph->isKeyPressed("d")) {
			d++;
			if (d == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::RIGHT;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_1, Bomberman::PlayerInput::RIGHT);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				d = 0;
			}
			graph->moveEntity(_game.getPlayer(Entity::PLAYER_1));
		} else if (graph->isKeyPressed("s")) {
			s++;
			if (s == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::DOWN;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_1, Bomberman::PlayerInput::DOWN);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_1));
				s = 0;
			}
		} else if (graph->isKeyPressed("up")) {
			q++;
			if (q == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::UP;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_2, Bomberman::PlayerInput::UP);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_2));
				q = 0;
			}
		} else if (graph->isKeyPressed("right")) {
			d++;
			if (d == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::RIGHT;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_2, Bomberman::PlayerInput::RIGHT);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_2));
				d = 0;
			}
		} else if (graph->isKeyPressed("left")) {
			s++;
			if (s == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::LEFT;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_2, Bomberman::PlayerInput::LEFT);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_2));
				s = 0;
			}
		} else if (graph->isKeyPressed("down")) {
			s++;
			if (s == 3) {
				graph->deleteAll();
				inputs[0] = Bomberman::DOWN;
				if (_game.update_map(inputs) == true)
					_game.mouvement(Entity::PLAYER_2, Bomberman::PlayerInput::DOWN);
				graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
				graph->draw_all(_stack.top());
				graph->moveEntity(_game.getPlayer(Entity::PLAYER_2));
				s = 0;
			}
		}
		if (graph->isKeyPressed("space")) {
			graph->deleteAll();
			_stack.top().push_back(_game.setBomb(Entity::PLAYER_1));
			graph->setCamera(tools::v3<float>(600, 600, -100), tools::v3<float>(600, 600, 0));
			graph->draw_all(_stack.top());
		}
		graph->displayAll();
	}
	return Phase::QUIT;
}
