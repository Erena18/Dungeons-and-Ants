#include <SFML/Graphics.hpp>
#include <iostream>
#include "asset.h"
using std::string;
using namespace sf;

void assetManager::LoadTexture(string name, string fileName)
{
	Texture tex;
	if (tex.loadFromFile(fileName))
	{
		this->_textures[name] = tex;
	}
}

Texture& assetManager::GetTexture(string name)
{
	return this->_textures.at(name);
}

/*void assetManager::LoadSoundBuffer(string name, string fileName)
{
	SoundBuffer buffer;
	if (buffer.loadFromFile(fileName))
	{
		this->_soundBuffer[name] = buffer;
	}
}

sf::SoundBuffer& assetManager::GetSoundBuffer(string name)
{
	return this->_soundBuffer.at(name);
}

void assetManager::LoadMusic(string name, string fileName)
{
	std::unique_ptr<Music> music = std::make_unique<Music>();
	if (music->openFromFile(fileName))
	{
		this->_music[name] = std::move(music);
	}
}

sf::Music& assetManager::GetMusic(string name)
{
	return *this->_music.at(name);
}
*/