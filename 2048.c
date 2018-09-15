#include "2048.h"


int init()
{
	int id;
	for(id=0; id<16; id++)
	{
		table[id]   = 0;
	}
	table[random_position()] = 1;
	
	return 0;
}

void show()
{
	system("clear");
	printf("\n\n");
	int ix, iz, id;
	char ch;
	
	for(ix=0; ix<4; ix++)
	{
		for(iz=0; iz<4; iz++)
		{
			id = iz*4 + ix;
			
			printf("%7d", table[id]);
		}
		printf("\n\n");
	}
	if(-1 == check_alive())
	{
		printf("You die!\n");
		printf("press <y> to play, <n> to quit\n");
		
switch_ch:
		ch = getchar();

		switch(ch)
		{
			case 'y':
				init();
				show();
				break;
			case 'n':
				printf("Goodbye! Have a good day!\n");
				exit(1);
				break;
			default:
				goto switch_ch;
				break;
		}
		
		
	}
}

int random_position()
{
	srand( (unsigned)time( NULL ) ); 
	int id;
	if(0 == check_zero())
	{
		while(1)
		{
			id = rand()%16;
			if(table[id] == 0)
			{
				return id;
			}
		}
	}
}

int check_zero()
{
	int id, i, j, ij;
	for(id=0; id<16; id++)
	{
		if(table[id] != 0)
		{
			if(id == 15)
			{
				return -1;
			}
			continue;
		}
		else
		{
			return 0;
		}
	}
}

int check_alive()
{
	int id, ix, iz;
	
	
	if(table[0] == table[1] ||
	   table[0] == table[4] ||
	   table[3] == table[2] ||
	   table[3] == table[7] ||
	   table[12] == table[13] ||
	   table[12] == table[8]  ||
	   table[15] == table[14] ||
	   table[15] == table[11] ||
	   table[2] == table[3] ||
	   table[4] == table[8] ||
	   table[7] == table[11] ||
	   table[13] == table[14])
	{
		return 0;
	}
	
	for(ix=0; ix<4; ix++)
	{
		for(iz=0; iz<4; iz++)
		{
			id = ix*4+iz;
			if(table[id] == 0)
			{
				return 0;
			}
			if(ix >= 1 && ix <= 2 && iz >=1 && iz <= 2)
			{
				if(table[id] == table[id-1])
				{
					return 0;
				}
				if(table[id] == table[id+1])
				{
					return 0;
				}
				if(table[id] == table[id-4])
				{
					return 0;
				}
				if(table[id] == table[id+4])
				{
					return 0;
				}
			}
			
		}
	}
	return -1;
}

