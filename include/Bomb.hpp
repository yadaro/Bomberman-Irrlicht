//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// bomb header file
//

#ifndef BOMB_HPP_
# define BOMB_HPP_

class		Bomb {
public:
	Bomb();
	bool	IsInGame() const;
	int	getTimer() const;
	void	decTimer();
private:
	bool	_InGame;
	int	_range;
	int	_timer;
	int	_x;
	int	_y;
};

#endif /* !BOMB_HPP_ */
