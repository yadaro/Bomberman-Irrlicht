//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Bomberman header file
//

#ifndef BOMBERMAN_HPP_
# define BOMBERMAN_HPP_

# include <unordered_map>
# include <string>
# include <vector>
# include "SuperEntity.hpp"

# define SIZE_MAP 16
# define COORD(x, y) set_coord(x, y)
# define GET_X(x) atoi(x.substr(0, x.find(";")).c_str())
# define GET_Y(x) atoi(x.substr(x.find(";") + 1).c_str())

enum Entity {
	PLAYER_1,
	PLAYER_2,
	PLAYER_3,
	PLAYER_4,
	WALL,
	CRATE,
	FIRE,
	BOMB,
	VOID
};

class	Bomberman {
public:
// enum Entity {
// 	PLAYER_1,
// 	PLAYER_2,
// 	PLAYER_3,
// 	PLAYER_4,
// 	WALL,
// 	CRATE,
// 	VOID
// };
enum PlayerInput {
	NONE,
	UP,
	LEFT,
	RIGHT,
	DOWN
};
	Bomberman();
	~Bomberman() 
	{}
	std::unordered_map<std::string, Entity>	&createMap(int);
	std::vector<SuperEntity *> generate(
		std::unordered_map<std::string, Entity> &,
		unsigned int, unsigned int);
	std::unordered_map<std::string, Entity>	&getMap();
	bool            update_map(std::vector<PlayerInput> &);
	void		dispMap();
	bool		isEnd();
	SuperEntity *	getPlayer(Entity);
	void		mouvement(Entity, PlayerInput);
	void		Bomb(int, int);
	void		clearBomb(int, int);
	SuperEntity *		setBomb(Entity player);
private:
	void		init_map(std::unordered_map<std::string, Entity> &);
	void		fill_map(std::unordered_map<std::string, Entity> &);
	void		place_players(std::unordered_map<std::string, Entity> &, int);
	bool		movePlayer(PlayerInput, Entity,
				   std::unordered_map<std::string, Entity> &);
	void		move_character(std::unordered_map<std::string, Entity> &,
				       Entity, int, int);
	
	std::unordered_map<std::string, Entity>	_map;
	std::unordered_map<int, Entitys::Model3D *> _players;
	std::unordered_map<int, std::vector<std::pair<std::string, int> > > _objs;
	std::vector<SuperEntity *> _saveGame;
	int _nbrOfPlayers;
	int _sizeCubeW;
	int _sizeCubeH;
};

std::string	set_coord(int, int);
std::string	get_coord(Entity, std::unordered_map<std::string, Entity> &);

#endif /* !BOMBERMAN_HPP_ */
