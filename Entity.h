#ifndef ENTITY_H
#define ENTITY_H
#include <algorithm>
#include <vector>
#include "Component.h"
class Entity {
public:
	typedef std::vector<Component*>::iterator ComponentIterator;
	std::string name;
	Entity() {};

	void addComponent(Component* c) {
		m_components.push_back(c);
	}

	void removeComponent(Component* c) {
		std::vector<Component*>::const_iterator it;
		it = std::find_if(m_components.begin(), m_components.end(), [&c](const Component* comp) {
			return comp->getType() == c->getType();
		});
		if (it != m_components.end()) {
			delete (*it);
			m_components.erase(it);
		}
	}

	bool hasComponent(Component::Type type) {
		std::vector<Component*>::const_iterator it = std::find_if(m_components.begin(), m_components.end(), [type](const Component* comp) {
			return comp->getType() == type;
		});
		if (it != m_components.end())
			return true;
		else
			return false;
	}

	Component* getComponent(Component::Type type) {
		ComponentIterator it = std::find_if(m_components.begin(), m_components.end(), [type](const Component* comp) {
			return comp->getType() == type;
		});
		if (it != m_components.end())
			return (*it);
		else
			return nullptr;
	}
	std::vector<Component*> getComponents() { return m_components; }

	void removeComponents() {
		ComponentIterator it = m_components.begin();
		ComponentIterator end = m_components.end();

		for (; it != end; ++it) {
			delete (*it);
		}

		m_components.clear();
	}
private:
	std::vector<Component*> m_components;
};
#endif