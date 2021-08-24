#include "Textures.h"

Textures* Textures::SingleTexture = nullptr;

Textures::Textures()
{

    //loads the solid wood texture
    SolidWoodCube1 = new sf::Texture;
    if (!SolidWoodCube1->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 177, 80, 82)))
    {
        std::cout << "Failed to load SolidWoodCube1" << std::endl;
    }
    SolidWoodCube1->setSmooth(true);

    //loads the solid wood texture slight damaged
    SolidWoodCube2 = new sf::Texture;
    if (!SolidWoodCube2->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 263, 80, 82)))
    {
        std::cout << "Failed to load SolidWoodCube2" << std::endl;
    }
    SolidWoodCube2->setSmooth(true);

    //loads the solid wood texture damaged
    SolidWoodCube3 = new sf::Texture;
    if (!SolidWoodCube3->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 89, 80, 82)))
    {
        std::cout << "Failed to load SolidWoodCube3" << std::endl;
    }
    SolidWoodCube3->setSmooth(true);

    //loads the solid wood texture very damaged
    SolidWoodCube4 = new sf::Texture;
    if (!SolidWoodCube4->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 3, 80, 82)))
    {
        std::cout << "Failed to load SolidWoodCube4" << std::endl;
    }
    SolidWoodCube4->setSmooth(true);

    //loads the Red Bird Normal Texture
    RedGrumpyBird1 = new sf::Texture;
    if (!RedGrumpyBird1->loadFromFile("Resources/BirdSprites/ANGRY_BIRDS_RIO_INGAME_BIRDS_1.png", sf::IntRect(344, 606, 62, 60)))
    {
        std::cout << "Failed to load SolidWoodCube4" << std::endl;
    }
    RedGrumpyBird1->setSmooth(true);

    //loads the Slingshot Texture
    SlingShot = new sf::Texture;
    if (!SlingShot->loadFromFile("Resources/BirdSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_MISC_1.png", sf::IntRect(46, 3, 81,197)))
    {
        std::cout << "Failed to load SolidWoodCube4" << std::endl;
    }
    SlingShot->setSmooth(true);
}

Textures::~Textures()
{
}

Textures* Textures::GetTextures()
{
    if (SingleTexture == nullptr)
    {
        SingleTexture = new Textures();
    }

    return SingleTexture;
}


