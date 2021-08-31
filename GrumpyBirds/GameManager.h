#ifndef __GameManager__
#define __GameManager__

//includes needed in this class
#include"Scene.h"
#include"ExampleScene.h"

//This is the game instance 
//created by Jacob Sullivan
class GameManager
{
public:
    //creates an empty game instance
    //created by Jacob Sullivan
    GameManager();
    
    //shuts down the game instance
    //created by Jacob Sullivan
    ~GameManager();

    //updates the scene
    //created by Jacob Sullivan
    void Update();

    //renders the scene
    //created by Jacob Sullivan
    void Render(sf::RenderWindow *window);

    //changes the scene
    //created by Jacob Sullivan
    void SetScene(Scene* NewScene);

    //// returns pointer to current scene
    //// created by Naomi Wiggins
    //Scene* GetScene();

private:
    //holds the current scene
    //created by Jacob Sullivan
    Scene* CurrentScene;

};
#endif // !__GameManager__
