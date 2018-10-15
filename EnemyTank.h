#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__
//#include <WinSock2.h>
//
//#include <windows.h>
#include "Tank.h"

#define MAX_STEP_TURN	20
#define MAX_STEP_SHOOT	15

class EnemyTank : public Tank
{
public:
	EnemyTank()
	{
		RandomTank();
	}

	~EnemyTank(){}

	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullets);

	void set_stepCnt(int stepCnt);


protected:
	void CalculateSphere();
	void RandomTank();
	// 随机产生坦克方向 type： 1, 新方向必须与之前方向不同 2, 任意一个新方向
	void RandomDir(int type);

	int m_stepCnt;//大概走几步会改变方向
};

#endif