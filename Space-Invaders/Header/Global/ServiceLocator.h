#pragma once
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Player\PlayerService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Time\TimeService.h"

class ServiceLocator
{
private:


	GraphicService *graphicService;
	EventService* eventService;
	PlayerService* playerService;
	TimeService* timeService;
	
	ServiceLocator();
	~ServiceLocator();

	void CreateServices();
	void ClearAllServices();

public:
	static ServiceLocator* GetInstance();

	void Initialize();
	void Update();
	void Render();

	GraphicService* getGraphicService();
	EventService* getEventService();
	PlayerService* getPlayerService();
	TimeService* getTimeService();


};
