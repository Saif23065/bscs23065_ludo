


// 
// 
// #pragma once
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include "Square.h"
//
//class Board {
//private:
//    std::vector<std::vector<Square>> squares; // 2D Vector to store squares
//    const int boardSize = 15; // Board size typically 15x15 for a Ludo board
//    const int squareSize = 40; // Visual size of each square
//
//public:
//    Board() {
//        squares.resize(boardSize, std::vector<Square>(boardSize));
//    }
//
//    void initializeSquares() {
//        // Initialize all squares
//        for (int i = 0; i < boardSize; ++i) {
//            for (int j = 0; j < boardSize; ++j) {
//                sf::Vector2f position(static_cast<float>(j * squareSize), static_cast<float>(i * squareSize));
//                squares[i][j] = Square(position, SquareColor::White, SquareType::Normal);
//            }
//        }
//
//        // Define the colored paths for each player
//        setupPlayerPath(0, 0, SquareColor::Green); // Green path
//        setupPlayerPath(0, 9, SquareColor::Yellow); // Yellow path
//        setupPlayerPath(9, 0, SquareColor::Red); // Red path
//        setupPlayerPath(9, 9, SquareColor::Blue); // Blue path
//
//        // Set start zones for each player
//        setupStartZone(1, 1, SquareColor::Green);
//        setupStartZone(1, 10, SquareColor::Yellow);
//        setupStartZone(10, 1, SquareColor::Red);
//        setupStartZone(10, 10, SquareColor::Blue);
//
//        // Set home zones for each player
//        setupHomeZone(5, 5, SquareColor::Green);
//        setupHomeZone(5, 9, SquareColor::Yellow);
//        setupHomeZone(9, 5, SquareColor::Red);
//        setupHomeZone(9, 9, SquareColor::Blue);
//    }
//
//    void setupPlayerPath(int startRow, int startCol, SquareColor color) {
//        sf::Color pathColor;
//        switch (color) {
//        case SquareColor::Green:
//            pathColor = sf::Color::Green;
//            break;
//        case SquareColor::Yellow:
//            pathColor = sf::Color::Yellow;
//            break;
//        case SquareColor::Red:
//            pathColor = sf::Color::Red;
//            break;
//        case SquareColor::Blue:
//            pathColor = sf::Color::Blue;
//            break;
//        default:
//            pathColor = sf::Color::White;
//        }
//
//        for (int i = 0; i < 6; ++i) { // Each arm of the cross has 6 rows
//            for (int j = 0; j < 8; ++j) { // Each arm of the cross has 8 columns
//                squares[startRow + i][startCol + j] = Square(sf::Vector2f(static_cast<float>((startCol + j) * squareSize), static_cast<float>((startRow + i) * squareSize)), pathColor, SquareType::Normal);
//                squares[startRow + j][startCol + i] = Square(sf::Vector2f(static_cast<float>((startCol + i) * squareSize), static_cast<float>((startRow + j) * squareSize)), pathColor, SquareType::Normal);
//            }
//        }
//    }
//
//    void setupStartZone(int startRow, int startCol, SquareColor color) {
//        sf::Color startColor;
//        switch (color) {
//        case SquareColor::Green:
//            startColor = sf::Color::Green;
//            break;
//        case SquareColor::Yellow:
//            startColor = sf::Color::Yellow;
//            break;
//        case SquareColor::Red:
//            startColor = sf::Color::Red;
//            break;
//        case SquareColor::Blue:
//            startColor = sf::Color::Blue;
//            break;
//        default:
//            startColor = sf::Color::White;
//        }
//
//        for (int i = 0; i < 3; ++i) { // Start zones are 3x3 squares
//            for (int j = 0; j < 3; ++j) {
//                squares[startRow + i][startCol + j] = Square(sf::Vector2f(static_cast<float>((startCol + j) * squareSize), static_cast<float>((startRow + i) * squareSize)), startColor, SquareType::Start);
//            }
//        }
//    }
//
//    void setupHomeZone(int startRow, int startCol, SquareColor color) {
//        sf::Color homeColor;
//        switch (color) {
//        case SquareColor::Green:
//            homeColor = sf::Color::Green;
//            break;
//        case SquareColor::Yellow:
//            homeColor = sf::Color::Yellow;
//            break;
//        case SquareColor::Red:
//            homeColor = sf::Color::Red;
//            break;
//        case SquareColor::Blue:
//            homeColor = sf::Color::Blue;
//            break;
//        default:
//            homeColor = sf::Color::White;
//        }
//
//        for (int i = 0; i < 5; ++i) { // Home zones are 5x5 squares
//            for (int j = 0; j < 5; ++j) {
//                squares[startRow + i][startCol + j] = Square(sf::Vector2f(static_cast<float>((startCol + j) * squareSize), static_cast<float>((startRow + i) * squareSize)), homeColor, SquareType::Home);
//            }
//        }
//    }
//
//    void draw(sf::RenderWindow& window) {
//        for (auto& row : squares) {
//            for (auto& square : row) {
//                square.draw(window);
//            }
//        }
//    }
//
//    // Function to get the square at a given position
//    Square& getSquareAt(sf::Vector2f position) {
//        int row = position.y / squareSize;
//        int col = position.x / squareSize;
//        return squares[row][col];
//    }
//
//    const Square& getSquareAt(sf::Vector2f position) const {
//        int row = position.y / squareSize;
//        int col = position.x / squareSize;
//        return squares[row][col];
//    }
//
//    // Function to check if a square is occupied by a piece of a given color
//    bool isSquareOccupiedByColor(sf::Vector2f position, SquareColor color) const {
//        const Square& square = getSquareAt(position);
//        return square.isOccupied() && square.getPieceColor() == color;
//    }
//
//    // Function to check if a square is a special square (Safe, Start, or Home)
//    bool isSpecialSquare(sf::Vector2f position) const {
//        const Square& square = getSquareAt(position);
//        return square.isSpecialSquare();
//    }
//
//    // Function to check if a square is the player's home
//    bool isHome(sf::Vector2f position, SquareColor color) const {
//        const Square& square = getSquareAt(position);
//        return square.isHome(color);
//    }
//
//    // Function to check if a square is the start square for the player
//    bool isStart(sf::Vector2f position, SquareColor color) const {
//        const Square& square = getSquareAt(position);
//        return square.isStart(color);
//    }
//
//    // Function to check if a square is a safe square
//    bool isSafe(sf::Vector2f position) const {
//        const Square& square = getSquareAt(position);
//        return square.isSafe();
//    }
//
//    // Function to add a piece to a square
//    void addPieceToSquare(sf::Vector2f position, SquareColor color) {
//        Square& square = getSquareAt(position);
//        square.addPiece(color);
//    }
//
//    // Function to remove a piece from a square
//    void removePieceFromSquare(sf::Vector2f position) {
//        Square& square = getSquareAt(position);
//        square.capturePiece();
//    }
//};
