/*
** EPITECH PROJECT, 2018
** indie_studio
** File description:
** lib.hpp
*/

#ifndef LIBIRRLICHT_HPP_
	#define LIBIRRLICHT_HPP_

#include "IGraphic.hpp"
#include <irrlicht/irrlicht.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "SuperEntity.hpp"
#include <SFML/Audio.hpp>

class libIrrlicht : public irr::IEventReceiver, public IGraphic
{
    public:
    struct SMouseState
    {
        irr::core::position2di Position;
        bool LeftButtonDown;
        SMouseState() : 
        LeftButtonDown(false)
        { }        
    } MouseState;
    libIrrlicht();
    ~libIrrlicht();
    virtual bool OnEvent(const irr::SEvent &event);
    bool createWindow(tools::v2<int> const &dim, std::string const &name) override;
    bool destroyWindow() override;
    bool isKeyPressed(std::string const &name) const override;
    bool setCamera(tools::v3<float> const &pos, tools::v3<float> const &lookat) override;
    bool setLight(tools::v3<int> const &pos, tools::v3<int> const &color, int radius) override;
    bool draw_all(std::vector<SuperEntity *> disp) override;
    bool draw_Triangle(SuperEntity *dispTriangle);
    bool draw_Sphere(SuperEntity *dispSphere);
    bool draw_Rect(SuperEntity *dispRect);
    bool draw_3dM(SuperEntity *disp3d);
    bool createtxt(SuperEntity *dispTxt);
    bool isRun();
    bool playMusic(std::string const &path) override;
    bool deleteAll() override;
    bool isMouseClicked() override;
    bool moveEntity(SuperEntity *disp3d) override;
    tools::v2<int> getPosMouse() const override;
    bool displayAll() override;

    private:
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver *driver;
    irr::gui::IGUIEnvironment *guienv;
    irr::scene::ISceneManager *smgr;
    std::string FontPath;
    std::unordered_map<std::string, irr::EKEY_CODE> _keys;
    bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
    sf::Music _music;
    std::vector<SuperEntity *> _save;
    bool fend;
    std::unordered_map<std::string, std::pair<int, int> >_frameData;
    std::unordered_map<std::string, irr::scene::IAnimatedMeshSceneNode *> _nodeModels;
};
#endif /* !LIBIRRLICHT_HPP_ */
