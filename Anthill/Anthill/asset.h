#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using std::string;
using namespace sf;

class assetManager
{
public:
	assetManager() {}
	~assetManager() {}

	void LoadTexture(string name, string fileName);
	sf::Texture& GetTexture(string name);

	void LoadSoundBuffer(string name, string fileName);
	sf::SoundBuffer& GetSoundBuffer(string name);

	void LoadMusic(string name, string fileName);
	sf::Music& GetMusic(string name);
	
private:
	std::map<string, Texture> _textures;
	std::map<string, SoundBuffer> _soundBuffer;
	std::map<string, std::unique_ptr<Music>> _music;
};