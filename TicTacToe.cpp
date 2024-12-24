#include<iostream>
#include <vector>
#include <optional>
#include <set>
#include <map>

#include <windows.h>
#include <conio.h>

typedef std::vector<std::vector<int>> board;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(short x, short y){
	SetConsoleCursorPosition(console, {x,y});
    return;
}


class Board
{
private:
    board brd;
public:
    Board(/* args */)
    {
        brd = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
    }
    void Get(int x, int y){}
    bool Set(int x, int y, int player){ return false;}
    void Undo(int x, int y){}
    void Display()
    {
        for (std::vector i : brd)
        {
            std::cout<<"\n---------------------\n|";
            for (int j : i)
            {
                switch (j)
                {
                    case -1:  std::cout << " O |"; break;
                    case +1:  std::cout << " X |"; break;
                    case 0:  std::cout << "   |"; break;
                }
            }
        }
        std::cout << Check().value_or('H');
    }
    std::optional<int> Check()
    {
        std::set<int> row, col, m_Dia, s_Dia;
        for (int i = 0; i < 3; i++)
        {
            row.clear();    col.clear();
            for (int j = 0; j < 3; j++)
            {
                row.insert(brd[i][j]);
                col.insert(brd[j][i]);
            }
            if (row.size() == 1 && row.count(0) == 0)
                return *row.begin();
            if (col.size() == 1 && col.count(0) == 0)
                return *col.begin();
            
            m_Dia.insert(brd[i][i]);
            s_Dia.insert(brd[i][2-i]);
        }
        if (m_Dia.size() == 1 && m_Dia.count(0) == 0)
            return *m_Dia.begin();
        if (s_Dia.size() == 1 && s_Dia.count(0) == 0)
            return *s_Dia.begin();
        
        return std::nullopt;
    }

    ~Board(){}
};
class Game
{
    private:
        Board brd;
        int Player;

    public:
        Game()
        {
            brd = Board();
        }
        void play();
        char Get_Input()
        {
            while(true)
            {
                if(kbhit())
                {
                    GetKeyState(VK_NUMPAD0);
                }
            }
        }
}
;


int main() {

    std::set<int> my_set;
    my_set.emplace(5);
    my_set.emplace(4);
    my_set.emplace(1);
    my_set.emplace(5);
    my_set.emplace(1);
    std::cout<< my_set.count(5);
    std::cout<< my_set.size();
    for(int val : my_set) {
        std::cout << val << " ";
    }
    Board b = Board();
    b.Display();

    return 0;
}