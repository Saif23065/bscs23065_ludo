#include "Dice.h"
Dice::Dice(vector<string>& filenames):rolling(false), animation_time(0), frameDuration(0.1f) {
	for (auto &filename:filenames)
	{
		sf::Texture texture;
		texture.loadFromFile(filename);
		dices.push_back(texture);
	}
	diceSprite.setTexture(dices[0]);
}
int Dice::roll() {
	int roll = rand() % 6 + 1;
	diceSprite.setTexture(dices[roll - 1]);
	return roll;

}
void Dice::setposition(float x, float y) {
	diceSprite.setPosition(x, y);
}
void Dice::setframe(int frame) {
	if (frameIndex > 0 && frameIndex < dices.size()) {
		diceSprite.setTexture(dices[frameIndex]);
	}
}
void Dice::setRolling(bool isrolling) {
	rolling = isrolling;
}
void Dice::update(float new_t) {
	if (rolling) {
		animation_time += new_t;
		if (animation_time >= frameDuration) {
			animation_time = 0;
			frameIndex = (frameIndex + 1) % dices.size();
			diceSprite.setTexture(dices[frameIndex]);
		}
	}
}
bool Dice::isrolling() {
	return rolling;
}

void Dice::setScale(float scaleX, float scaleY) {
	diceSprite.setScale(scaleX, scaleY);
}


sf::Sprite Dice::getSprite() {
	return diceSprite;
}