#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <WinSock2.h>

#include <windows.h>
#include <list>

#include "Graphic.h"



using namespace std;

enum Dir { UP, DOWN, LEFT, RIGHT };

class Object
{
public:
	// 绘图
	virtual void Display() = 0;

	// 移动
	virtual void Move() = 0;

	// 爆炸
	virtual void Boom(list<Object*>& lstBombs) = 0;

	// 设置消失
	virtual void SetDisappear() = 0;

	// 判断是否消失
	virtual bool IsDisappear() = 0;

	virtual Rect GetSphere() = 0;

	Dir GetDir();

	byte get_id();
	void set_id(byte id);

	Point get_pos();

	void set_pos(int pos_x,int pos_y);
	void Object::SetDir(Dir dir);

	COLORREF get_color();

protected:
	

	
	
	
	
	// 计算势力范围
	virtual void CalculateSphere() = 0;


	

	//add for online 
	byte id;

	// 位置
	Point m_pos;

	// 势力范围
	Rect m_rectSphere;

	

	// 颜色
	COLORREF m_color;
	// 方向
	Dir m_dir;
	// 存在状态
	bool m_bDisappear;
	// 单次前进步长
	int m_step;

};

#endif