#include "2048.h"

/*
     64     32     16      8

     32     16      8      4

     16      8      4      2

      8      4      2      1

You die!
press <y> to play, <n> to quit

*/

int main()
{
	system("clear");
	init();
	
	show();
	
	char ch;

	
	while((ch = getch_from_terminal()) != VK_QUIT)
	//while((ch = getchar()) != VK_QUIT)
	{
		switch(ch)
		{
			case VK_UP:
				handle(VK_UP);
				show();
				break;
				
			case VK_DOWN:
				handle(VK_DOWN);
				show();
				break;
				
			case VK_LEFT:
				handle(VK_LEFT);
				show();
				break;
				
			case VK_RIGHT:
				handle(VK_RIGHT);
				show();
				break;
				
			case 'q':
				exit(1);
				break;
				
			default:
				printf("<w><s><a><d>\n");
				break;
		}
	}
	
	
	return 0;
}