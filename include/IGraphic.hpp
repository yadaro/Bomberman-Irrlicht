/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** igraphic
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <vector>
#include <iostream>
#include "tools.hpp"
#include "SuperEntity.hpp"

class IGraphic
{
public:
	virtual ~IGraphic() = default;
	virtual bool createWindow(tools::v2<int> const &dim, std::string const &name) = 0;
	virtual bool isKeyPressed(std::string const &name) const = 0;
	// EVENT_TYPE onEvent();
	virtual bool displayAll() = 0;
	// bool drawShape(SHAPE const &shape, std::string const &path, tools::Info info);
	// bool draw3D(std::string const &path, tools::Info info);
	virtual bool destroyWindow() = 0;
	virtual bool draw_all(std::vector<SuperEntity *> disp) = 0;
	virtual bool playMusic(std::string const &path) = 0;
	// bool playVideo(std::string const &path);
	virtual bool deleteAll() = 0;
	virtual bool createtxt(SuperEntity *dispTxt) = 0;
	virtual bool isRun() = 0;
	virtual bool setCamera(tools::v3<float> const &pos, tools::v3<float> const &lookat) = 0;
	virtual bool setLight(tools::v3<int> const &pos, tools::v3<int> const &color, int radius) = 0;
	virtual bool isMouseClicked() = 0;
	virtual tools::v2<int> getPosMouse() const = 0;
	virtual bool moveEntity(SuperEntity *disp3d) = 0;
};

#endif /* !IGRAPHIC_HPP_ */
