//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// move_player
//

#include "Bomberman.hpp"

typedef std::unordered_map<std::string, Entity>	t_map;
typedef bool	(*fnMovement)(t_map &map, Entity player);

bool	moveUp(t_map &map, Entity player)
{
	int	x = GET_X(get_coord(player, map));
	int	y = GET_Y(get_coord(player, map));

	if (map[COORD(x, y + 1)] == VOID) {
		map[COORD(x, y)] = VOID;
		map[COORD(x, y + 1)] = player;
		return false;
	}
	return true;
}

bool	moveDown(t_map &map, Entity player)
{
	int	x = GET_X(get_coord(player, map));
	int	y = GET_Y(get_coord(player, map));

	if (map[COORD(x, y - 1)] == VOID) {
		map[COORD(x, y)] = VOID;
		map[COORD(x, y - 1)] = player;		
		return false;
	}
	return true;
}

bool	moveRight(t_map &map, Entity player)
{
	int	x = GET_X(get_coord(player, map));
	int	y = GET_Y(get_coord(player, map));

	if (map[COORD(x + 1, y)] == VOID) {
		map[COORD(x, y)] = VOID;
		map[COORD(x + 1, y)] = player;
		return false;
	}
	return true;
}

bool	moveLeft(t_map &map, Entity player)
{
	int	x = GET_X(get_coord(player, map));
	int	y = GET_Y(get_coord(player, map));

	if (map[COORD(x - 1, y)] == VOID) {
		map[COORD(x, y)] = VOID;
		map[COORD(x - 1, y)] = player;
		return false;
	}
	return true;

}

bool	Bomberman::movePlayer(PlayerInput myInput, Entity player, t_map &map)
{	
	std::vector<fnMovement>		movements =
		{&moveUp, &moveDown, &moveLeft, &moveRight};
	std::vector<PlayerInput>	inputs =
		{UP, DOWN, LEFT, RIGHT};
	int				c = 0;

	bool vf = false;
	for (auto i : inputs) {
		if (i == myInput) {
			if (movements[c](map, player) == true)
			{
				vf = true;
			}
			else
			{
				vf = false;
			}
		}
		c++;
	}
	return vf;
}
