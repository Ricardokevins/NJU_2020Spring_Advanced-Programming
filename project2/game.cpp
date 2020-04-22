#include"game.h"

# define row 30
# define len 80

int Game::run()
{
    display();
}

int Game::display()
{
    //modeset(100,50);
    _setmode(_fileno(stdout), _O_U16TEXT);//让控制台启用Unicode 16
    //L告诉编译器使用两个字节的Unicode字符集
    for(int i(0);i<row;i++)
    {
        for(int j(0);j<len;j++)
        {
            if(j==0||j==len-1)
            {
                wcout<<  L"\u2551";
                if(j==len-1)
                {
                    wcout<<endl;
                }
            }
            else
            {
                if(i==0||i==row-1)
                {
                    wcout<<  L"\u2550";
                }
                else
                {
                    wcout<<" ";
                }
            }
        }
    }
	return 0;
}

