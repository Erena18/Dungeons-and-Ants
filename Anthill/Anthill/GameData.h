#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <string>

#include "asset.h"

using namespace std;
using namespace sf;

struct GameData {
    RenderWindow window;
    assetManager assets;
};

typedef shared_ptr<GameData> GameDataRef;