void handle(char VK)
{
	int ix, iz, i, id;
	
	switch(VK)
	{
		case VK_UP:
			for(ix=0; ix<4; ix++)
			{
loop_VK_UP_1:
				for(iz=0; iz<4; iz++)
				{
					if(table[ix*4+iz] == 0)
					{
						for(i=iz; i<4; i++)
						{
							if(i==3)
							{
								table[ix*4+i] = 0;
							}
							else
							{
								table[ix*4+i] = table[ix*4+i+1];
							}
						}
					}
				}
				for(iz=0; iz<4; iz++)
				{
					if(table[ix*4+iz] != 0)
					{
						for(i=0; i<iz; i++)
						{
							if(table[ix*4+i] == 0)
							{
								goto loop_VK_UP_1;
							}
						}
					}
				}
loop_VK_UP_2:
				for(iz=0; iz<3; iz++)
				{
					if(table[ix*4+iz] == table[ix*4+iz+1])
					{
						table[ix*4+iz] 	= table[ix*4+iz]	+ table[ix*4+iz+1];
						for(i=iz+1; i<4; i++)
						{
							if(i==3)
							{
								table[ix*4+i] = 0;
							}
							else
							{
								table[ix*4+i] = table[ix*4+i+1];
							}
						}
					}
				}
				for(iz=0; iz<3; iz++)
				{
					if(table[ix*4+iz] != 0 && table[ix*4+iz] == table[ix*4+iz+1])
					{
						goto loop_VK_UP_2;
					}
				}
			}
			table[random_position()] = 1;
			break;
			
		case VK_DOWN:
			for(ix=0; ix<4; ix++)
			{
loop_VK_DOWN_1:
				for(iz=3; iz>=0; iz--)
				{
					if(table[ix*4+iz] == 0)
					{
						for(i=iz; i>=0; i--)
						{
							if(i==0)
							{
								table[ix*4+i] = 0;
							}
							else
							{
								table[ix*4+i] = table[ix*4+i-1];
							}
						}
					}
				}
				for(iz=3; iz>=0; iz--)
				{
					if(table[ix*4+iz] != 0)
					{
						for(i=3; i>iz; i--)
						{
							if(table[ix*4+i] == 0)
							{
								goto loop_VK_DOWN_1;
							}
						}
					}
				}
loop_VK_DOWN_2:
				for(iz=3; iz>=1; iz--)
				{
					if(table[ix*4+iz] == table[ix*4+iz-1])
					{
						table[ix*4+iz] 	= table[ix*4+iz]	+ table[ix*4+iz-1];
						for(i=iz-1; i>=0; i--)
						{
							if(i==0)
							{
								table[ix*4+i] = 0;
							}
							else
							{
								table[ix*4+i] = table[ix*4+i-1];
							}
						}
					}
				}
				for(iz=3; iz>=1; iz--)
				{
					if(table[ix*4+iz] != 0 && table[ix*4+iz] == table[ix*4+iz-1])
					{
						goto loop_VK_DOWN_2;
					}
				}
			}
			table[random_position()] = 1;
			break;
			
		case VK_LEFT:
			for(iz=0; iz<4; iz++)
			{
loop_VK_LEFT_1:
				for(ix=0; ix<4; ix++)
				{
					if(table[ix*4+iz] == 0)
					{
						for(i=ix; i<4; i++)
						{
							if(i==3)
							{
								table[i*4+iz] = 0;
							}
							else
							{
								table[i*4+iz] = table[(i+1)*4+iz];
							}
						}
					}
				}
				for(ix=0; ix<4; ix++)
				{
					if(table[ix*4+iz] != 0)
					{
						for(i=0; i<ix; i++)
						{
							if(table[i*4+iz] == 0)
							{
								goto loop_VK_LEFT_1;
							}
						}
					}
				}
loop_VK_LEFT_2:
				for(ix=0; ix<3; ix++)
				{
					if(table[ix*4+iz] == table[(ix+1)*4+iz])
					{
						table[ix*4+iz] 	= table[ix*4+iz]	+ table[(ix+1)*4+iz];
						for(i=ix+1; i<4; i++)
						{
							if(i==3)
							{
								table[i*4+iz] = 0;
							}
							else
							{
								table[i*4+iz] = table[(i+1)*4+iz];
							}
						}
					}
				}
				for(ix=0; ix<3; ix++)
				{
					if(table[ix*4+iz] != 0 && table[ix*4+iz] == table[(ix+1)*4+iz])
					{
						goto loop_VK_LEFT_2;
					}
				}
			}
			table[random_position()] = 1;
			break;
			
		case VK_RIGHT:
			for(iz=0; iz<4; iz++)
			{
loop_VK_RIGHT_1:
				for(ix=3; ix>=0; ix--)
				{
					if(table[iz+ix*4] == 0)
					{
						for(i=ix; i>=0; i--)
						{
							if(i==0)
							{
								table[iz+i*4] = 0;
							}
							else
							{
								table[iz+i*4] = table[iz+(i-1)*4];
							}
						}
					}
				}
				for(ix=3; ix>=0; ix--)
				{
					if(table[iz+ix*4] != 0)
					{
						for(i=3; i>ix; i--)
						{
							if(table[iz+i*4] == 0)
							{
								goto loop_VK_RIGHT_1;
							}
						}
					}
				}
loop_VK_RIGHT_2:
				for(ix=3; ix>=1; ix--)
				{
					if(table[iz+ix*4] == table[iz+(ix-1)*4])
					{
						table[iz+ix*4] 	= table[iz+ix*4]	+ table[iz+(ix-1)*4];
						for(i=ix-1; i>=0; i--)
						{
							if(i==0)
							{
								table[iz+i*4] = 0;
							}
							else
							{
								table[iz+i*4] = table[iz+(i-1)*4];
							}
						}
					}
				}
				for(ix=3; ix>=1; ix--)
				{
					if(table[iz+ix*4] != 0 && table[iz+ix*4] == table[iz+(ix-1)*4])
					{
						goto loop_VK_RIGHT_2;
					}
				}
			}
			table[random_position()] = 1;
			break;
			
		default:
			break;
	}
}

char getch_from_terminal()
/*https://blog.csdn.net/Timsley/article/details/51424068*/
{
	FILE *input;
    FILE *output;
    struct termios initial_settings, new_settings;
    int inputString;

    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");
    if(!input || !output)
    {
        fprintf(stderr, "Unable to open /dev/tty\n");
        exit(1);
    }

    tcgetattr(fileno(input), &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_lflag &= ~ISIG;

    if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0)
    {
        fprintf(stderr, "Could not set attributes\n");
    }

    //while(inputString != 'q')
    //{
        //do
        //{
            inputString = fgetc(input);
        //}while(inputString == '\n' || inputString == '\r');
        //return (char )inputString;
    //}

    tcsetattr(fileno(input), TCSANOW, &initial_settings);
	
	return (char)inputString;
}