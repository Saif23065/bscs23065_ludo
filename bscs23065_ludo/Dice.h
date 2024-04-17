#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
class Dice
{
private:
	vector<sf::Texture> dices;
	sf::Sprite diceSprite;
	bool rolling;
	float animation_time;
	float frameDuration;
	int frameIndex;

public:
	Dice(vector<string>& filenames);
	int roll();
	void setposition(float x, float y);
	void update(float new_t);
	sf::Sprite getSprite();
	void setRolling(bool isrolling);
	bool isrolling();
	void setScale(float scaleX, float scaleY);


};