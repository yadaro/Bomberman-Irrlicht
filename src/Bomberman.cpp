//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Bomberman member functions
//

#include "Bomberman.hpp"
#include <unordered_map>
#include <iostream>
#include <sstream>

void	Bomberman::clearBomb(int x, int y)
{
	int	range = 3;
	int	xFlame = x;
	int	yFlame = y;

	while (xFlame != x + range && _map[COORD(xFlame, y)] != WALL) {
		_map[COORD(xFlame, y)] = VOID;
		xFlame++;
	}
	xFlame = x;
	while (xFlame != x - range && _map[COORD(xFlame, y)] != WALL) {
		_map[COORD(xFlame, y)] = VOID;
		xFlame--;
	}
	xFlame = x;
	while (yFlame != y + range && _map[COORD(x, yFlame)] != WALL) {
		_map[COORD(x, yFlame)] = VOID;
		yFlame++;
	}
	yFlame = y;
	while (yFlame != y - range && _map[COORD(x, yFlame)] != WALL) {
		_map[COORD(x, yFlame)] = VOID;
		yFlame--;
	}	
}

SuperEntity * Bomberman::setBomb(Entity player)
{
	SuperEntity * bomb;

	bomb = new Entitys::Model3D(_objs[Entity::BOMB][0].first, tools::Info<float>(
		tools::v3<float>(_players[player]->_info._pos.x, _players[player]->_info._pos.y, _players[player]->_info._pos.z),
		tools::v3<float>(0.75, 0.75, 0.75),
		tools::v3<float>(0, 0, 0)
		), "./media/bomb.tga");

	return bomb;
}

void	Bomberman::Bomb(int x, int y)
{
	int	range = 3;
	int	xFlame = x;
	int	yFlame = y;

	while (xFlame != x + range && _map[COORD(xFlame, y)] != WALL) {
		_map[COORD(xFlame, y)] = FIRE;
		xFlame++;
	}
	xFlame = x;
	while (xFlame != x - range && _map[COORD(xFlame, y)] != WALL) {
		_map[COORD(xFlame, y)] = FIRE;
		xFlame--;
	}
	xFlame = x;
	while (yFlame != y + range && _map[COORD(x, yFlame)] != WALL) {
		_map[COORD(x, yFlame)] = FIRE;
		yFlame++;
	}
	yFlame = y;
	while (yFlame != y - range && _map[COORD(x, yFlame)] != WALL) {
		_map[COORD(x, yFlame)] = FIRE;
		yFlame--;
	}
}

std::string set_coord(int x, int y)
{
	std::stringstream buf;

	buf << x << ";" << y;
	return buf.str();
}

std::string get_coord(Entity entity,
	std::unordered_map<std::string, Entity> &map)
{
	int x;
	int y = 0;

	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			if (map[COORD(x, y)] == entity)
				return COORD(x, y);
			x++;
		}
		y++;
	}
	return NULL;
}

Bomberman::Bomberman()
	: _nbrOfPlayers(0),
	  _sizeCubeW(8),
	  _sizeCubeH(8)
{
	_objs = {
		{Entity::WALL, {std::make_pair("./media/wall.bmp", 8)}},
		{Entity::CRATE, {std::make_pair("./media/crate.jpg", 8)}},
		{Entity::PLAYER_1, {std::make_pair("./media/ninja.b3d", 8)}},
		{Entity::PLAYER_2, {std::make_pair("./media/ninja.b3d", 8)}},
		{Entity::PLAYER_3, {std::make_pair("./media/ninja.b3d", 8)}},
		{Entity::PLAYER_4, {std::make_pair("./media/ninja.b3d", 8)}},
		{Entity::BOMB, {std::make_pair("./media/bomb.obj", 8)}},
		{Entity::FIRE, {std::make_pair("./media/fire.obj", 8)}},
		{Entity::VOID, {std::make_pair("./media/floor.jpg", 0)}}};
}

