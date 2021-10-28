#include "Events/Events.h"

ge::Events::Events()
{
	m_current = Event::NONE;
}

ge::Events::Events(ge::Events::Event t_current)
{
	m_current = t_current;
}

ge::Events::~Events() {}

void ge::Events::setCurrent(ge::Events::Event event) {
	m_current = event;
}

ge::Events::Event ge::Events::getCurrent() {
	return m_current;
}
