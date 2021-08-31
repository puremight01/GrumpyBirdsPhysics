#include "Textures.h"

Textures* Textures::SingleTexture = nullptr;

Textures::Textures()
{
    // loads the sphere solid wood texture
    m_solidWoodSphere[0] = new sf::Texture;
    if (m_solidWoodSphere[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(88, 418, 75, 74)))
    {
        std::cout << "Failed to load m_solidWoodSphere[0]" << std::endl;
    }
    m_solidWoodSphere[0]->setSmooth(true);
    // loads the sphere solid wood texture - slight damage
    m_solidWoodSphere[1] = new sf::Texture;
    if (m_solidWoodSphere[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(336, 84, 75, 74)))
    {
        std::cout << "Failed to load m_solidWoodSphere[1]" << std::endl;
    }
    m_solidWoodSphere[1]->setSmooth(true);
    // loads the sphere solid wood texture - half damage
    m_solidWoodSphere[2] = new sf::Texture;
    if (m_solidWoodSphere[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(408, 84, 75, 74)))
    {
        std::cout << "Failed to load m_solidWoodSphere[2]" << std::endl;
    }
    m_solidWoodSphere[2]->setSmooth(true);
    // loads the sphere solid wood texture - very damaged
    m_solidWoodSphere[3] = new sf::Texture;
    if (m_solidWoodSphere[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(491, 84, 75, 74)))
    {
        std::cout << "Failed to load m_solidWoodSphere[3]" << std::endl;
    }
    m_solidWoodSphere[3]->setSmooth(true);


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


