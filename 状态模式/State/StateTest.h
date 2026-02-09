#ifndef STATETEST_H
#define STATETEST_H

#include <iostream>
#include <memory>
#include <string>

class CTMachine;

class State
{
public:
	virtual ~State() = default;
	virtual void scan(CTMachine* machine) = 0;
	virtual void stop(CTMachine* machine) = 0;

protected:
	void changedState(CTMachine* machine, std::unique_ptr<State> newState);
};


class CTMachine
{
private:
	std::unique_ptr<State> currentState;

public:
	CTMachine(std::unique_ptr<State> initialState)
		: currentState(std::move(initialState))
	{

	}

	void setState(std::unique_ptr<State> newState)
	{
		currentState = std::move(newState);
	}

	void requestScan()
	{
		currentState->scan(this);
	}

	void requestStop()
	{
		currentState->stop(this);
	}
};

void State::changedState(CTMachine* machine, std::unique_ptr<State> newState)
{
	machine->setState(std::move(newState));
}

class ScanningState : public State
{
	void scan(CTMachine* machine) override
	{
		std::cout << "[É¨ÃèÖÐ] ÒÑ¾­ÔÚÉ¨ÃèÁË£¬ÇëÎðÖØ¸´²Ù×÷¡£" << std::endl;
	}

	void stop(CTMachine* machine) override;
};

class IdleState : public State
{
	void scan(CTMachine* machine) override
	{
		std::cout << "[¿ÕÏÐ] ¿ªÊ¼É¨ÃèÁ÷³Ì..." << std::endl;
		changedState(machine, std::make_unique<ScanningState>());
	}

	void stop(CTMachine* machine) override
	{
		std::cout << "[¿ÕÏÐ] »úÆ÷ÒÑÍ£Ö¹£¬ÎÞ²Ù×÷¡£" << std::endl;
	}
};

void ScanningState::stop(CTMachine* machine)
{
	std::cout << "[É¨ÃèÖÐ] Í£Ö¹É¨Ãè£¬»Øµ½¿ÕÏÐ×´Ì¬¡£" << std::endl;
	changedState(machine, std::make_unique<IdleState>());
}


#endif//STATETEST_H