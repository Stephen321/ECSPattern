#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H
#include <iostream>
#include "Entity.h"
#include "PositionComponent.h"

class RenderSystem {
public:
	void addEntity(Entity* e) {
		m_entities.push_back(e);
	}

	void update() {
		std::cout << "RenderSystem Update:" << std::endl;

		for (Entity* e : m_entities) {
			PositionComponent* positionComponent = 
				static_cast<PositionComponent*>(e->getComponent(Component::Type::Position));
			std::cout << "Drawing " << e->name.c_str() << " at position " << positionComponent->getX() 
				      << ", " << positionComponent->getY() << std::endl;
		}

		std::cout << std::endl;
	}

private:
	std::vector<Entity*> m_entities;
};

#endif