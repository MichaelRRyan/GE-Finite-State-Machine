#ifndef EVENTS_H
#define EVENTS_H

namespace ge {
	class Events
	{
	public:
		enum class Event
		{
			NONE,
			MOVE_UP_START_EVENT,
			MOVE_UP_STOP_EVENT,
			RUN_RIGHT_START_EVENT,
			RUN_RIGHT_STOP_EVENT,
			MOVE_DOWN_START_EVENT,
			MOVE_DOWN_STOP_EVENT,
			JUMP_UP_EVENT,
			FALL_DOWN_EVENT,
			SLIDE_EVENT,
			ATTACK_START_EVENT,
			ATTACK_STOP_EVENT,
			THROW_START_EVENT,
			THROW_STOP_EVENT,
			HIT_WALL_EVENT,
			HIT_GROUND_EVENT,
			HIT_LADDER_TOP_EVENT,
			HIT_LADDER_BOTTOM_EVENT,
			DIED_EVENT,
			REVIVED_EVENT,
			Count
		};

		Events();
		Events(Event t_current);
		~Events();

		void setCurrent(Event);
		Event getCurrent();

	private:
		Event m_current;
	};
}

#endif // !EVENTS_H
