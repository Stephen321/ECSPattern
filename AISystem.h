#ifndef AISYSTEM_H
#define AISYSTEM_H
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"
#include "HealthComponent.h"

class AISystem {
public:
	void addEntity(Entity* e) {
		m_entities.push_back(e);
	}

	void update(){
		std::cout << "AISystem Update:" << std::endl;

		for (Entity* e : m_entities) {
			HealthComponent* healthComponent =
				static_cast<HealthComponent*>(e->getComponent(Component::Type::Health));

			int currentHealth = healthComponent->getHealth();
			std::cout << "Updating Health for " << e->name.c_str() << ". Current Health: " 
				      << currentHealth << std::endl;
			healthComponent->setHealth(currentHealth--);

			PositionComponent* positionComponent =
				static_cast<PositionComponent*>(e->getComponent(Component::Type::Position));

			int currentX = positionComponent->getX();
			int currentY = positionComponent->getY();
			std::cout << "Updating Position for " << e->name.c_str() << " at:" 
				      << currentX << ", " << currentY << std::endl;
			positionComponent->setX(currentX + 5);
			positionComponent->setY(currentY + 5);
		}

		std::cout << std::endl;
	}

private:
	std::vector<Entity*> m_entities;
};

#endif