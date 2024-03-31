#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "./headers/global.hpp"

int main (){
    sf::RenderWindow window(sf::VideoMode(500, 400), "Animation");

    // //=================== For pacman sprite =================
    sf::Texture texture;
    texture.loadFromFile("./spritesheets/red_ghost.png");

    sf::IntRect rectSourceSprite(0,0,24,24);  // width = 24 , height = 24  
    sf::Sprite sprite(texture,rectSourceSprite);
    sprite.setScale(5.0f,5.0f);
    sprite.setPosition(200.0f,150.0f);
    // // ======================================================

    // ============= For game swordsman character sprite =================
    // sf::Texture texture;
    // texture.loadFromFile("./spritesheets/game_character.png");

    // sf::IntRect rectSourceSprite(0,150,50,40);  // width = 50 , height = 40
    // sf::Sprite sprite(texture,rectSourceSprite);
    // sprite.setScale(5.0f,5.0f);
    // sprite.setPosition(125.0f,125.0f);
    // ======================================================

    sf::Event event;
    sf::Clock clock;

    // 264 - for pacman sprite
    // 450 - for the game swordsman character
    int last_frame_location{PACMAN_GAME_CHARACTER_LAST_FRAME_LOCATION};
    // 24 - for pacman sprite
    // 50 - for the game swordsman character
    int frame_width{PACMAN_GAME_CHARACTER_WIDTH};

    while (window.isOpen())
    {

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS);
            }
        }

        if(clock.getElapsedTime().asSeconds() > 0.1f)
        {
             if(rectSourceSprite.left == last_frame_location)
             {
                rectSourceSprite.left = 0 ;
             }
             else{
                rectSourceSprite.left += frame_width ;
             }

             sprite.setTextureRect(rectSourceSprite);
             clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}