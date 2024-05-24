#pragma once
#include <chrono>
class TimeService
{
private:

	// A point in time which indicates the starting time of previous frame.
	std::chrono::time_point<std::chrono::steady_clock> previous_time;
	// No need to worry about the syntax of this variable too much right now
	// It'll be explained in detail at a later time.

	float delta_time; //to store the detla time

	void UpdateDeltaTime(); // method to update time
	float CalculateDeltaTime(); //calculate time by subtracting the previous time from the current time
	void UpdatePreviousTime(); // finally update the current time to be previous time

public:

	//lifecycle methods
	void Initialize();
	void Update();

	//getter
	float GetDeltaTime();
};
