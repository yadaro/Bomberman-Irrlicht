//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <utility>
#include "../include/libirrlicht.hpp"
#include "../include/SuperEntity.hpp"

bool    libIrrlicht::draw_3dM(SuperEntity *disp3d)
{
    irr::scene::IAnimatedMeshSceneNode* Model_mesh;

    Entitys::Model3D *info = static_cast<Entitys::Model3D *> (disp3d);
    irr::scene::IAnimatedMesh  *mesh = smgr->getMesh(info->_modelPath.c_str());
    if (mesh) {
        std::cout << info->_modelPath.c_str() << std::endl;
    Model_mesh = smgr->addAnimatedMeshSceneNode(mesh);
    Model_mesh->setFrameLoop(0, 0);
    Model_mesh->setLoopMode(false);
    Model_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
    if (Model_mesh && info->_texPath.c_str())
    {
        Model_mesh->setMaterialTexture(
            0, driver->getTexture(info->_texPath.c_str()));
    }
    Model_mesh->setScale(irr::core::vector3df(info->_info._dim.x, info->_info._dim.y, info->_info._dim.z));
    Model_mesh->setPosition(irr::core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
    Model_mesh->setRotation(irr::core::vector3df(info->_info._deg.x, info->_info._deg.y, info->_info._deg.z));
    _nodeModels[info->_modelPath] = Model_mesh;
    return true;
}

bool	libIrrlicht::isRun()
{
	if (this->device->run())
		return true;
	else 
		return false;
}

bool        libIrrlicht::draw_Rect(SuperEntity *dispRect)
{
    Entitys::Rect *info = static_cast<Entitys::Rect *> (dispRect);
    irr::scene::ISceneNode* cube = smgr->addCubeSceneNode();
    if (cube) {
    // std::cout <<info->_texturePath.c_str() << std::endl;
    cube->setMaterialTexture(0, driver->getTexture(info->_texturePath.c_str()));
    cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    cube->setScale (irr::core::vector3df(info->_info._dim.x, info->_info._dim.y, info->_info._dim.z));
    cube->setPosition(irr::core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
    cube->setRotation(irr::core::vector3df(info->_info._deg.x, info->_info._deg.y, info->_info._deg.z));
    return (true);
    }
    else
    return (false);
}

// bool        libIrrlicht::draw_Sphere(SuperEntity *dispSphere)
// {
//     Entitys::Sphere *info = static_cast<Entitys::Sphere *> (dispSphere);
//     irr::scene::ISceneNode* sphere = smgr->addSphereSceneNode();
//     if (sphere) {
//         sphere->setPosition(irr::core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
//         sphere->setMaterialTexture(0, driver->getTexture(info->TexturePath.c_str()));
//         sphere->setMaterialFlag(irr::video::EMF_LIGHTING, false);
// }

// }

// bool        libIrrlicht::draw_Triangle(SuperEntity *dispTriangle)
// {
//      Entitys::Triangle *info = static_cast<Entitys::Triangle *> (dispRect);
//     scene::ISceneNode* Triangle = smgr->addP;
//     cube->setMaterialTexture(0, driver->getTexture(info->_texturePath.c_str()));
//     cube->setMaterialFlag(video::EMF_LIGHTING, false);
//     cube->setPosition(core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
//     cube->setRotation(core::vector3df(info->_info._deg.x, info->_info._deg.y, info->_info._deg.z));
// }



// bool        libIrrlicht::verifEntity(std::vector &compt);
// {
//     for (auto &it : save){
//         if (&it == &compt && compt->)
//         return false;
//     }
// }

// }

bool        libIrrlicht::draw_all(std::vector<SuperEntity *> disp)
{
    // bool (* draw_func[4])(SuperEntity *);

    // draw_func[0] = this->draw_Rect;
    // draw_func[1] = this->draw_Sphere;
    // draw_func[2] = this->draw_Triangle;
    // draw_func[3] = this->draw_3dM;
     for (unsigned int i = 0 ; i < disp.size() ;i++)
    {
        if (disp[i]->getType() == 0){
        draw_Rect(disp[i]);
        // std::cout<<"RECT"<<std::endl;
        }
        if (disp[i]->getType() == 3) {
        draw_3dM(disp[i]);
        // std::cout<<"3D"<<std::endl;
        }
        if (disp[i]->getType() == 4) {
        createtxt(disp[i]);    
        }
    }
    return true;
}

libIrrlicht::libIrrlicht()
{
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
        _keyIsDown[i] = false;
    _keys =
        {
            {"escape", irr::KEY_ESCAPE},
            {"z", irr::KEY_KEY_Z},
            {"s", irr::KEY_KEY_S},
            {"d", irr::KEY_KEY_D},
            {"q", irr::KEY_KEY_Q},
            {"u", irr::KEY_KEY_U},
            {"j", irr::KEY_KEY_J},
            {"i", irr::KEY_KEY_I},
            {"k", irr::KEY_KEY_K},
            {"o", irr::KEY_KEY_O},
            {"l", irr::KEY_KEY_L},
            {"m", irr::KEY_KEY_M},
            {"n", irr::KEY_KEY_N},
            {"p", irr::KEY_KEY_P},
            {"a", irr::KEY_KEY_A},
            {"c", irr::KEY_KEY_B},
            {"e", irr::KEY_KEY_E},
            {"f", irr::KEY_KEY_F},
            {"g", irr::KEY_KEY_G},
            {"h", irr::KEY_KEY_H},
            {"j", irr::KEY_KEY_J},
            {"r", irr::KEY_KEY_R},
            {"t", irr::KEY_KEY_T},
            {"u", irr::KEY_KEY_U},
            {"v", irr::KEY_KEY_V},
            {"w", irr::KEY_KEY_W},
            {"x", irr::KEY_KEY_X},
            {"y", irr::KEY_KEY_Y},
            {"backspace", irr::KEY_BACK},
            {"enter", irr::KEY_RETURN},
            {"space", irr::KEY_SPACE},
            {"left", irr::KEY_LEFT},
            {"right", irr::KEY_RIGHT},
            {"down", irr::KEY_DOWN},
            {"up", irr::KEY_UP}
        };
    
    // _frameData = { 
    //     {"./model/ninja.b3d", std::make_pair<0, 13>}

    // };

    _nodeModels = {

    };
    fend = false;
}

libIrrlicht::~libIrrlicht()
{}

bool libIrrlicht::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        {   
            _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
            return true;
        }

    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
    {
        switch(event.MouseInput.Event)
        {
            case irr::EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LeftButtonDown = true;
                break;

            case irr::EMIE_LMOUSE_LEFT_UP:
                MouseState.LeftButtonDown = false;
                break;

            case irr::EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;

            default:
                break;
        }
    }
    return false;
}

bool libIrrlicht::createWindow(tools::v2<int> const &dim, std::string const &name)
{
    std::wstring wname;
    for(unsigned int i = 0; i < name.length(); ++i)
        wname += wchar_t(name[i]);
    const wchar_t* title = wname.c_str();

    device = irr::createDevice(irr::video::EDT_OPENGL,
                               irr::core::dimension2d<irr::u32>(dim.x, dim.y), 16, false, false, false, this);
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    irr::gui::IGUISkin* skin = guienv->getSkin();
    irr::gui::IGUIFont* font = guienv->getFont("./media/myfont.png");
    skin->setFont(guienv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    if (font) {
        skin->setFont(font);
    }

    device->setWindowCaption(title);

    return true;
}

bool libIrrlicht::isKeyPressed(std::string const &name) const
{
    for (auto it : _keys)
    {
        if (name == it.first)
            return _keyIsDown[it.second];
    }
    return false;
}

bool libIrrlicht::displayAll()
{
     if (device->isWindowActive())
        {
            // std::cout << "refresh" << std::endl;
            driver->beginScene(true, true, irr::video::SColor(255, 113, 113, 133));
            smgr->drawAll();
	        guienv->drawAll();
            driver->endScene();
            return true;
        }
    return false;
}

bool libIrrlicht::createtxt(SuperEntity *dispTxt)
{    
	// std::cout<<"draw text" << std::endl;
    Entitys::Txt *info = static_cast<Entitys::Txt *> (dispTxt);
    std::wstring wTxt;

    for(unsigned int i = 0; i < info->_txt.length(); ++i)
        wTxt += wchar_t(info->_txt[i]);
           guienv->addStaticText(wTxt.c_str(),
         irr::core::rect<irr::s32>(info->_posL.x, info->_posL.y, info->_posR.x, info->_posR.y), true);
         
//     irr::scene::ITextSceneNode *nodeText = smgr->addTextSceneNode("./media/arcade.ttf", wTxt.c_str());
//     nodeText->setTextColor(irr::video::SColor(255, 100, 100, 0));
//     nodeText->setPosition(irr::core::vector3df(info->_dim.x, info->_dim.y, info->_dim.z));
//     nodeText->setScale(irr::core::vector3df(info->_pos.x, info->_pos.y, info->_pos.z)); 
    return true;
}

bool libIrrlicht::deleteAll()
{
	smgr->clear();
	guienv->clear();
    //driver->endScene();
    return true;
}

bool libIrrlicht::destroyWindow()
{
    if (device->drop())
        return true;
    return false;
}

bool libIrrlicht::setCamera(tools::v3<float> const &pos, tools::v3<float> const &lookat)
{
	// smgr->addCameraSceneNodeFPS();
    if (smgr->addCameraSceneNode(0, irr::core::vector3df(pos.x, pos.y , pos.z), 
        irr::core::vector3df(lookat.x, lookat.y, lookat.z), 16, true))
        return true;
    return false;
}

bool libIrrlicht::setLight(tools::v3<int> const &pos, tools::v3<int> const &color, int radius)
{
    if (smgr->addLightSceneNode(0, irr::core::vector3df(pos.x, pos.y, pos.z),
        irr::video::SColorf(color.x, color.y, color.z), radius))
        return true;
    return false;
}

bool libIrrlicht::playMusic(std::string const &path)
{
    if (!_music.openFromFile(path))
        return false;
    _music.play();
    return true;
}

bool libIrrlicht::isMouseClicked()
{
    if (MouseState.LeftButtonDown == true)
        return true;
    return false;
}

// bool libIrrlicht::moveEntity(scene::IAnimatedMeshSceneNode* enty)
bool libIrrlicht::moveEntity(SuperEntity *disp3d)
{
    Entitys::Model3D *info = static_cast<Entitys::Model3D *> (disp3d);

    // std::cout << fend << std::endl;

    // static int k = 0;

    if (_nodeModels.find(info->_modelPath) != _nodeModels.end())
    {
        if (info->_modelPath == _nodeModels.find(info->_modelPath)->first)
        {
            if (fend == false)
            {
                _nodeModels.find(info->_modelPath)->second->setFrameLoop(0, 13); // EN DUR

            // _nodeModels.find(info->_modelPath)->second->setFrameLoop(_frameData[_nodeModels.find(info->_modelPath)->first].first, _frameData[_nodeModels.find(info->_modelPath)->first].second) // A REMPLACER
                fend = true;
            }
            if (_nodeModels.find(info->_modelPath)->second->getFrameNr() == 13)
            {
                fend = false;
            }

            // std::cout << _nodeModels.find(info->_modelPath)->second->getFrameNr() << std::endl;
        }
         // EN DUR
        //if (_nodeModels.find(info->_modelPath)->second->getFrameNr() == _frameData[_nodeModels.find(info->_modelPath)->first].second) // A REMPLACER
        
    }

    return true;
}

tools::v2<int> libIrrlicht::getPosMouse() const
{
    tools::v2<int> pm;

    pm.x = MouseState.Position.X;
    pm.y = MouseState.Position.Y;

    return pm;
}


// int main()
// {
//     libIrrlicht receiver;

//     receiver.createWindow(tools::v2<int>(800, 600), "MY FCKING WINDOW");

//     scene::IAnimatedMeshSceneNode* anms =
//         receiver.smgr->addAnimatedMeshSceneNode(receiver.smgr->getMesh("./media/ninja.b3d"));
//     anms->setFrameLoop(0, 0);
//     anms->setLoopMode(false);
//     anms->setMaterialFlag(video::EMF_LIGHTING, false);
//     anms->setPosition(core::vector3df(0,0,60));

//     receiver.setCamera(tools::v3<float>(0, 0, 30), tools::v3<float>(0, 0, 60));

//     while(receiver.device->run())
//     {

//         if(receiver.isKeyPressed("z"))
//         {
//             receiver.moveEntity(anms);
//             anms->setRotation(core::vector3df(0,360,0));
//         }
//         else if (receiver.isKeyPressed("s"))
//         {
//             receiver.moveEntity(anms);
//             anms->setRotation(core::vector3df(0,180,0));
//         }
//         if (receiver.isKeyPressed("d"))
//         {
//           receiver.moveEntity(anms);
//           anms->setRotation(core::vector3df(0,90,0));
//         }

//         else if(receiver.isKeyPressed("q"))
//         {
//             receiver.moveEntity(anms);
//             anms->setRotation(core::vector3df(0,270,0));
//         }
//         receiver.displayAll();
//     }
//     receiver.device->drop();
    
//     return 0;
// }