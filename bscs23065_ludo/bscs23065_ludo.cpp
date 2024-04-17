#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;


// Mobeen entered into the repository


int main() {
    sf::RenderWindow window(sf::VideoMode(750, 750), "Ludo Game");
    sf::Vector2u windowSize = window.getSize();
    int windowWidth = windowSize.x;
    int windowLength = windowSize.y;

    sf::Texture ludoboard;
    if (!ludoboard.loadFromFile("assets/pics/board.jpg")) {
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

                    // Print the position to the console
                    std::cout << "Mouse Click Position: x = " << clickPos.x/50 << ", y = " << clickPos.y/50 << std::endl;
                    clickSound.play();
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
