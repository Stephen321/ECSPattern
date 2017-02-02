#ifndef CONTROLCOMPONENT_H
#define CONTROLCOMPONENT_H
#include "Component.h"

class ControlComponent : public Component {
public:
	ControlComponent() : Component(Type::Control), m_aPressed(false), m_dPressed(false) {}
	int getAPressed() const { return m_aPressed; }
	void setAPressed(bool aPressed) { m_aPressed = aPressed; }
	int getDPressed() const { return m_dPressed; }
	void setDPressed(bool dPressed) { m_dPressed = dPressed; }
private:
	bool m_aPressed;
	bool m_dPressed;
};
#endif