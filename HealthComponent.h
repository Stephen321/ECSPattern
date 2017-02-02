#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H
#include "Component.h"

class HealthComponent : public Component {
public:
	HealthComponent() : Component(Type::Health), m_health(100) {}
	int getHealth() const { return m_health; }
	void setHealth(int health) { m_health = health; }
private:
	int m_health;
};
#endif