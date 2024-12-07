#pragma once
#include <chrono>
//set up Timeservice.h and .cpp


namespace Time
{
	class TimeService {

		// The TimeService class helps keep track of time in game and calculate delta time.
		// Utilizes the <chrono> library to calculate delta time.

	private:

		// A point in time which indicates the starting time of previous frame.
		std::chrono::time_point<std::chrono::steady_clock> previous_time;

		float delta_time; //to store the detla time

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:
		void update();
		void initialize();

		//getter
		float getDeltaTime();

	};
}
