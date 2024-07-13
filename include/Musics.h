#pragma once

#include <Resources.h>
#include <SFML/Audio.hpp>


enum GameSounds { Menu_Song, Red_Song, Pink_Song, Blue_Song };

const int SOUNDS = 10;



class Musics
{
public:
	Musics();
	static Musics& instance();
	void playMenuSound();
	//stopMusic
	void stopMusic();
	void playSongLevel(const GameSounds sound);





	const sf::SoundBuffer& getSoundBuffer(const GameSounds sound) const { return m_soundBuffers[sound]; }




private:
	sf::Sound m_menuSound;
	sf::Sound m_levelSound;

	sf::SoundBuffer m_soundBuffers[SOUNDS];
	void loadMusic();

};