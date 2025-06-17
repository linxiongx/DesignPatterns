#include "Work.h"
#include "State.h"
#include "ForenoonState.h"

Work::Work()
	:m_pState(new ForenoonState), m_dHour(9)
{

}

void Work::setState(std::unique_ptr<State> pState)
{
	m_pState = std::move(pState);
}

void Work::WriteProgram()
{
	m_pState->WriteProgram(this);
}