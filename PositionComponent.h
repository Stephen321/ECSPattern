#ifndef POSITONCOMPONENT_H
#define POSITONCOMPONENT_H
#include "Component.h"

class PositionComponent : public Component {
public:
	PositionComponent() : Component(Type::Position), m_x(5), m_y(5) {}
	int getX() const { return m_x; }
	void setX(int x) { m_x = x; }	
	int getY() const { return m_x; }
	void setY(int x) { m_x = x; }
private:
	int m_x;
	int m_y;
};
#endif