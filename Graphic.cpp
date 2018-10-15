
#include "Graphic.h"

#include "Setting.h"

Rect Graphic::m_rectScreen; 
Rect Graphic::m_rectBattleGround;
char Graphic::m_pArray[100];

void Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(DARKGRAY);

	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graphic::Destroy()
{
	closegraph();
}

void Graphic::DrawBattleGround()
{
	rectangle(m_rectBattleGround.GetStartPoint().GetX(), m_rectBattleGround.GetStartPoint().GetY(),
		m_rectBattleGround.GetEndPoint().GetX(), m_rectBattleGround.GetEndPoint().GetY());
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

Rect Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}

const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;

void Graphic::ShowScore()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPTSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());
	drawtext((LPTSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPTSTR)m_pArray, _T("分  数  :  %d"), Setting::GetSumScore());
	drawtext((LPTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPTSTR)m_pArray, _T("级  别  :  %d"), Setting::GetTankLevel());
	drawtext((LPTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPTSTR)m_pArray, _T("生  命  :  %d"), Setting::GetLife());
	drawtext((LPTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPTSTR)m_pArray, _T("敌人数  :  %d"), Setting::GetTankNum());
	drawtext((LPTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPTSTR)m_pArray, _T("共击毁敌人数  :  %d"), Setting::GetTankSum());
	drawtext((LPTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Graphic::ShowGameLevel(int nLevel)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPTSTR)m_pArray, _T("第 %d 关"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPTSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPTSTR)m_pArray, _T("按 Enter 键准备进入游戏"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

/*
	ERROR:网络连接错误
*/
void Graphic::ShowErrorNoNetwork(int nLevel)
{

	//new added here
	// Draw Background
	cleardevice();
	Graphic::DrawBattleGround();

	//waiting to be modified
	Graphic::ShowScore();

	// end of new 

	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPTSTR)m_pArray, _T("第 %d 关"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPTSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPTSTR)m_pArray, _T("网络连接出错"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
	Sleep(100);
}


/*
	表示找到了队友，休眠100毫秒
*/
void Graphic::ShowGameLevel_got_friend(int nLevel,char* ip)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPTSTR)m_pArray, _T("第 %d 关"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPTSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f); 

	char *content = "即将与玩家";
	strcat_s(content, strlen(ip) + 1, ip);
	strcat_s(content, strlen("共同战斗") + 1, "共同战斗");
	wsprintf((LPTSTR)m_pArray, _T(content), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
	Sleep(100);
}

/*
	表示找到了队友
*/
void Graphic::showGameLevel_waiting(int nLevel)
{	
	for (int i = 1; i < 6; i++) {
		ShowGameLevel_waiting_sub(nLevel, i);
	}
}

/*
表示找到了队友_动画制作
*/
void Graphic::ShowGameLevel_waiting_sub(int nLevel, int waitCount)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPTSTR)m_pArray, _T("第 %d 关"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPTSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	switch (waitCount)
	{
	case 1:
		wsprintf((LPTSTR)m_pArray, _T("匹配队友中."), nLevel);
		Sleep(100);
		break;
	case 2:
		wsprintf((LPTSTR)m_pArray, _T("匹配队友中.."), nLevel);
		Sleep(100);
		break;
	case 3:
		wsprintf((LPTSTR)m_pArray, _T("匹配队友中..."), nLevel);
		Sleep(100);
		break;
	case 4:
		wsprintf((LPTSTR)m_pArray, _T("匹配队友中...."), nLevel);
		Sleep(100);
		break;
	case 5:
		wsprintf((LPTSTR)m_pArray, _T("匹配队友中....."), nLevel);
		Sleep(100);
		break;
	default:
		break;
	}
}




void Graphic::ShowGameOver( )
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPTSTR)m_pArray, _T("GAME OVER"));
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPTSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPTSTR)m_pArray, _T("按 Enter 键退出"));
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}