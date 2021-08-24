//GameManager
#include"GameManager.h"

int main()
{
    //creates a game instance
    GameManager Game;
    
    //window
    sf::RenderWindow window(sf::VideoMode(1600,900), "SFML and box2D works!");
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