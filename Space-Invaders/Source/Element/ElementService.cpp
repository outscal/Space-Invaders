#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\ElementService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\Bunker\BunkerModel.h"

namespace Element
{
	ElementService::ElementService() { }

	ElementService::~ElementService() { Destroy(); }
	
		void ElementService::Initialize()
		{
			for (int i = 0;i < bunker_data_list.size();i++)
			{	
				//create new controllers
				Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();
				bunker_controller->Initialize(bunker_data_list[i]); //init them
				bunker_list.push_back(bunker_controller);
			}
		}
		void ElementService::Update()
		{
			for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->Update();
		}
		void ElementService::Render()
		{
			for (int i = 0; i < bunker_list.size(); i++) bunker_list[i]->Render();
		}
		void ElementService::Destroy()
		{
			for (int i = 0; i < bunker_list.size(); i++) delete(bunker_list[i]);
		}
}