#pragma once
#include <chrono>

/*	- The time service class helps keep track of time in game and calculate delta time
	- Utilizes the <chrono> library to calculate delta time.
*/

namespace Time
{
	class TimeService
	{
	private:
		//A point in time which indicates the starting time of the previous frame
		std::chrono::time_point<std::chrono::steady_clock> previous_time;
		//No need to worry about the syntax of this variable too much right now
		// It will be explained in detail at a time later on

		float delta_time; //To store the delta time

		void updateDeltaTime(); //method to update time
		float calculateDeltaTime(); //calculate time by subtracting the previous time from the current time
		void updatePreviousTime(); // finally update the current time to be previous time

	public:

		//lifecycle methods
		void initialize();
		void update();

		//getter
		float getDeltaTime();
	};
}