#pragma once

class GameService
{
private:
	void initialize(); // Handles Intialize the game		
	void destroy();	// Handles Clean up the memory


public:
	GameService();  //Constructor
	~GameService();	    //Destructor

	void ignite();	//Intialize the game
	void update();	//update the game logic and game state
	void render();		//render game in each frame
	bool isRunning();  //check if game is running or not
};
