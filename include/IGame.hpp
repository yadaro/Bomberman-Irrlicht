/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** Game Interface
*/

#ifndef IGAME_HPP_
# define IGAME_HPP_

class IGame {
	public:
		virtual int	InitMap() = 0;
		virtual int	InterpretInputs() = 0;
		virtual void	DestroyMap() = 0;
};

#endif /* !IGAME_HPP_ */
