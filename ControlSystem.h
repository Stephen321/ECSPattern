#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"
#include "ControlComponent.h"

class ControlSystem {
public:
	void addEntity(Entity* e) {
		m_entities.push_back(e);
	}

	void update() {
		std::cout << "ControlSystem Update:" << std::endl;

		for (Entity* e : m_entities) {
			ControlComponent* controlComponent =
				static_cast<ControlComponent*>(e->getComponent(Component::Type::Control));
			std::cout << "Getting keys pressed for " << e->name.c_str() 
				<< " APressed: " << controlComponent->getAPressed() 
				<< " DPressed: " << controlComponent->getDPressed() << std::endl;

			PositionComponent* positionComponent =
				static_cast<PositionComponent*>(e->getComponent(Component::Type::Position));
			std::cout << "Control Position for " << e->name.c_str() << " at:"
				<< positionComponent->getX() << ", " << positionComponent->getY() << std::endl;

		}

		std::cout << std::endl;
	}

private:
	std::vector<Entity*> m_entities;
};

#endif