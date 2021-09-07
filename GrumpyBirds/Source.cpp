//GameManager
#include"GameManager.h"


//this is the main thread of the game 
//created by Jacob Sullivan
int main()
{
    //creates a game instance
    GameManager Game;
    
    //window
    Globals::window = new sf::RenderWindow(sf::VideoMode(1600,900), "GrumpyBirds");
    sf::View MainCamera(sf::Vector2f(800.f, 450.f), sf::Vector2f(1600.f, 900.f));
    Globals::window->setView(MainCamera);
    Globals::window->setFramerateLimit(60);

    while (Globals::window->isOpen())
    {
        //clears the back buffer
        Globals::window->clear();

        sf::Event event;
        while (Globals::window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Globals::window->close();
        }
      
        //updates the game
        Game.Update();

        //renders the game to the window 
        Game.Render(Globals::window);

        //swaps the back buffer to the front buffer
        Globals::window->display();
    }

    return 0;
}