void Bomberman::move_character(std::unordered_map<std::string, Entity> &map,
							   Entity entity, int new_x, int new_y)
{
	if (map[COORD(new_x, new_y)] == VOID)
	{
		map[get_coord(entity, map)] = VOID;
		map[COORD(new_x, new_y)] = entity;
	}
}

void Bomberman::place_players(std::unordered_map<std::string, Entity> &map, int nbPlayer)
{
	map[COORD(1, 1)] = PLAYER_1;
	map[COORD(2, 1)] = VOID;
	map[COORD(1, 2)] = VOID;
	if (nbPlayer > 1)
	{
		map[COORD(SIZE_MAP - 3, 1)] = PLAYER_2;
		map[COORD(SIZE_MAP - 2, 2)] = VOID;
	}
	if (nbPlayer > 2)
	{
		map[COORD(1, SIZE_MAP - 2)] = PLAYER_3;
		map[COORD(2, SIZE_MAP - 2)] = VOID;
		map[COORD(1, SIZE_MAP - 3)] = VOID;
	}
	if (nbPlayer > 3)
	{
		map[COORD(SIZE_MAP - 2, SIZE_MAP - 2)] = PLAYER_4;
		map[COORD(SIZE_MAP - 3, SIZE_MAP - 2)] = VOID;
		map[COORD(SIZE_MAP - 2, SIZE_MAP - 3)] = VOID;
	}
}

void Bomberman::fill_map(std::unordered_map<std::string, Entity> &map)
{
	int y = 0;
	int x;
	int difficulty = 2;

	srand(time(NULL));
	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			if (y == 0 || x == 0 ||
				y == SIZE_MAP - 1 || x == SIZE_MAP - 1 ||
				x % 2 != 1)
				map[COORD(x, y)] = WALL;
			if ((y == 1 || y == SIZE_MAP - 2 || y % 2 == 1) &&
				(x > 0 && x < SIZE_MAP - 1 && y > 0 && y < SIZE_MAP - 1))
				map[COORD(x, y)] = VOID;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			if (map[COORD(x, y)] == VOID)
			{
				if (rand() % difficulty == 1)
					map[COORD(x, y)] = CRATE;
			}
			x++;
		}
		y++;
	}
}

void Bomberman::init_map(std::unordered_map<std::string, Entity> &map)
{
	std::string pos;
	int x;
	int y = 0;

	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			pos = COORD(x, y);
			map[pos] = VOID;
			x = x + 1;
		}
		y = y + 1;
	}
	fill_map(map);
}

std::unordered_map<std::string, Entity> &Bomberman::createMap(int nbPlayers)
{
	init_map(_map);
	place_players(_map, nbPlayers);
	return _map;
}

std::unordered_map<std::string, Entity> &Bomberman::getMap()
{
	return _map;
}

void Bomberman::dispMap()
{
	std::string pos;
	int x;
	int y = 0;
	std::unordered_map<int, char> ascii;

	ascii[PLAYER_1] = 'A';
	ascii[PLAYER_2] = 'B';
	ascii[PLAYER_3] = 'C';
	ascii[PLAYER_4] = 'D';
	ascii[WALL] = '*';
	ascii[CRATE] = '#';
	ascii[FIRE] = 'F';
	ascii[VOID] = ' ';
	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			pos = COORD(x, y);
			std::cout << ascii[_map[pos]];
			x = x + 1;
		}
		std::cout << std::endl;
		y = y + 1;
	}
}

bool Bomberman::isEnd()
{
	std::string pos;
	int x;
	int y = 0;

	while (y < SIZE_MAP)
	{
		x = 0;
		while (x < SIZE_MAP)
		{
			pos = COORD(x, y);
			if (_map[pos] == PLAYER_1 || _map[pos] == PLAYER_2 || _map[pos] == PLAYER_3 || _map[pos] == PLAYER_4)
				return false;
			x = x + 1;
		}
		y = y + 1;
	}
	return true;
}

