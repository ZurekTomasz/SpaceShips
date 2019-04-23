#pragma once

#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Gift.h"

class Game
{
public:
	Game();
	void run();

private:
	//Set name or resolution
	const string gameName = "SpaceShips";
	static const int gameWidth = 1280;
	static const int gameHeight = 720;

	//Declaration of variables
	static const int gameSpeed = 1000;
	static const int playerBulletSpeed = 50;
	static const int enemyBulletSpeed = 80;
	static const int jumpDown = 40;

	bool gameIsStarted = false;
	int currentLevel = 1;//initial level
	int presentState = 0;//cycles
	int actualView = 0;
	int actualViewChoice = 1;
	string topHighScoreBackground = "menu";

	const string highscoresFileName = "Assets/Data/highscores.csv";
	const string maxLevelFileName = "Assets/Data/maxlevel.csv";
	const int playerIdSkinStart = 0;
	const int playerHPStart = 100;

	sf::RenderWindow renderWindow;
	std::map<string, sf::Texture> textures;
	std::map<string, sf::Sprite> sprites;
	std::map<string, sf::Font> fonts;
	std::map<string, sf::Text> texts;

	Player player;
	std::vector<Enemy*> enemies;
	std::vector<Gift*> gifts;
	std::vector<Bullet*> enemyBullets;
	sf::Event event1;

	Files file2;
	Files file3;

	string highscores[5][2];
	std::vector<string> characters;
	int currentChar[3] = { 0,0,0 };
	int currentCharPosition = 0;

	Bullet tBullet1;
	Bullet tBullet2;

	//Flags for key pressed
	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;
	bool AFlag = false;
	bool DFlag = false;
	bool returnFlag = false;
	bool escapeFlag = false;

	//Methods
	void processEvents();
	int loadAssets();
	void init();
	void update();
	int loadLevel(int level);
};