#pragma once

class GameService {
private:
	void initialize(); // initializing the game
	void destroy(); //clean up the game

public:
	GameService(); //Constructor
	~GameService(); //Destructor

	void ignite(); // initiates the game
	void update(); //update the game logic and game state 
	void render(); // render each frame of the game
	bool isRunning(); //check if game is running
};
