#pragma once
#include "Entity.h"
class Action
{
public:
	Action();
	virtual void DoAction(Entity* e) = 0;
	std::string mActionName = "Action";
	float mModifier = 3.f;
};

class MoveForward : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mY += 1*mModifier;
	};
};
class MoveRight : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mX += 1 * mModifier;
	};
};
class MoveBackwards : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mY -= 1 * mModifier;
	};
};
class MoveLeft : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mX -= 1 * mModifier;
	};
};
