#include<iostream>
#include<graphics.h>
using namespace std;
class CKind{
public:
	WCHAR ROOKS = *(_T("车"));
	WCHAR KNIGHTS = *_T("马");
	WCHAR ELEPHANTS = *_T("象");
	WCHAR MINISTERS = *_T("相");
	WCHAR MANDARINS = *_T("士");
	WCHAR GUARDS = *_T("仕");
	WCHAR KING = *_T("将");
	WCHAR GENERALS = *_T("帅");
	WCHAR CANNONS = *_T("炮");
	WCHAR PAWNS = *_T("卒");
	WCHAR SOLDIERS = *_T("兵");
	WCHAR PLAYER_1 = *_T("BLACK");
	WCHAR PLAYER_2 = *_T("RED");
};
class Grid{
	int x, y;
public:
	Grid(){};
	virtual WCHAR get_name(){ return NULL; }
	virtual void drowReady(int x, int y){}
	virtual void setPlayer(WCHAR player){}
	virtual WCHAR getPlayer(){ return NULL; }
	void set_xy(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	pair<int, int>get_xy()
	{
		pair<int, int>p(x, y);
		return p;
	}
};
class Chess :public Grid
{
	WCHAR player;
	WCHAR name;
public:
	Chess(WCHAR name)
	{
		this->name = name;
	}
	WCHAR get_name()
	{
		return name;
	}
	void setPlayer(WCHAR player)
	{
		this->player = player;
	}
	WCHAR getPlayer()
	{
		return player;
	}
	void drowReady(int x, int y)
	{
		setfillcolor(RGB(51, 205, 219));
		fillcircle(x, y, 27);
		RECT r = { x - 18, y - 18, x + 18, y + 18 };
		setbkcolor(RGB(51, 205, 219));
		if (player == *_T("BLACK"))
		{
			settextcolor(BLACK);
		}
		else
			settextcolor(RED);
		drawtext(name, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
};

class PaneBoard{
	CKind ckind;
	int PERLENGTH;//单位长度
	Grid *grid[10][9];
public:
	PaneBoard()
	{
		PERLENGTH = 60;
	}
	//开始游戏
	void startGame()
	{
		initPaneGrid();
		CreateMap();
		repaint();
		messagewhile();
		closegraph();
	}
	//初始化棋盘格
	void initPaneGrid()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				grid[i][j] = NULL;
			}
		}
		//敌方
		grid[0][0] = new Chess(ckind.ROOKS);
		grid[0][1] = new Chess(ckind.KNIGHTS);
		grid[0][2] = new Chess(ckind.ELEPHANTS);
		grid[0][3] = new Chess(ckind.MANDARINS);
		grid[0][4] = new Chess(ckind.KING);
		grid[0][5] = new Chess(ckind.MANDARINS);
		grid[0][6] = new Chess(ckind.ELEPHANTS);
		grid[0][7] = new Chess(ckind.KNIGHTS);
		grid[0][8] = new Chess(ckind.ROOKS);
		grid[2][1] = new Chess(ckind.CANNONS);
		grid[2][7] = new Chess(ckind.CANNONS);
		for (int i = 0; i <= 8; i += 2)
		{
			grid[3][i] = new Chess(ckind.PAWNS);
		}
		//设置棋盘格坐标与属性
		for (int j = 0; j <= 8; j++)
		{
			grid[0][j]->set_xy(PERLENGTH*(j + 1), PERLENGTH);
			grid[0][j]->setPlayer(ckind.PLAYER_1);
		}
		grid[2][1]->set_xy(2 * PERLENGTH, 3 * PERLENGTH);
		grid[2][7]->set_xy(8 * PERLENGTH, 3 * PERLENGTH);
		grid[2][1]->setPlayer(ckind.PLAYER_1);
		grid[2][7]->setPlayer(ckind.PLAYER_1);
		for (int i = 0; i <= 8; i += 2)
		{
			grid[3][i]->set_xy((i + 1)* PERLENGTH, 4 * PERLENGTH);
			grid[3][i]->setPlayer(ckind.PLAYER_1);
		}
		//我方
		grid[9][0] = new Chess(ckind.ROOKS);
		grid[9][1] = new Chess(ckind.KNIGHTS);
		grid[9][2] = new Chess(ckind.MINISTERS);
		grid[9][3] = new Chess(ckind.GUARDS);
		grid[9][4] = new Chess(ckind.GENERALS);
		grid[9][5] = new Chess(ckind.GUARDS);
		grid[9][6] = new Chess(ckind.MINISTERS);
		grid[9][7] = new Chess(ckind.KNIGHTS);
		grid[9][8] = new Chess(ckind.ROOKS);
		grid[7][1] = new Chess(ckind.CANNONS);
		grid[7][7] = new Chess(ckind.CANNONS);
		for (int i = 0; i <= 8; i += 2)
		{
			grid[6][i] = new Chess(ckind.SOLDIERS);
		}
		//设置棋盘格坐标与属性
		for (int j = 0; j <= 8; j++)
		{
			grid[9][j]->set_xy(PERLENGTH*(j + 1), 10 * PERLENGTH);
			grid[9][j]->setPlayer(ckind.PLAYER_2);
		}
		grid[7][1]->set_xy(2 * PERLENGTH, 8 * PERLENGTH);
		grid[7][7]->set_xy(8 * PERLENGTH, 8 * PERLENGTH);
		grid[7][1]->setPlayer(ckind.PLAYER_2);
		grid[7][7]->setPlayer(ckind.PLAYER_2);
		for (int i = 0; i <= 8; i += 2)
		{
			grid[6][i]->set_xy((i + 1)* PERLENGTH, 7 * PERLENGTH);
			grid[6][i]->setPlayer(ckind.PLAYER_2);
		}
	}
	//创建窗口
	void CreateMap()
	{
		initgraph(10 * PERLENGTH, 11 * PERLENGTH);//单位宽度
		setbkcolor(WHITE);
		cleardevice();
	}

