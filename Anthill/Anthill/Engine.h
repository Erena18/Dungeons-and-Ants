#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>

using namespace sf;

#include "asset.h"
#include "itemGeneration.h"

struct GameData {
	RenderWindow window;
	assetManager assets;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Engine
{
public:
	Engine(int widht, int hight, std::string title);
private:
	const float dt = 1.0f / 60.0f;
	Clock _clock;
	GameDataRef _data = std::make_shared<GameData>();

	void Run();
};