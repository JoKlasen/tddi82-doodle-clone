#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <stack>
#include "State.h"


class State_Machine
{

public:

State_Machine(std::unique_ptr<State> initial_state);

void switch_state (std::unique_ptr<State> state);

bool previous_state();


private:

std::stack<std::unique_ptr<State>> state_stack;

State & current_state () const;

};

#endif