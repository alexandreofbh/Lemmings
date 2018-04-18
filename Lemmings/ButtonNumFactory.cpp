#include "Game.h"
#include "ButtonNumFactory.h"

Sprite* ButtonNumFactory::createNum(int num)
{
	Sprite *numSprite = Sprite::createSprite(glm::ivec2(3, 8), glm::vec2(3.f/16, 0.25), &Scene::shaderProgram(), &Game::spriteSheets().numSprites);
	numSprite->setNumberAnimations(1);
	numSprite->addKeyframe(0, this->numPositions[num]);
	numSprite->changeAnimation(0);

	return numSprite;
}
