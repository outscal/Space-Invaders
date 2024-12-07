#include "../../HeaderFiles/Time/TimeService.h"

namespace Time {

	void TimeService::initialize() {
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;
	}

	void TimeService::update() {
		updateDeltaTime();
	}

	void TimeService::updateDeltaTime() {
		delta_time = calculateDeltaTime();
		updatePreviousTime();
	}
	float TimeService::getDeltaTime() {
		return delta_time;
	}

	float TimeService::calculateDeltaTime()
	{
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - previous_time).count();

		// The cast is used to convert delta time from microseconds into seconds.
		// We will learn aboit how this works in detail later.
		return static_cast<float>(delta) / static_cast<float>(1000000);
	}


	void TimeService::updatePreviousTime() { //Updated the previous time to a new time. To keep the difference between frames same the second delta time becomes the first
		previous_time = std::chrono::steady_clock::now();
	}
}




