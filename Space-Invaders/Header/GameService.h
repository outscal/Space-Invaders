#pragma once

// we declare a function that returns an integer and takes two int arguments. -declaration
// we say nothing about what it actually does.

class GameService
{
private:
	void initialize(); //Handles game initialization.
	void destroy(); // Handles cleanup tasks

public:
	GameService(); //Constructor for initializing the GameService object
	~GameService(); //Destructor for cleaning up resources upon object deletion

	void ignite(); //initiates the game
	void update(); //updates the game logic and game state
	void render(); //renders each frame of the game
	bool isRunning(); //checks to see if the game is currently running

};