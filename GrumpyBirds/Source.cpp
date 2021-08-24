//GameManager
#include"GameManager.h"

//this is the main thread of the game 
//created by Jacob Sullivan
int main()
{
    //creates a game instance
    GameManager Game;
    
    //window
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen on main display");
    sf::View MainCamera(sf::Vector2f(800.f, 450.f), sf::Vector2f(1600.f, 900.f));
    window.setView(MainCamera);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        //clears the back buffer
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      
        //updates the game
        Game.Update();

        //renders the game to the window 
        Game.Render(&window);

        //swaps the back buffer to the front buffer
        window.display();
    }

    return 0;
}