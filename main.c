#include "mySimpleComputer.h"

#include <stdio.h>

main()
{
	int val;
	int nval;
	int bval;
	sc_memoryInit();
	printf("\n");
	sc_regInit();
	printf("\n");
	sc_memorySet(10, 45);
	int cell;
	sc_memoryGet(10, &cell);
	printf("\n memory cell value = %d\n", cell);
	sc_regGet(OUT_OF_MEM, &val);
	printf("\n flag value - %d\n", val);
	sc_memorySet(1000, 45);
	printf("\n");
	sc_regGet(1, &val);
	printf("\n flag value - %d\n", val);
	sc_memorySave("save.bin");
	printf("\n");
	sc_memoryLoad("save.bin");
	printf("\n");

	/*sc_regSet(OUT_OF_MEM, 1);
	
	sc_regGet(1, &val);
	printf("\n flag value - %d\n", val);*/

	sc_commandEncode(0x21, 0x28, &nval);
	sc_regGet(3, &val);
	printf("\n flag value - %d\n", val);
	int command;
	int oper;
	sc_commandDecode(nval, &command, &oper);
	sc_regGet(3, &val);
	printf("\n flag value - %d\n", val);
	sc_commandEncode(500, 0x29, &bval);
	sc_regGet(3, &val);
	printf("\n flag value - %d\n", val);
	printf("\n command - %x \n", command);
	printf("\n operand - %x \n", oper);
}
