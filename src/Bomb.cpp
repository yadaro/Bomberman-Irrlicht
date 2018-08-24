//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// bomb for bomberman
//

#include "Bomb.hpp"

Bomb::Bomb() : _InGame(false), _range(3),
	       _timer(10), _x(-1), _y(-1)
{
}

bool	Bomb::IsInGame() const
{
	return _InGame;
}

int	Bomb::getTimer() const
{
	return _timer;
}

int	Bomb::decTimer()
{
	_timer = _timer - 1;
}
