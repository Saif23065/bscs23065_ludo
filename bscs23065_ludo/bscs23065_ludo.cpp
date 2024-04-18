#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
#include<vector>
#include "Dice.h"

// Mobeen entered into the repository


int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Ludo Game");
    sf::Vector2u windowSize = window.getSize();
    int windowWidth = windowSize.x;
    int windowLength = windowSize.y;

    vector<string> dices = {
        "assets/pics/diceOne.png", "assets/pics/diceTwo.png","assets/pics/diceThree.png",
        "assets/pics/diceFour.png", "assets/pics/diceFive.png","assets/pics/diceSix.png"
        /* ,"assets/pics/01.png","assets/pics/02.png","assets/pics/03.png","assets/pics/04.png","assets/pics/05.png"
        ,"assets/pics/06.png","assets/pics/07.png","assets/pics/08.png","assets/pics/09.png","assets/pics/10.png"
        ,"assets/pics/11.png","assets/pics/12.png","assets/pics/13.png","assets/pics/14.png","assets/pics/15.png"
        ,"assets/pics/16.png","assets/pics/17.png","assets/pics/18.png","assets/pics/19.png","assets/pics/20.png"
        ,"assets/pics/21.png","assets/pics/22.png","assets/pics/23.png","assets/pics/24.png","assets/pics/25.png"
        ,"assets/pics/26.png","assets/pics/27.png","assets/pics/28.png","assets/pics/29.png","assets/pics/30.png"*/
        //,"assets/pics/Cubelogo.png"
    };

    Dice dice(dices);
    dice.setposition(800, 300);

    dice.setScale(0.5f, 0.5f);
    sf::Texture ludoboard;
    if (!ludoboard.loadFromFile("assets/pics/WBoard.jpg")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite sprite;
    sprite.setTexture(ludoboard);

    sf::SoundBuffer click;
    if (!click.loadFromFile("assets/audio/click.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound clickSound;
    clickSound.setBuffer(click);

    sf::SoundBuffer diceroll;
    if (!diceroll.loadFromFile("assets/audio/dice.mp3")) {
        return EXIT_FAILURE;
    }
    sf::Sound rollSound;
    rollSound.setBuffer(diceroll);
    
    sf::Clock clock;
    float rollingDuration =0.5f;
    float rollTime = 0.0f;

    bool firstclick = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Check if the left mouse button was pressed
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the position of the click
                    sf::Vector2i clickPos = sf::Mouse::getPosition(window);
                    if (clickPos.x >= 17 * 46 && clickPos.x <= 20 * 46 && clickPos.y >= 6 * 46 && clickPos.y <= 9 * 46) {
                        int roll = dice.roll();
                        cout << "DICE ROLL : " << roll << endl;
                        dice.setRolling(true);
                        rollSound.play();
                    }
                    else {
                        clickSound.play();
                    }

                    // Print the position to the console
                    std::cout << "Mouse Click Position: x = " << clickPos.x / 46 << ", y = " << clickPos.y / 46 << std::endl;
                }
            }
        
        }
        float newt = clock.restart().asSeconds();
        if (dice.isrolling()) {
            rollTime += newt;
            if (rollTime >= rollingDuration) {
                dice.setRolling(false);
                rollTime = 0.0f;
             //   dice.setframe(rand() % 30);
                int randomFrameIndex = rand() % dices.size();
                dice.setframe(randomFrameIndex);
            }
        }
        dice.update(newt);

        window.clear();
        window.draw(sprite);
        window.draw(dice.getSprite());
        window.display();
    }

    return 0;
}
