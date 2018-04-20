#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE

#include "GameState.h"
#include <glm/glm.hpp>
#include <vector>
#include "MaskedTexturedQuad.h"
#include "SoundManager.h"
#include "Level.h"
#include "Lemming.h"
#include "UI.h"
#include "Word.h"
#include "MaskManager.h"

// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene : public GameState
{

public:

	static Scene &getInstance()
	{
		static Scene instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	void startLevel(string levelMode, int levelNum);

	void eraseMask(int x, int y);
	void applyMask(int x, int y);
	void eraseSpecialMask(int x, int y);
	void applySpecialMask(int x, int y);
	
	void buildStep(glm::vec2 position);
	
	void changePauseStatus();
	void changeSpeedUpStatus();
	bool isPaused();
	bool isSpeedUp();

	int getActualLevel();
	int getActualMode();
	
	void explodeAll();

	char getPixel(int x, int y);

	//******
	int getNumLemmingAlive();
	int getLemmingIndexInPos(int posX, int posY);
	Lemming getLemming(int index);
	bool assignJob(int lemmingIndex, Job *jobToAssign);
	void lemmingSaved();
	void lemmingDied();
	VariableTexture &getMaskedMap();

	void setMaskManager(MaskManager* maskManager);

	void killLemmingInPos(glm::vec2 pos);

private:
	void initMap();
	void initSounds();
	void initUI();

	void spawnLemmings();
	void updateLemmings(int deltaTime);
	void updateCurrentLevel(int deltaTime);
	void updateUI();

	
	
public:
	float currentTime;

private:
	bool doomed;

	bool paused = false;
	bool speedUp = false;
	int lemmingsSaved;
	int lemmingsDied;
	int actualLevel;
	int actualMode;

	MaskedTexturedQuad *map;

	vector<Lemming> lemmings;
	vector<bool> alive;
	int currentAlive; 
	const SoundManager* soundManager;
	FMOD::Sound* music, *dooropen;

	MaskManager *maskManager;

};
#endif // _SCENE_INCLUDE

