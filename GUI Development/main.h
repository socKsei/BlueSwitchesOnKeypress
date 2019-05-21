#pragma once
#pragma comment(lib, "user32.lib")
#define flase false // A special little replacement I added because I'm retarded and type 'flase' instead of 'false' sometimes

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <conio.h>
#include <chrono>
#include <fstream>

namespace noGlobal
{
	extern int cpuKiller;		// Ranodom key sound generator, takes quite a big toll on CPU usage, but still below 6% on mine
	extern int keyNumber;		// Used to determine which key sound will be used
	extern int aCounter;		// Key used just for A to allow for quick succession of A and D to be pressed
	extern int dCounter;		// Key used just for D to allow for quick succession of A and D to be pressed
	extern std::string settingsIn;		// String checkker used to determine the output on the settings page.
	extern std::string pauseKey; 		// Key used to unpause the program
	extern bool enableKey;	// Toggle used for held keys
	extern bool holdKeysT;	// Toggle exclusive to holdKeys()
	extern bool holdKey2T;	// Toggle exclusive to holdKeys() but its actually inside the loop inside holdKeys()
	extern bool muteMouse;	// Setting for muting mouse press sounds.
	extern bool muteKeys;	// Setting for muting keys sounds.
	extern bool muteSpace;	// Setting for muting spacebar sounds.
	extern bool replaceSpcWKey;	// Setting for replacing spacebar sounds with normal key sounds.
	extern bool breakItAll;
}

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

using noGlobal::aCounter;
using noGlobal::dCounter;
using noGlobal::cpuKiller;
using noGlobal::enableKey;
using noGlobal::keyNumber;
using noGlobal::settingsIn;
using noGlobal::enableKey;
using noGlobal::pauseKey;
using noGlobal::holdKeysT;
using noGlobal::holdKey2T;
using noGlobal::muteMouse;
using noGlobal::muteKeys;
using noGlobal::muteSpace;
using noGlobal::replaceSpcWKey;



void strafer	   ();
void suddenlyA	   ();
void suddenlyD	   ();

void playKeySound  ();
void playSpaceSound();
void playMouseSound();

void startProgram  ();
void holdKeys	   ();
void detectAllElse ();

void keyLogger	   ();