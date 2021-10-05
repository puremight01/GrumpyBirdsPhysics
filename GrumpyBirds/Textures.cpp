#include "Textures.h"

Textures* Textures::SingleTexture = nullptr;

Textures::Textures()
{
    // loads texture - no damage
    m_woodCube[0] = new sf::Texture;
    if (!m_woodCube[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 177, 80, 82)))
    {
        std::cout << "Failed to load m_woodCube[0]" << std::endl;
    }
    m_woodCube[0]->setSmooth(true);
    // loads texture - slight damage
    m_woodCube[1] = new sf::Texture;
    if (!m_woodCube[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 263, 80, 82)))
    {
        std::cout << "Failed to load m_woodCube[1]" << std::endl;
    }
    m_woodCube[1]->setSmooth(true);
    // loads texture - half damage
    m_woodCube[2] = new sf::Texture;
    if (!m_woodCube[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 89, 80, 82)))
    {
        std::cout << "Failed to load m_woodCube[2]" << std::endl;
    }
    m_woodCube[2]->setSmooth(true);
    // loads texture - very damaged
    m_woodCube[3] = new sf::Texture;
    if (!m_woodCube[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(4, 3, 80, 82)))
    {
        std::cout << "Failed to load m_woodCube[3]" << std::endl;
    }
    m_woodCube[3]->setSmooth(true);

    // loads the sphere solid wood texture
    m_woodSphere[0] = new sf::Texture;
    if (!m_woodSphere[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(88, 417, 76, 76)))
    {
        std::cout << "Failed to load m_woodSphere[0]" << std::endl;
    }
    m_woodSphere[0]->setSmooth(true);
    // loads the sphere solid wood texture - slight damage
    m_woodSphere[1] = new sf::Texture;
    if (!m_woodSphere[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(336, 85, 76, 75)))
    {
        std::cout << "Failed to load m_woodSphere[1]" << std::endl;
    }
    m_woodSphere[1]->setSmooth(true);
    // loads the sphere solid wood texture - half damage
    m_woodSphere[2] = new sf::Texture;
    if (!m_woodSphere[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(413, 85, 76, 75)))
    {
        std::cout << "Failed to load m_woodSphere[2]" << std::endl;
    }
    m_woodSphere[2]->setSmooth(true);
    // loads the sphere solid wood texture - very damaged
    m_woodSphere[3] = new sf::Texture;
    if (!m_woodSphere[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(490, 85, 76, 75)))
    {
        std::cout << "Failed to load m_woodSphere[3]" << std::endl;
    }
    m_woodSphere[3]->setSmooth(true);

    // loads texture - no damage
    m_woodTriangle[0] = new sf::Texture;
    if (!m_woodTriangle[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(339, 1, 84, 83)))
    {
        std::cout << "Failed to load m_woodTriangle[0]" << std::endl;
    }
    m_woodTriangle[0]->setSmooth(true);
    // loads texture - slight damage
    m_woodTriangle[1] = new sf::Texture;
    if (!m_woodTriangle[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(423, 1, 84, 83)))
    {
        std::cout << "Failed to load m_woodTriangle[1]" << std::endl;
    }
    m_woodTriangle[1]->setSmooth(true);
    // loads texture - half damage
    m_woodTriangle[2] = new sf::Texture;
    if (!m_woodTriangle[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(87, 85, 84, 83)))
    {
        std::cout << "Failed to load m_woodTriangle[2]" << std::endl;
    }
    m_woodTriangle[2]->setSmooth(true);
    // loads texture - very damaged
    m_woodTriangle[3] = new sf::Texture;
    if (!m_woodTriangle[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_WOOD_1.png", sf::IntRect(87, 169, 84, 83)))
    {
        std::cout << "Failed to load m_woodTriangle[3]" << std::endl;
    }
    m_woodTriangle[3]->setSmooth(true);

    // loads texture - no damage
    m_glassCube[0] = new sf::Texture;
    if (!m_glassCube[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(4, 263, 80, 82)))
    {
        std::cout << "Failed to load m_glassCube[0]" << std::endl;
    }
    m_glassCube[0]->setSmooth(true);
    // loads texture - slight damage
    m_glassCube[1] = new sf::Texture;
    if (!m_glassCube[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(4, 177, 80, 82)))
    {
        std::cout << "Failed to load m_glassCube[1]" << std::endl;
    }
    m_glassCube[1]->setSmooth(true);
    // loads texture - half damage
    m_glassCube[2] = new sf::Texture;
    if (!m_glassCube[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(4, 89, 80, 82)))
    {
        std::cout << "Failed to load m_glassCube[2]" << std::endl;
    }
    m_glassCube[2]->setSmooth(true);
    // loads texture - very damaged
    m_glassCube[3] = new sf::Texture;
    if (!m_glassCube[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(4, 3, 80, 82)))
    {
        std::cout << "Failed to load m_glassCube[3]" << std::endl;
    }
    m_glassCube[3]->setSmooth(true);

    // loads texture - no damage
    m_glassSphere[0] = new sf::Texture;
    if (!m_glassSphere[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(410, 86, 75, 73)))
    {
        std::cout << "Failed to load m_glassSphere[0]" << std::endl;
    }
    m_glassSphere[0]->setSmooth(true);
    // loads texture - slight damage
    m_glassSphere[1] = new sf::Texture;
    if (!m_glassSphere[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(487, 86, 73, 73)))
    {
        std::cout << "Failed to load m_glassSphere[1]" << std::endl;
    }
    m_glassSphere[1]->setSmooth(true);
    // loads texture - half damage
    m_glassSphere[2] = new sf::Texture;
    if (!m_glassSphere[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(89, 419, 73, 73)))
    {
        std::cout << "Failed to load m_glassSphere[2]" << std::endl;
    }
    m_glassSphere[2]->setSmooth(true);
    // loads texture - very damaged
    m_glassSphere[3] = new sf::Texture;
    if (!m_glassSphere[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(337, 85, 73, 73)))
    {
        std::cout << "Failed to load m_glassSphere[3]" << std::endl;
    }
    m_glassSphere[3]->setSmooth(true);

    // loads texture - no damage
    m_glassTriangle[0] = new sf::Texture;
    if (!m_glassTriangle[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(423, 1, 84, 82)))
    {
        std::cout << "Failed to load m_glassTriangle[0]" << std::endl;
    }
    m_glassTriangle[0]->setSmooth(true);
    // loads texture - slight damage
    m_glassTriangle[1] = new sf::Texture;
    if (!m_glassTriangle[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(340, 1, 80, 82)))
    {
        std::cout << "Failed to load m_glassTriangle[1]" << std::endl;
    }
    m_glassTriangle[1]->setSmooth(true);
    // loads texture - half damage
    m_glassTriangle[2] = new sf::Texture; 
    if (!m_glassTriangle[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(88, 169, 82, 82)))
    {
        std::cout << "Failed to load m_glassTriangle[2]" << std::endl;
    }
    m_glassTriangle[2]->setSmooth(true);
    // loads texture - very damaged
    m_glassTriangle[3] = new sf::Texture;
    if (!m_glassTriangle[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_GLASS_1.png", sf::IntRect(88, 85, 82, 82)))
    {
        std::cout << "Failed to load m_glassTriangle[3]" << std::endl;
    }
    m_glassTriangle[3]->setSmooth(true);

    // loads texture - no damage
    m_stoneCube[0] = new sf::Texture;
    if (!m_stoneCube[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(264, 2, 80, 80)))
    {
        std::cout << "Failed to load m_stoneCube[0]" << std::endl;
    }
    m_stoneCube[0]->setSmooth(true);
    // loads texture - slight damage
    m_stoneCube[1] = new sf::Texture;
    if (!m_stoneCube[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(177, 3, 81, 81)))
    {
        std::cout << "Failed to load m_stoneCube[1]" << std::endl;
    }
    m_stoneCube[1]->setSmooth(true);
    // loads texture - half damage
    m_stoneCube[2] = new sf::Texture;
    if (!m_stoneCube[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(90, 2, 81, 81)))
    {
        std::cout << "Failed to load m_stoneCube[2]" << std::endl;
    }
    m_stoneCube[2]->setSmooth(true);
    // loads texture - very damaged
    m_stoneCube[3] = new sf::Texture;
    if (!m_stoneCube[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(3, 3, 80, 80)))
    {
        std::cout << "Failed to load m_stoneCube[3]" << std::endl;
    }
    m_stoneCube[3]->setSmooth(true);

    // loads texture - no damage
    m_stoneSphere[0] = new sf::Texture;
    if (!m_stoneSphere[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(86, 172, 74, 73)))
    {
        std::cout << "Failed to load m_stoneSphere[0]" << std::endl;
    }
    m_stoneSphere[0]->setSmooth(true);
    // loads texture - slight damage
    m_stoneSphere[1] = new sf::Texture;
    if (!m_stoneSphere[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(87, 247, 74, 73)))
    {
        std::cout << "Failed to load m_stoneSphere[1]" << std::endl;
    }
    m_stoneSphere[1]->setSmooth(true);
    // loads texture - half damage
    m_stoneSphere[2] = new sf::Texture;
    if (!m_stoneSphere[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(86, 322, 74, 73)))
    {
        std::cout << "Failed to load m_stoneSphere[2]" << std::endl;
    }
    m_stoneSphere[2]->setSmooth(true);
    // loads texture - very damaged
    m_stoneSphere[3] = new sf::Texture;
    if (!m_stoneSphere[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(86, 397, 74, 74)))
    {
        std::cout << "Failed to load m_stoneSphere[3]" << std::endl;
    }
    m_stoneSphere[3]->setSmooth(true);

    // loads texture - no damage
    m_stoneTriangle[0] = new sf::Texture;
    if (!m_stoneTriangle[0]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(1, 256, 83, 82)))
    {
        std::cout << "Failed to load m_stoneTriangle[0]" << std::endl;
    }
    m_stoneTriangle[0]->setSmooth(true);
    // loads texture - slight damage
    m_stoneTriangle[1] = new sf::Texture;
    if (!m_stoneTriangle[1]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(1, 340, 82, 82)))
    {
        std::cout << "Failed to load m_stoneTriangle[1]" << std::endl;
    }
    m_stoneTriangle[1]->setSmooth(true);
    // loads texture - half damage
    m_stoneTriangle[2] = new sf::Texture;
    if (!m_stoneTriangle[2]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(1, 424, 82, 82)))
    {
        std::cout << "Failed to load m_stoneTriangle[2]" << std::endl;
    }
    m_stoneTriangle[2]->setSmooth(true);
    // loads texture - very damaged
    m_stoneTriangle[3] = new sf::Texture;
    if (!m_stoneTriangle[3]->loadFromFile("Resources/MapSprites/ANGRY_BIRDS_RIO_INGAME_BLOCKS_STONE_1.png", sf::IntRect(85, 88, 82, 82)))
    {
        std::cout << "Failed to load m_stoneTriangle[3]" << std::endl;
    }
    m_stoneTriangle[3]->setSmooth(true);


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

    // loads texture - no damage
    m_pig[0] = new sf::Texture;
    if (!m_pig[0]->loadFromFile("Resources/BirdSprites/INGAME_BIRDS_1.png", sf::IntRect(355, 341, 86, 86)))
    {
        std::cout << "Failed to load m_pig[0]" << std::endl;
    }
    m_pig[0]->setSmooth(true);
    // loads texture - slight damage
    m_pig[1] = new sf::Texture;
    if (!m_pig[1]->loadFromFile("Resources/BirdSprites/INGAME_BIRDS_1.png", sf::IntRect(441, 340, 86, 86)))
    {
        std::cout << "Failed to load m_pig[1]" << std::endl;
    }
    m_pig[1]->setSmooth(true);
    // loads texture - half damage
    m_pig[2] = new sf::Texture;
    if (!m_pig[2]->loadFromFile("Resources/BirdSprites/INGAME_BIRDS_1.png", sf::IntRect(526, 424, 86, 86)))
    {
        std::cout << "Failed to load m_pig[2]" << std::endl;
    }
    m_pig[2]->setSmooth(true);
    // loads texture - very damaged
    m_pig[3] = m_pig[2];

    
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


