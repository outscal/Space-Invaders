#pragma once

class GameService
{
private:
	void initialize(); //Handles game initialization
	void destroy();    //Handles the cleanup task.

public:
	GameService();  //Constructor for initilizing the GameService object.
	~GameService(); //Deconstructor for cleaning up resources upon object deletion.

	void ignite();  //initiates the game logic game state.
	void update();  //Updats the game logic and game state.
	void render();  //Renders each frame of the game.
	bool isRuning(); //Checks if the game is currently runing
};