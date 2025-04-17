#pragma once
#include <map>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class assetManager
{
public:
	assetManager() {}
	~assetManager() {}

	void LoadTexture(string name, string fileName);
	Texture& GetTexture(string name);

	//void LoadSoundBuffer(string name, string fileName);
	//SoundBuffer& GetSoundBuffer(string name);

	//void LoadMusic(string name, string fileName);
	//Music& GetMusic(string name);
	
private:
	map<string, Texture> _textures;
	//map<string, SoundBuffer> _soundBuffer;
	//map<string, unique_ptr<Music>> _music;
};