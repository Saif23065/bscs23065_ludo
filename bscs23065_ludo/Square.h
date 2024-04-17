

//#pragma once
//#include <SFML/Graphics.hpp>
//
//enum class SquareType {
//    Normal,
//    Start,
//    Home,
//    Safe
//};
//
//enum class SquareColor {
//    Green,
//    Yellow,
//    Red,
//    Blue,
//    White,
//    None
//};
//
//class Square {
//private:
//    sf::RectangleShape shape;
//    SquareColor color;
//    SquareType type;
//    SquareColor pieceColor; // Added member variable for piece color
//    const int squareSize = 40; // Visual size of each square
//    sf::Vector2f position;
//    bool occupied;
//
//public:
//    Square() : position(0, 0), color(SquareColor::White), type(SquareType::Normal), occupied(false), pieceColor(SquareColor::None) {}
//
//    Square(sf::Vector2f position, SquareColor color, SquareType type)
//        : position(position), color(color), type(type), occupied(false), pieceColor(SquareColor::None) {}
//
//     // Assignment operator
//    Square& operator=(const Square& other) {
//        if (this != &other) {
//            this->position = other.position;
//            this->color = other.color;
//            this->type = other.type;
//            this->occupied = other.occupied;
//            this->pieceColor = other.pieceColor;
//        }
//        return *this;
//    }
//
//    // Getter and setter for position
//    sf::Vector2f getPosition() const {
//        return shape.getPosition();
//    }
//
//    void setPosition(float x, float y) {
//        shape.setPosition(x, y);
//    }
//
//    // Getter and setter for fill color
//    void setFillColor(const sf::Color& color) {
//        shape.setFillColor(color);
//    }
//
//    // Drawing function
//    void draw(sf::RenderWindow& window) const {
//        window.draw(shape);
//    }
//
//    // Function to check if a point is inside the square
//    bool isInside(sf::Vector2f point) const {
//        sf::FloatRect bounds = shape.getGlobalBounds();
//        return bounds.contains(point);
//    }
//
//    // Getter and setter for pieceColor
//    void setPieceColor(SquareColor color) {
//        pieceColor = color;
//    }
//
//    SquareColor getPieceColor() const {
//        return pieceColor;
//    }
//
//    // Function to check if the square is occupied by a piece
//    bool isOccupied() const {
//        return pieceColor != SquareColor::None;
//    }
//
//    // Function to remove a piece from the square
//    void capturePiece() {
//        pieceColor = SquareColor::None;
//    }
//
//    // Function to check if the square is a special square (Safe, Start, or Home)
//    bool isSpecialSquare() const {
//        return type == SquareType::Safe || type == SquareType::Start || type == SquareType::Home;
//    }
//
//    // Function to check if the square is the player's home
//    bool isHome(SquareColor color) const {
//        return type == SquareType::Home && pieceColor == color;
//    }
//
//    // Function to check if the square is the start square for the player
//    bool isStart(SquareColor color) const {
//        return type == SquareType::Start && pieceColor == SquareColor::None;
//    }
//
//    // Function to check if the square is a safe square
//    bool isSafe() const {
//        return type == SquareType::Safe;
//    }
//
//    // Function to add a piece to the square
//    void addPiece(SquareColor color) {
//        pieceColor = color;
//    }
//
//    // Function to check if the square contains a piece of the given color
//    bool containsPieceOfColor(SquareColor color) const {
//        return pieceColor == color;
//    }
//
//    // Getter and setter for type
//    SquareType getType() const {
//        return type;
//    }
//
//    void setType(SquareType newType) {
//        type = newType;
//    }
//
//    // Getter and setter for color
//    SquareColor getColor() const {
//        return color;
//    }
//
//    void setColor(SquareColor newColor) {
//        color = newColor;
//        switch (color) {
//        case SquareColor::Green:
//            shape.setFillColor(sf::Color::Green);
//            break;
//        case SquareColor::Yellow:
//            shape.setFillColor(sf::Color::Yellow);
//            break;
//        case SquareColor::Red:
//            shape.setFillColor(sf::Color::Red);
//            break;
//        case SquareColor::Blue:
//            shape.setFillColor(sf::Color::Blue);
//            break;
//        default:
//            shape.setFillColor(sf::Color::White);
//            break;
//        }
//    }
//};
