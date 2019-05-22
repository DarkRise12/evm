#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>

main()
{
	unsigned int x = 0, y = 0, d, R = 2, C = 1;
	unsigned int *row = &x, *col = &y;
	int cell;
	/*sc_memoryInit();
	printf("\n");
	sc_regInit();
	printf("\n");
	sc_memorySet(10, 45);
	int cell;
	sc_memoryGet(10, &cell);
	printf("\n memory cell value = %d\n", cell);

	sc_memorySave("save.bin");
	printf("\n");
	sc_memoryLoad("save.bin");
	printf("\n");

	sc_regSet(OUT_OF_MEM, 1);
	int val;
	sc_regGet(1, &val);
	printf("\n flag value - %d\n", val);

	sc_commandEncode(0x56, 96, &val);
	int command;
	int oper;
	sc_commandDecode(val, &command, &oper);
	printf("\n command - %x \n", command);
	printf("\n operand - %x \n", oper);*/
	
	mt_clrscr();
	d = mt_getscreensize(row, col);	
    mt_gotoXY(5, 10);
    mt_setfgcolor(red);
    mt_setgbcolor(black);
    write(1, "Nikita", 6);
    mt_gotoXY(6, 8);
    mt_setfgcolor(green);
    mt_setgbcolor(gray);
    write(1, "IP-713", 6);
    mt_gotoXY(10, 1);
    mt_setfgcolor(9);
    mt_setgbcolor(9);
    
}
