#include "mySimpleComputer.h"

#include <stdio.h>

main()
{
	sc_memoryInit();
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
	printf("\n operand - %x \n", oper);
}
