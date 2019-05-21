#include "main.h"				// Headers

namespace noGlobal
{
	int cpuKiller{ 0 };		// Ranodom key sound generator, takes quite a big toll on CPU usage, but still below 6% on mine
	int keyNumber{ 0 };		// Used to determine which key sound will be used
	int aCounter{ 0 };		// Key used just for A to allow for quick succession of A and D to be pressed
	int dCounter{ 0 };		// Key used just for D to allow for quick succession of A and D to be pressed
	std::string settingsIn{ 0 };		// String checkker used to determine the output on the settings page.
	std::string pauseKey{ 0 }; 		// Key used to unpause the program
	bool enableKey{ true };	// Toggle used for held keys
	bool holdKeysT{ true };	// Toggle exclusive to holdKeys()
	bool holdKey2T{ true };	// Toggle exclusive to holdKeys() but its actually inside the loop inside holdKeys()
	bool muteMouse{ false };	// Setting for muting mouse press sounds.
	bool muteKeys{ false };	// Setting for muting keys sounds.
	bool muteSpace{ false };	// Setting for muting spacebar sounds.
	bool replaceSpcWKey{ false };	// Setting for replacing spacebar sounds with normal key sounds.
	bool breakItAll{ false };
}

void playSpaceSound()
	{
		if (muteSpace == true)
		{
		}
		else
		{
			keyNumber = (rand() + cpuKiller) % 6 + 1;
			if (keyNumber == 1) //if the result of the above equation equals 1:
			{
				PlaySound(TEXT("\Key noises\\spacebar1.wav"), NULL, SND_ASYNC); // Play the wav file at that directory
			}
			if (keyNumber == 2)
			{
				PlaySound(TEXT("\Key noises\\spacebar2.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 3)
			{
				PlaySound(TEXT("\Key noises\\spacebar3.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 4)
			{
				PlaySound(TEXT("\Key noises\\spacebar4.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 5)
			{
				PlaySound(TEXT("\Key noises\\spacebar5.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 6)
			{
				PlaySound(TEXT("\Key noises\\spacebar6.wav"), NULL, SND_ASYNC);
			}
		}
	}
void playMouseSound()
	{
	if (muteMouse == true)
	{

	}
	else
		{
			keyNumber = (rand() + cpuKiller) % 3 + 1;
			if (keyNumber == 1) //if the result of the above equation equals 1:
			{
				PlaySound(TEXT("\Key noises\\mouseclick1.wav"), NULL, SND_ASYNC); // Play the wav file at that directory
			}
			if (keyNumber == 2) //if the result of the above equation equals 2:
			{
				PlaySound(TEXT("\Key noises\\mouseclick2.wav"), NULL, SND_ASYNC); // Play the wav file at that directory
			}
			if (keyNumber == 3) //if the result of the above equation equals 3:
			{
				PlaySound(TEXT("\Key noises\\mouseclick3.wav"), NULL, SND_ASYNC); // Play the wav file at that directory
			}
		}
	}
void playKeySound  () // Key sound function
	{
	if (muteKeys == true) 
	{

	}

	else
		{
			keyNumber = (rand() + cpuKiller) % 8 + 1; // Use cpuKiller variable to generate a new random number between 1 and 8
			if (keyNumber == 1) //if the result of the above equation equals 1:
			{
				PlaySound(TEXT("\Key noises\\keypress1.wav"), NULL, SND_ASYNC); // Play the wav file at that directory
			}
			if (keyNumber == 2)
			{
				PlaySound(TEXT("\Key noises\\keypress2.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 3)
			{
				PlaySound(TEXT("\Key noises\\keypress3.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 4)
			{
				PlaySound(TEXT("\Key noises\\keypress4.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 5)
			{
				PlaySound(TEXT("\Key noises\\keypress5.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 6)
			{
				PlaySound(TEXT("\Key noises\\keypress6.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 7)
			{
				PlaySound(TEXT("\Key noises\\keypress7.wav"), NULL, SND_ASYNC);
			}
			if (keyNumber == 8)
			{
				PlaySound(TEXT("\Key noises\\keypress8.wav"), NULL, SND_ASYNC);
			}
		}

	}



void holdKeys	   ()
	{
		// Hold key failsafe (keys I hold down often, usually ingame). So it doesn't spam.
		while ((GetAsyncKeyState(VK_TAB) & 0x8000)
			|| (GetAsyncKeyState(VK_SHIFT) & 0x8000)
			|| (GetAsyncKeyState(VK_CONTROL) & 0x8000)
			|| (GetAsyncKeyState(VK_MENU) & 0x8000)
			|| (GetAsyncKeyState(VK_SHIFT) & 0x8000)
			|| (GetAsyncKeyState(VK_BACK) & 0x8000)
			|| (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			|| (GetAsyncKeyState(VK_DELETE) & 0x8000)
			|| (GetAsyncKeyState(VK_NEXT) & 0x8000)
			|| (GetAsyncKeyState(VK_PRIOR) & 0x8000)
			|| (GetAsyncKeyState(VK_UP) & 0x8000)
			|| (GetAsyncKeyState(VK_DOWN) & 0x8000)
			|| (GetAsyncKeyState(VK_LEFT) & 0x8000)
			|| (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			)
		{
			if (holdKeysT == 1)
			{
				playKeySound();
			}

			while ((GetAsyncKeyState('W') & 0x8000)
				|| (GetAsyncKeyState('S') & 0x8000))
			{
				if (enableKey == 1)
				{
					playKeySound();
				}
				while (GetAsyncKeyState('A') & 0x8000)
				{
					if (!(GetAsyncKeyState('D') & 1) && aCounter == 0)
					{
						dCounter = 0;
						playKeySound();
					}
					detectAllElse();
					aCounter = 1; Sleep(50);
				}
				while (GetAsyncKeyState('D') & 0x8000)
				{
					if (!(GetAsyncKeyState('A') & 1) && dCounter == 0)
					{
						aCounter = 0;
						playKeySound();
					}
					detectAllElse();
					dCounter = 1; Sleep(50);
				}
				detectAllElse();
				enableKey = 0;
				Sleep(10);
			}

			while (GetAsyncKeyState('D') & 0x8000)
			{
				if (!(GetAsyncKeyState('A') & 1) && dCounter == 0)
				{
					aCounter = 0;
					playKeySound();
				}
				detectAllElse();
				dCounter = 1; Sleep(50);
			}
			holdKeysT = 0; enableKey = 1; dCounter = 0; aCounter = 0; holdKey2T = 1;

			while ((GetAsyncKeyState(VK_UP) & 0x8000)
				|| (GetAsyncKeyState(VK_DOWN) & 0x8000)
				|| (GetAsyncKeyState(VK_LEFT) & 0x8000)
				|| (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				|| (GetAsyncKeyState(VK_TAB) & 0x8000))
			{
				if (holdKey2T == 1)
				{
					playKeySound();
				}
				holdKey2T = 0;
				Sleep(10);
			}
			detectAllElse();
		}
	}
void detectAllElse ()
	{
		// Big spam of everything else. Its good because it allows for key crossover, which sometimes messes up otherwise.
		if ((GetAsyncKeyState('1') & 1)
			|| (GetAsyncKeyState('2') & 1)
			|| (GetAsyncKeyState('3') & 1)
			|| (GetAsyncKeyState('4') & 1)
			|| (GetAsyncKeyState('5') & 1)
			|| (GetAsyncKeyState('6') & 1)
			|| (GetAsyncKeyState('7') & 1)
			|| (GetAsyncKeyState('8') & 1)
			|| (GetAsyncKeyState('9') & 1)
			|| (GetAsyncKeyState('0') & 1)
			|| (GetAsyncKeyState('Q') & 1)
			|| (GetAsyncKeyState('E') & 1)
			|| (GetAsyncKeyState('R') & 1)
			|| (GetAsyncKeyState('T') & 1)
			|| (GetAsyncKeyState('Y') & 1)
			|| (GetAsyncKeyState('U') & 1)
			|| (GetAsyncKeyState('I') & 1)
			|| (GetAsyncKeyState('O') & 1)
			|| (GetAsyncKeyState('P') & 1)
			|| (GetAsyncKeyState('F') & 1)
			|| (GetAsyncKeyState('G') & 1)
			|| (GetAsyncKeyState('H') & 1)
			|| (GetAsyncKeyState('J') & 1)
			|| (GetAsyncKeyState('K') & 1)
			|| (GetAsyncKeyState('L') & 1)
			|| (GetAsyncKeyState('Z') & 1)
			|| (GetAsyncKeyState('X') & 1)
			|| (GetAsyncKeyState('C') & 1)
			|| (GetAsyncKeyState('V') & 1)
			|| (GetAsyncKeyState('B') & 1)
			|| (GetAsyncKeyState('N') & 1)
			|| (GetAsyncKeyState('M') & 1)
			|| (GetAsyncKeyState(VK_OEM_1) & 1)
			|| (GetAsyncKeyState(VK_OEM_2) & 1)
			|| (GetAsyncKeyState(VK_OEM_PLUS) & 1)
			|| (GetAsyncKeyState(VK_OEM_COMMA) & 1)
			|| (GetAsyncKeyState(VK_OEM_MINUS) & 1)
			|| (GetAsyncKeyState(VK_OEM_PERIOD) & 1)
			|| (GetAsyncKeyState(VK_OEM_3) & 1)
			|| (GetAsyncKeyState(VK_OEM_4) & 1)
			|| (GetAsyncKeyState(VK_OEM_5) & 1)
			|| (GetAsyncKeyState(VK_OEM_6) & 1)
			|| (GetAsyncKeyState(VK_OEM_7) & 1)
			|| (GetAsyncKeyState(VK_OEM_8) & 1)
			|| (GetAsyncKeyState(VK_OEM_102) & 1)
			|| (GetAsyncKeyState(VK_F1) & 1)
			|| (GetAsyncKeyState(VK_F2) & 1)
			|| (GetAsyncKeyState(VK_F3) & 1)
			|| (GetAsyncKeyState(VK_F4) & 1)
			|| (GetAsyncKeyState(VK_F5) & 1)
			|| (GetAsyncKeyState(VK_F6) & 1)
			|| (GetAsyncKeyState(VK_F7) & 1)
			|| (GetAsyncKeyState(VK_F8) & 1)
			|| (GetAsyncKeyState(VK_F9) & 1)
			|| (GetAsyncKeyState(VK_F10) & 1)
			|| (GetAsyncKeyState(VK_F11) & 1)
			|| (GetAsyncKeyState(VK_F12) & 1)
			|| (GetAsyncKeyState(VK_LWIN) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD1) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD2) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD3) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD4) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD5) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD6) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD7) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD8) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD9) & 1)
			|| (GetAsyncKeyState(VK_NUMPAD0) & 1)
			|| (GetAsyncKeyState(VK_MULTIPLY) & 1)
			|| (GetAsyncKeyState(VK_ADD) & 1)
			|| (GetAsyncKeyState(VK_SUBTRACT) & 1)
			|| (GetAsyncKeyState(VK_DECIMAL) & 1)
			|| (GetAsyncKeyState(VK_DIVIDE) & 1)
			|| (GetAsyncKeyState(VK_INSERT) & 1)
			|| (GetAsyncKeyState(VK_HOME) & 1)
			|| (GetAsyncKeyState(VK_RETURN) & 1)
			)
		{
			playKeySound();
		}
		if ((GetAsyncKeyState(VK_LBUTTON) & 1)
			|| (GetAsyncKeyState(VK_RBUTTON) & 1)
			|| (GetAsyncKeyState(VK_MBUTTON) & 1)
			|| (GetAsyncKeyState(VK_XBUTTON1) & 1)
			|| (GetAsyncKeyState(VK_XBUTTON2) & 1)
			)
		{
			playMouseSound();
		}
	}
void startProgram  ()
{
	for (;;)
	{
	ReLoop:
		++cpuKiller; // increment cpuKiller
		// Pause program trigger. Requires you to hold down the 'end' key and then press 'alt'
		while (GetAsyncKeyState(VK_END) & 0x8000)
		{
			if (enableKey == 1)
			{
				playKeySound();
			}

			if (GetAsyncKeyState(VK_MENU) & 0x8000)
			{
				playKeySound();
				goto BreakEveryThing;
			} enableKey = 0;
		}
		holdKeys();
		// Space, 'A' and 'D' hold failsafe because I'm a pro autostrafer.
		while (GetAsyncKeyState('A') & 0x8000)
		{
			if (!(GetAsyncKeyState('D') & 1) && aCounter == 0)
			{
				dCounter = 0;
				playKeySound();
			}
			detectAllElse();
			holdKeys();
			aCounter = 1; Sleep(50);
		}
		while (GetAsyncKeyState('D') & 0x8000)
		{
			if (!(GetAsyncKeyState('A') & 1) && dCounter == 0)
			{
				aCounter = 0;
				playKeySound();
			}
			detectAllElse();
			holdKeys();
			dCounter = 1; Sleep(50);
		}
		while (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (enableKey == 1)
			{
				if (replaceSpcWKey == true)
					playKeySound();
				else
					playSpaceSound();
			}
			enableKey = 0;
			while (GetAsyncKeyState('A') & 0x8000)
			{
				if (!(GetAsyncKeyState('D') & 1) && aCounter == 0)
				{
					dCounter = 0;
					playKeySound();
				} aCounter = 1; Sleep(50);
			}
			while (GetAsyncKeyState('D') & 0x8000)
			{
				if (!(GetAsyncKeyState('A') & 1) && dCounter == 0)
				{
					aCounter = 0;
					playKeySound();
				} dCounter = 1; Sleep(50);
			}
			detectAllElse();
			Sleep(10);
		}

		while ((GetAsyncKeyState('W') & 0x8000)
			|| (GetAsyncKeyState('S') & 0x8000))
		{
			if (enableKey == 1)
			{
				playKeySound();
			}
			while (GetAsyncKeyState('A') & 0x8000)
			{
				if (!(GetAsyncKeyState('D') & 1) && aCounter == 0)
				{
					dCounter = 0;
					playKeySound();
				}
				detectAllElse();
				aCounter = 1; Sleep(50);
			}
			while (GetAsyncKeyState('D') & 0x8000)
			{
				if (!(GetAsyncKeyState('A') & 1) && dCounter == 0)
				{
					aCounter = 0;
					playKeySound();
				}
				detectAllElse();
				dCounter = 1; Sleep(50);
			}
			detectAllElse();
			holdKeys();
			enableKey = 0;
			Sleep(10);
		}

		detectAllElse();
		enableKey = 1; dCounter = 0; aCounter = 0; holdKeysT = 1;
		Sleep(10); // This reduces CPU usage by a factor of 5. Went from 25% to 6% max for me
		goto ReLoop;
	BreakEveryThing:
		break;
	}
}