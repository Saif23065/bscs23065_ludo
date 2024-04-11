#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    // Create a window with SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "test the sfml window");

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw something
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(350.f, 250.f);
        window.draw(shape);

        // Display what was drawn
        window.display();
    }

    return 0;
}