bool Bomberman::update_map(std::vector<PlayerInput>
	&inputs)
{
	std::vector<Entity> players = {PLAYER_1, PLAYER_2,
		PLAYER_3, PLAYER_4};

	bool vf = false;

	int c = 0;

	for (auto i : inputs) {
		if (i != NONE) {
			if (movePlayer(i, players[c], _map) == true)
				vf = false;
			else
				vf = true;
			i = NONE;
		}
		c++;
	}
	return vf;
}

SuperEntity *Bomberman::getPlayer(Entity player)
{
	return _players[player];
}

std::vector<SuperEntity *> Bomberman::generate(
	std::unordered_map<std::string, Entity> &mapGame,
	unsigned int width, unsigned int height)
{
	std::vector<SuperEntity *> mainGame;
	int size_w = 0;
	int size_h = 0;

	(void)width;
	(void)height;
	while (mapGame.find(COORD(size_w, size_h)) != mapGame.end())
		size_w += 1;
	size_h = size_w;
	if (size_h == 0 || size_w == 0) {
		std::cout << "map game too lil" << std::endl;
	}

	for (int y = 0; y < size_h; ++y)
	{
		for (int x = 0; x < size_w; ++x) {
			if (mapGame[COORD(x, y)] == Entity::PLAYER_1
				|| mapGame[COORD(x, y)] == Entity::PLAYER_2) {
				_players[_nbrOfPlayers] = new Entitys::Model3D(_objs[mapGame[COORD(x, y)]][0].first, tools::Info<float>(
					tools::v3<float>(((x * _sizeCubeW) * 10) + 40, ((y * _sizeCubeH) * 10) + 20, 900), // pos
					tools::v3<float>(_sizeCubeW, _sizeCubeH, _objs[mapGame[COORD(x, y)]][0].second),   // dim
					tools::v3<float>(-60, 0, 0) // deg or rotate
					), "./media/bomber.tga");
				mainGame.push_back(_players[_nbrOfPlayers]);
				mainGame.push_back(new Entitys::Rect(_objs[Entity::VOID][0].first, tools::Info<float>(
					tools::v3<float>((x * _sizeCubeW) * 10, (y * _sizeCubeH) * 10, 1000),	// pos
					tools::v3<float>(_sizeCubeW, _sizeCubeH, _objs[Entity::VOID][0].second), // dim
					tools::v3<float>(0, 0, 0)						// deg or rotate
					)));
				++_nbrOfPlayers;
			} else {
				mainGame.push_back(new Entitys::Rect(_objs[mapGame[COORD(x, y)]][0].first, tools::Info<float>(
					tools::v3<float>((x * _sizeCubeW) * 10, (y * _sizeCubeH) * 10, 1000), // pos
					tools::v3<float>(_sizeCubeW, _sizeCubeH, _objs[mapGame[COORD(x, y)]][0].second), // dim
					tools::v3<float>(0, 0, 0)							// deg or rotate
					)));
			}
		}
	}
	_saveGame = mainGame;
	return mainGame;
}

void Bomberman::mouvement(Entity player, PlayerInput mouve)
{	
	switch (mouve)
	{
		case PlayerInput::UP:
		std::cout << "up\n";
			_players[player]->_info._pos.y += (_sizeCubeH) * 10;
			_players[player]->_info._deg.x = -60;
			break;
		case PlayerInput::DOWN:
			_players[player]->_info._pos.y -= (_sizeCubeH)*10;
			_players[player]->_info._deg.x = 60;
			break ;
		case PlayerInput::LEFT:
			_players[player]->_info._pos.x -= (_sizeCubeH) * 10;
			_players[player]->_info._deg.x = 120;
			break ;
		case PlayerInput::RIGHT:
			_players[player]->_info._pos.x += (_sizeCubeH) * 10;
			_players[player]->_info._deg.x = 20;
			break ;
		default :
			break;
	}
}
