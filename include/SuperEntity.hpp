//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// SuperEntity
//

#ifndef SUPER_ENTITY_HPP_
# define SUPER_ENTITY_HPP_

#include <string>
#include "tools.hpp"

class	SuperEntity {
public:
	enum TYPE {
		RECT,
		SPHERE,
		TRIANGLE,
		MODEL3D,
		TXT,
	};
	virtual SuperEntity::TYPE getType() const = 0;
	virtual ~SuperEntity() = default;
private:
//ta class pour les cord..
};

namespace Entitys {

	class Model3D : public SuperEntity {
	public:
		Model3D(const std::string &path, const tools::Info<float> &info, std::string textPath)
		: _modelPath(path),
		_info(info),
		_type(SuperEntity::MODEL3D),
		_texPath(textPath)
		{}
		~Model3D() {}
		SuperEntity::TYPE getType() const override { return _type; }
		std::string _modelPath;
		tools::Info<float> _info;
		SuperEntity::TYPE _type;
		std::string _texPath;																																																																																																																																																																																																																																																																								
	};																																																																																																																																																																																																																		
	class Txt : public SuperEntity {
	public:
		Txt(const std::string &txt)
		: _type(SuperEntity::TXT),
		_txt(txt)
		{}
		void setInfo(tools::v2<float> posL, tools::v2<float> posR)
		{
			_posL = posL;
			_posR = posR;
		}
		SuperEntity::TYPE getType() const override { return _type; }
		std::string _txt;
		SuperEntity::TYPE _type;
		tools::v2<float> _posL;
		tools::v2<float> _posR;
	};
	class Rect : public SuperEntity {
	public:
		Rect(const std::string &path, const tools::Info<float> &info)
		: _texturePath(path),
		_info(info),
		_type(SuperEntity::RECT)
		{}
		Rect(const std::string &path)
		    : _texturePath(path),
		      _type(RECT)
		{}
		~Rect()
		{}
		SuperEntity::TYPE getType() const override { return _type; }
		void setInfo(const tools::Info<float> &info) { _info = info; }
		std::string _texturePath;
		SuperEntity::TYPE _type;
		tools::Info<float> _info;
	private:
		//ta classe pour les dim et la rotation
	};
	
	class Sphere : public SuperEntity {
	public:
	std::string TexturePath;
	};
	
	class Triangle : public SuperEntity {
	public:
	std::string TexturePath;
	};

};
#endif /* !SUPER_ENTITY_HPP_ */
