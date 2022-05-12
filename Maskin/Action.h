#pragma once
#include "Entity.h"
class Action
{
public:
	virtual void DoAction(Entity* e) = 0;
};

class MoveForward : public Action
{
public:
	MoveForward();
	virtual void DoAction(Entity* e) {
		e->mY += 1;
	};
};
class MoveRight : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mX += 1;
	};
};
class MoveBackwards : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mY -= 1;
	};
};
class MoveLeft : public Action
{
public:
	virtual void DoAction(Entity* e) {
		e->mX -= 1;
	};
};
