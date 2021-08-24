#ifndef __GameManager__
#define __GameManager__

//includes needed in this class
#include"Scene.h"
#include"ExampleScene.h"

class GameManager
{
public:
    //creates an empty game instance
    GameManager();
    
    //shuts down the game instance
    ~GameManager();

    //updates the scene
    void Update();

    //renders the scene
    void Render(sf::RenderWindow *window);

    //changes the scene
    void SetScene(Scene* NewScene);

private:
    //holds the current scene
    Scene* CurrentScene;

};
#endif // !__GameManager__