	//重绘棋盘
	void repaint()
	{
		setbkcolor(WHITE);
		cleardevice();
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
		line(PERLENGTH - 5, PERLENGTH - 5, PERLENGTH * 9 + 5, PERLENGTH - 5);
		line(PERLENGTH - 5, PERLENGTH - 5, PERLENGTH - 5,PERLENGTH*10+5);
		line(PERLENGTH - 5, PERLENGTH * 10 + 5, PERLENGTH * 9 + 5, PERLENGTH * 10 + 5);
		line(PERLENGTH * 9 + 5, PERLENGTH * 10 + 5, PERLENGTH * 9 + 5, PERLENGTH - 5);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
		for (int i = 1; i <= 10; i++)
		{
			line(PERLENGTH, i*PERLENGTH, 9 * PERLENGTH, i*PERLENGTH);
		}
		for (int i = 1; i <= 9; i++)
		{
			line(i*PERLENGTH, PERLENGTH, i* PERLENGTH, 5 * PERLENGTH);
			line(i*PERLENGTH, 6 * PERLENGTH, i* PERLENGTH, 10 * PERLENGTH);
		}
		line(PERLENGTH, 5 * PERLENGTH, PERLENGTH, 6 * PERLENGTH);
		line(9 * PERLENGTH, 5 * PERLENGTH, 9 * PERLENGTH, 6 * PERLENGTH);
		line(4 * PERLENGTH, PERLENGTH, 6 * PERLENGTH, 3 * PERLENGTH);
		line(4 * PERLENGTH, 3 * PERLENGTH, 6 * PERLENGTH, PERLENGTH);
		line(4 * PERLENGTH, 8 * PERLENGTH, 6 * PERLENGTH, 10 * PERLENGTH);
		line(4 * PERLENGTH, 10 * PERLENGTH, 6 * PERLENGTH, 8 * PERLENGTH);
		settextcolor(RED);
		settextstyle(PERLENGTH * 2 / 3, 0, _T("楷体"));
		RECT r = { 2 * PERLENGTH, 5 * PERLENGTH, 4 * PERLENGTH, 6 * PERLENGTH };
		drawtext(_T("楚河"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		r = { 6 * PERLENGTH, 5 * PERLENGTH, 8 * PERLENGTH, 6 * PERLENGTH };
		drawtext(_T("汉界"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		for (int i = 3; i <= 7; i += 2)
		{
			//敌方
			line(i * PERLENGTH - 3, 4 * PERLENGTH - 3, i * PERLENGTH - 3, 4 * PERLENGTH - 10);
			line(i * PERLENGTH - 3, 4 * PERLENGTH - 3, i * PERLENGTH - 10, 4 * PERLENGTH - 3);
			line(i * PERLENGTH - 3, 4 * PERLENGTH + 3, i * PERLENGTH - 3, 4 * PERLENGTH + 10);
			line(i * PERLENGTH - 3, 4 * PERLENGTH + 3, i * PERLENGTH - 10, 4 * PERLENGTH + 3);
			line(i * PERLENGTH + 3, 4 * PERLENGTH - 3, i * PERLENGTH + 3, 4 * PERLENGTH - 10);
			line(i * PERLENGTH + 3, 4 * PERLENGTH - 3, i * PERLENGTH + 10, 4 * PERLENGTH - 3);
			line(i * PERLENGTH + 3, 4 * PERLENGTH + 3, i * PERLENGTH + 3, 4 * PERLENGTH + 10);
			line(i * PERLENGTH + 3, 4 * PERLENGTH + 3, i * PERLENGTH + 10, 4 * PERLENGTH + 3);
			//我方
			line(i * PERLENGTH - 3, 7 * PERLENGTH - 3, i * PERLENGTH - 3, 7 * PERLENGTH - 10);
			line(i * PERLENGTH - 3, 7 * PERLENGTH - 3, i * PERLENGTH - 10, 7 * PERLENGTH - 3);
			line(i * PERLENGTH - 3, 7 * PERLENGTH + 3, i * PERLENGTH - 3, 7 * PERLENGTH + 10);
			line(i * PERLENGTH - 3, 7 * PERLENGTH + 3, i * PERLENGTH - 10, 7 * PERLENGTH + 3);
			line(i * PERLENGTH + 3, 7 * PERLENGTH - 3, i * PERLENGTH + 3, 7 * PERLENGTH - 10);
			line(i * PERLENGTH + 3, 7 * PERLENGTH - 3, i * PERLENGTH + 10, 7 * PERLENGTH - 3);
			line(i * PERLENGTH + 3, 7 * PERLENGTH + 3, i * PERLENGTH + 3, 7 * PERLENGTH + 10);
			line(i * PERLENGTH + 3, 7 * PERLENGTH + 3, i * PERLENGTH + 10, 7 * PERLENGTH + 3);
		}
		for (int i = 2; i <= 8; i += 6)
			for (int j = 3; j <= 8; j += 5)
			{
			line(i * PERLENGTH - 3, j * PERLENGTH - 3, i * PERLENGTH - 3, j * PERLENGTH - 10);
			line(i * PERLENGTH - 3, j * PERLENGTH - 3, i * PERLENGTH - 10, j * PERLENGTH - 3);
			line(i * PERLENGTH - 3, j * PERLENGTH + 3, i * PERLENGTH - 3, j * PERLENGTH + 10);
			line(i * PERLENGTH - 3, j * PERLENGTH + 3, i * PERLENGTH - 10, j * PERLENGTH + 3);
			line(i * PERLENGTH + 3, j * PERLENGTH - 3, i * PERLENGTH + 3, j * PERLENGTH - 10);
			line(i * PERLENGTH + 3, j * PERLENGTH - 3, i * PERLENGTH + 10, j * PERLENGTH - 3);
			line(i * PERLENGTH + 3, j * PERLENGTH + 3, i * PERLENGTH + 3, j * PERLENGTH + 10);
			line(i * PERLENGTH + 3, j * PERLENGTH + 3, i * PERLENGTH + 10, j * PERLENGTH + 3);
			}
		for (int j = 4; j <= 7; j += 3)
		{
			line(PERLENGTH + 3, j * PERLENGTH - 3, PERLENGTH + 3, j * PERLENGTH - 10);
			line(PERLENGTH + 3, j * PERLENGTH - 3, PERLENGTH + 10, j * PERLENGTH - 3);
			line(PERLENGTH + 3, j * PERLENGTH + 3, PERLENGTH + 3, j * PERLENGTH + 10);
			line(PERLENGTH + 3, j * PERLENGTH + 3, PERLENGTH + 10, j * PERLENGTH + 3);
		}
		for (int j = 4; j <= 7; j += 3)
		{
			line(9 * PERLENGTH - 3, j * PERLENGTH - 3, 9 * PERLENGTH - 3, j * PERLENGTH - 10);
			line(9 * PERLENGTH - 3, j * PERLENGTH - 3, 9 * PERLENGTH - 10, j * PERLENGTH - 3);
			line(9 * PERLENGTH - 3, j * PERLENGTH + 3, 9 * PERLENGTH - 3, j * PERLENGTH + 10);
			line(9 * PERLENGTH - 3, j * PERLENGTH + 3, 9 * PERLENGTH - 10, j * PERLENGTH + 3);
		}
		for (int i = 0; i <10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (grid[i][j] != NULL)
				{
					pair<int, int>p = grid[i][j]->get_xy();
					int x = p.first; int y = p.second;
					setfillcolor(RGB(200, 220, 250));
					setbkcolor(RGB(200, 220, 250));
					fillcircle(x, y, 27);
					RECT r = { x - 18, y - 18, x + 18, y + 18 };
					if (grid[i][j]->getPlayer() == *_T("BLACK"))
					{
						settextcolor(BLACK);
					}
					else
						settextcolor(RED);
					drawtext(grid[i][j]->get_name(), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
		}
	}

	//进入消息循环
	void messagewhile()
	{
		MOUSEMSG msg;
		bool isReady = false;
		pair<int, int>p;
		pair<int, int>readyChess;
		int next = 1;//1表示红方下棋
		while (1)
		{
			msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (isChoose(msg.x, msg.y))
				{
					p = translate(msg.x, msg.y);//将所选坐标转化为棋盘格索引
					if (isReady)//如果已经有棋子被激活
					{
						if (p.first == readyChess.first&&p.second == readyChess.second)//激活之后选的是自己；
						{
							isReady = false;
							repaint();
							break;
						}
						else if (grid[p.first][p.second] == NULL)//激活之后选了一个空位置
						{
							if (!isTrueWay(grid[readyChess.first][readyChess.second]->get_name(), readyChess.first, readyChess.second, p.first, p.second))break;
							grid[p.first][p.second] = grid[readyChess.first][readyChess.second];
							pair<int, int>change = compute_xy(p.first, p.second);
							grid[p.first][p.second]->set_xy(change.first, change.second);
							grid[readyChess.first][readyChess.second] = NULL;
							isReady = false;
							repaint();
							next = !next;
							break;
						}
						else if (grid[p.first][p.second] != NULL)//激活之后，所选位置已有棋子
						{
							if (grid[p.first][p.second]->getPlayer() == grid[readyChess.first][readyChess.second]->getPlayer())//该位置是己方棋子
							{
								repaint();
								pair<int, int>xy = compute_xy(p.first, p.second);//根据索引计算真实坐标
								grid[p.first][p.second]->drowReady(xy.first, xy.second);//将棋子改为激活状态
								readyChess.first = p.first;//记录被激活棋子的棋盘格索引
								readyChess.second = p.second;
								isReady = true;
								break;
							}
							if (grid[p.first][p.second]->getPlayer() != grid[readyChess.first][readyChess.second]->getPlayer())//该位置是敌方棋子
							{
								if (!isTrueWay(grid[readyChess.first][readyChess.second]->get_name(), readyChess.first, readyChess.second, p.first, p.second))break;
								grid[p.first][p.second] = grid[readyChess.first][readyChess.second];
								pair<int, int>change = compute_xy(p.first, p.second);
								grid[p.first][p.second]->set_xy(change.first, change.second);
								grid[readyChess.first][readyChess.second] = NULL;
								isReady = false;
								repaint();
								next = !next;
								break;
							}
						}
					}
					else//如果没有棋子被激活
					{
						if (!haveChess(p.first, p.second))break;//如果所选位置没有棋子
						else
						{
							if (next && grid[p.first][p.second]->getPlayer() == *_T("BLACK"))break;
							if (!next && grid[p.first][p.second]->getPlayer() == *_T("RED"))break;
							pair<int, int>xy = compute_xy(p.first, p.second);//根据索引计算真实坐标
							grid[p.first][p.second]->drowReady(xy.first, xy.second);//将棋子改为激活状态
							readyChess.first = p.first;//记录被激活棋子的棋盘格索引
							readyChess.second = p.second;
							isReady = true;
						}
					}
				}
				break;
			}
		}
	}

	//棋盘格索引转化为真实坐标
	pair<int, int>compute_xy(int i, int j)
	{
		pair<int, int>p((j + 1)*PERLENGTH, (i + 1)*PERLENGTH);
		return p;
	}

	//判断是否选中棋盘格
	bool isChoose(int x, int y)
	{
		if (x > PERLENGTH / 2 && x<(10 * PERLENGTH - PERLENGTH / 2) && y>PERLENGTH / 2 && y < (11 * PERLENGTH - PERLENGTH / 2))
			return true;
		else
			return false;
	}

	//若选中棋盘格，将所选中的坐标转化为棋盘格索引
	pair<int, int>translate(int x, int y)
	{
		int X = x / PERLENGTH;
		int Y = y / PERLENGTH;
		int mx = x%PERLENGTH;
		int my = y%PERLENGTH;
		if (mx < PERLENGTH / 2)X--;
		if (my < PERLENGTH / 2)Y--;
		pair<int, int>p(Y, X);
		return p;
	}

	//判断所选棋盘格是否有棋子
	bool haveChess(int i, int j)
	{
		if (grid[i][j] == NULL)
			return false;
		else return true;
	}
	//判断走法是否正确
	bool isTrueWay(WCHAR name, int row, int col, int _row, int _col)
	{
		//车的限制
		if (name == ckind.ROOKS)
		{
			if (row != _row&&col != _col)return false;
			if (row == row)
			{
				if (col > _col)
				{
					for (int i = _col + 1; i < col; i++)
					{
						if (grid[row][i] != NULL)
							return false;
					}

				}
				else
				{
					for (int i = col + 1; i < _col; i++)
					{
						if (grid[row][i] != NULL)
							return false;
					}

				}
			}
			if (col == _col)
			{
				if (row > _row)
				{
					for (int i = _row + 1; i < row; i++)
					{
						if (grid[i][col] != NULL)
							return false;
					}
				}
				else
				{
					for (int i = row + 1; i < _row; i++)
					{
						if (grid[i][col] != NULL)
							return false;
					}

				}
			}
		}
		//马的限制
		else if (name == ckind.KNIGHTS)
		{
			if ((col - _col)*(col - _col) + (row - _row)*(row - _row) != 5)return false;
			//row-1,col//row+1,col//row,col-1//row,col+1//四个位置中的一个
			else if ((row - 1 - _row) *(row - 1 - _row) + (col - _col)*(col - _col) == 2)
			{
				if (grid[row - 1][col] != NULL)return false;
			}
			else if ((row + 1 - _row) *(row + 1 - _row) + (col - _col)*(col - _col) == 2)
			{
				if (grid[row + 1][col] != NULL)return false;
			}
			else if ((row - _row)*(row - _row) + (col - 1 - _col)*(col - 1 - _col) == 2)
			{
				if (grid[row][col - 1] != NULL)return false;
			}
			else if ((row - _row)*(row - _row) + (col + 1 - _col)*(col + 1 - _col) == 2)
			{
				if (grid[row][col + 1] != NULL)return false;
			}
		}
		//象的限制
		else if (name == ckind.ELEPHANTS)
		{
			if (_row > 4)return false;
			else if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 8)return false;
			else if (grid[(row + _row) / 2][(col + _col) / 2] != NULL)return false;
		}

		//相的限制
		else if (name == ckind.MINISTERS)
		{
			if (_row < 5)return false;
			else if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 8)return false;
			else if (grid[(row + _row) / 2][(col + _col) / 2] != NULL)return false;
		}

		//士的限制
		else if (name == ckind.MANDARINS)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 2)return false;
			else if (_row > 2 || _col < 3 || _col>5)return false;
		}

		//仕的限制
		else if (name == ckind.GUARDS)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 2)return false;
			else if (_row <7 || _col < 3 || _col>5)return false;
		}

