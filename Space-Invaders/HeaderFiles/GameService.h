#pragma once

class GameService
{
private:
	void initialize(); // Handle game initialization
	void destroy(); // Destroys unneeded objects
	void iz();

public:
	GameService(); // Default Constructor 
	~GameService(); // Deconstructor
	void update(); // Updating game logic
	void ignite(); // initiates the game
	void render(); //Rendering the next frame
	bool isRunning(); //check if the game is currently running

     
};