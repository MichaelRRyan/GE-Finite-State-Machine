#ifndef CHANGE_PLAYER_STATE_COMMAND_H
#define CHANGE_PLAYER_STATE_COMMAND_H

#include "FSM/Command.h"
#include "GameObjects/Player.h"
#include "FSM/PlayerState.h"

class ChangePlayerStateCommand : public Command
{
public:

    ChangePlayerStateCommand(Player & t_player, PlayerState * t_state = nullptr) : 
        m_player{ t_player },
        m_state{ t_state }
    {}

    ~ChangePlayerStateCommand() 
    {
        if (m_state)
            delete m_state;
    }

    void setNextState(PlayerState * t_state)
    {
        m_state = t_state;
    }

    virtual void execute() override
    {
        if (m_state != nullptr)
        {
            m_player.setPlayerState(m_state);
            m_state = nullptr;
        }
    }

private:

    Player & m_player;
    PlayerState * m_state;

};

#endif // !CHANGE_PLAYER_STATE_COMMAND_H