		//将的限制
		else if (name == ckind.KING)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 1)return false;
			else if (_row > 2 || _col < 3 || _col>5)return false;
		}
		//帅的限制
		else if (name == ckind.GENERALS)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 1)return false;
			else if (_row < 7 || _col < 3 || _col>5)return false;
		}

		//炮的限制
		else if (name == ckind.CANNONS)
		{
			int t;
			if (row != _row&&col != _col)return false;
			if (row == _row)
			{
				int t = 0;
				if (col > _col)
				{
					for (int i = _col + 1; i < col; i++)
					{
						if (grid[row][i] != NULL)++t;
					}

					if (grid[_row][_col] == NULL&&t != 0)return false;
					if (grid[_row][_col] != NULL&&t != 1)return false;
				}
				else
				{
					for (int i = col + 1; i < _col; i++)
					{
						if (grid[row][i] != NULL)++t;
					}
					cout << t;
					if (grid[_row][_col] == NULL&&t != 0)return false;
					if (grid[_row][_col] != NULL&&t != 1)return false;
				}
			}
			if (col == _col)
			{
				t = 0;
				if (row > _row)
				{
					for (int i = _row + 1; i < row; i++)
					{
						if (grid[i][col] != NULL)++t;
					}
					cout << t << endl;
					if (grid[_row][_col] == NULL&&t != 0)return false;
					if (grid[_row][_col] != NULL&&t != 1)return false;
				}
				else
				{
					for (int i = row + 1; i < _row; i++)
					{
						if (grid[i][col] != NULL)++t;
					}
					cout << t << endl;
					if (grid[_row][_col] == NULL&&t != 0)return false;
					if (grid[_row][_col] != NULL&&t != 1)return false;
				}
			}
		}

		//卒的限制
		else if (name == ckind.PAWNS)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 1)return false;
			else if (row < 5)
			{
				if (_row <= row)
					return false;
			}
			else if (row >= 5)
			{
				if (_row < row)
					return false;
			}
		}
		//兵的限制
		else if (name == ckind.SOLDIERS)
		{
			if ((row - _row)*(row - _row) + (col - _col)*(col - _col) != 1)return false;
			else if (row > 4)
			{
				if (_row >= row)
					return false;
			}
			else if (row <= 4)
			{
				if (_row > row)
					return false;
			}
		}
		return true;
	}
};
void main()
{
	PaneBoard paneBoard;
	paneBoard.startGame();
	system("pause");
}