#include "../include/libirrlicht.hpp"
#include "../include/SuperEntity.hpp"

// bool    libIrrlicht::draw_3dM(SuperEntity *disp3d)
// {
//     irr::scene::IAnimatedMeshSceneNode* Model_mesh;

//     Entitys::Model3D *info = static_cast<Entitys::Model3D *> (disp3d);
//     irr::scene::IAnimatedMesh  *mesh = smgr->getMesh(info->_modelPath.c_str());
//     if (mesh) {
//     Model_mesh = smgr->addAnimatedMeshSceneNode(mesh); 
//     Model_mesh->setFrameLoop(0, 0);
//     Model_mesh->setLoopMode(false);
//     Model_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
//     }
//     if (Model_mesh && info->_texPath.c_str())
//     {
//         Model_mesh->setMaterialTexture(
//     0, driver->getTexture(info->_texPath.c_str()));
//     }
//     Model_mesh->setPosition(irr::core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
//     Model_mesh->setRotation(irr::core::vector3df(info->_info._deg.x, info->_info._deg.y, info->_info._deg.z));
//     _nodeModels[info->_modelPath] = Model_mesh;
// }

// bool        libIrrlicht::draw_Rect(SuperEntity *dispRect)
// {
//     Entitys::Rect *info = static_cast<Entitys::Rect *> (dispRect);
//     irr::scene::ISceneNode* cube = smgr->addCubeSceneNode();
//     if (cube) {
//     cube->setMaterialTexture(0, driver->getTexture(info->_texturePath.c_str()));
//     cube->setMaterialFlag(irr::video::EMF_LIGHTING, false); 
//     cube->setPosition(irr::core::vector3df(0.0f, 0.0f, 0.0f));
//     cube->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
//    // cube->setPosition(irr::core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
//   //  cube->setRotation(irr::core::vector3df(info->_info._deg.x, info->_info._deg.y, info->_info._deg.z));
//     return (true);
//     }
//     else
//     return (false);
// }

// bool        libIrrlicht::draw_Sphere(SuperEntity *dispSphere)
// {
//     Entitys::Sphere *info = static_cast<Entitys::Sphere *> (dispSphere);
//     scene::ISceneNode* sphere = smgr->addSphereSceneNode();
//     if (sphere) {
//         node->setPosition(core::vector3df(info->_info._pos.x, info->_info._pos.y, info->_info._pos.z));
//         node->setMaterialTexture(0, driver->getTexture(info->TexturePath.c_str()));
//         node->setMaterialFlag(video::EMF_LIGHTING, false);
//     }

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


bool        libIrrlicht::draw_all(std::vector<SuperEntity *> disp)
{
    // bool (* draw_func[4])(SuperEntity *);

    // draw_func[0] = this->draw_Rect;
    // draw_func[1] = this->draw_Sphere;
    // draw_func[2] = this->draw_Triangle;
    // draw_func[3] = this->draw_3dM;
     
    for (int i = 0 ; i < disp.size() ;i++)
    {
        if (disp[i]->getType() == 0)
        draw_Rect(disp[i]);
        if (disp[i]->getType() == 3)
        draw_3dM(disp[i]);
    }
    if (!device->run())
        return false;
    else
        return true;
}