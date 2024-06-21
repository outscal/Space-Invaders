#include <iostream>
using namespace std;
#include"../HeaderFiles/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{ // creates insatnces of the servicelocator services
}
ServiceLocator::~ServiceLocator() {
	//cleams up services that are not needed
}
void ServiceLocator::initialize(){
	//initializes the service locator class
}
void ServiceLocator::update() {
	//Keeps on updating services required and updates the game state
}
void ServiceLocator::render() {
	//Keeps on rendering the new services
}
void ServiceLocator::createServices() {

}
void ServiceLocator::clearAllServices() {

}
 //ServiceLocator:: static ServiceLocator* getInstance() {

//}
