#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
	enum class Type {
		Health,
		Position,
		Control
	};
	Component(Type type) : m_type(type) {}
	Type getType() const { return m_type; }

private:
	Type m_type;
};
#endif