#include <chrono>
#include <thread>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"

#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"

int main() {
	std::vector<Entity> entities;

	Entity player;
	player.name = "player";
	player.addComponent(new HealthComponent());
	player.addComponent(new PositionComponent());
	player.addComponent(new ControlComponent());
	entities.push_back(player);

	Entity alien;
	alien.name = "alien";
	alien.addComponent(new HealthComponent());
	alien.addComponent(new PositionComponent());
	entities.push_back(alien);

	Entity cat;
	cat.name = "cat";
	cat.addComponent(new PositionComponent());
	entities.push_back(cat);

	Entity dog;
	dog.name = "dog";
	dog.addComponent(new HealthComponent());
	dog.addComponent(new PositionComponent());
	entities.push_back(dog);


	ControlSystem controllSystem;
	for (std::vector<Entity>::iterator it = entities.begin(); it != entities.end(); ++it) {
		if (it->hasComponent(Component::Type::Position) && it->hasComponent(Component::Type::Control))
			controllSystem.addEntity(&(*it));
	}

	RenderSystem renderSystem;
	for (std::vector<Entity>::iterator it = entities.begin(); it != entities.end(); ++it) {
		if (it->hasComponent(Component::Type::Position))
			renderSystem.addEntity(&(*it));
	}

	AISystem aiSystem;
	for (std::vector<Entity>::iterator it = entities.begin(); it != entities.end(); ++it) {
		if (it->hasComponent(Component::Type::Health) && it->hasComponent(Component::Type::Position))
			aiSystem.addEntity(&(*it));
	}
	std::chrono::seconds duration(5);
	int systemToUpdate = 0;
	while (true) {
		if (systemToUpdate == 0)
			controllSystem.update();
		else if (systemToUpdate == 1)
			renderSystem.update();
		else
			aiSystem.update();


		std::this_thread::sleep_for(duration);
		systemToUpdate++;
		if (systemToUpdate == 3)
			systemToUpdate = 0;
	}

	for (Entity& e : entities)
		e.removeComponents();

	return 0;
}