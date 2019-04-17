#include "mySimpleComputer.h"

int sc_memoryInit()
{
	int i = 0;
	for(i = 0; i < SIZE; i++)
	{
		sc_memory[i] = 0;
	}
	printf("memory initialized");
	return 0;
}

int sc_memorySet(int address, int value)
{
	if(address < 0 || address >= SIZE)
	{
		sc_regSet(OUT_OF_MEM, 1);
		errorHandler(1);
	}
	else
	{
		sc_memory[address] = value;
	}
	printf("memory setled");
	return 0;
}

int sc_memoryGet(int address, int *value)
{
	if(address < 0 || address >= SIZE)
	{
		sc_regSet(OUT_OF_MEM, 1);
		errorHandler(1);
	}
	else
	{
		*value = sc_memory[address];
	}
	return 0;
}

int sc_memorySave(char *filename)
{
	FILE *file = fopen(filename, "wb");
	if(!file)
	{
		errorHandler(2);
	}
	else
	{
		fwrite(ram, sizeof(int), SIZE, file);
	}
	fclose(file);
	printf("memory saved");
	return 0;
}

int sc_memoryLoad(char *filename)
{
	FILE *file = fopen(filename, "rb");
	if(!file)
	{
		errorHandler(3);
	}
	else
	{
		fread(ram, sizeof(int), SIZE, file);
	}
	fclose(file);
	printf("memory loaded");
	return 0;
}

int sc_regInit()
{
	sc_register = 0x0;
	printf("reg initialized")
	return 0;
}

int sc_regSet(int reg, int value)
{
    if ((reg >= 0) && (reg <= 6))
    {
		if (value == 0)
		{
			sc_register &= ~reg;
			return 0;
		}
		else if (value == 1)
		{
			sc_register |= reg;
			return 0;
		}
		else
		{
			errorHandler(4);
		}
	}
	else
	{
		errorHandler(5);
	}
	printf("reg setled");
	return 0;
}

int sc_regGet(int reg, int *value)
{
    if ((reg >= 0x01) && (reg <= 0x10))
    {
		*value = sc_register >> (reg - 1) & 0x1;
    }
    else
    {
		errorHandler(5);
	}
	
        return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
    //if (!(command == 0xa) || !(command == 0xb) || !(command == 0x15) || !(command == 0x1e) || operand < 0 || operand > 127 || !(command == 0x1f) || !(command == 0x20) || !(command == 0x21))
	if (!((command == 0xa) || (command == 0xb) || (command == 0x15) || (command == 0x1e) || (command == 0x1f) || (command == 0x20) || (command == 0x21)) || operand < 0 || operand > 127 )
    {
		sc_regSet(COMMAND_ERROR, 1);
        errorHandler(6);
    }
    int temp = 0x00;
    temp |= command;
    temp <<= 7;
    temp |= operand;
    *value = temp;
    return 0;
}

int sc_commandDecode(int value, int *command, int *operand)
{
    if (value >> 14 != 0x0)
    {
        sc_regSet(COMMAND_ERROR, 1);
        errorHandler(6);
    }
    else if (!((*command == 0xa) || (*command == 0xb) || (*command == 0x15) || (*command == 0x1e) || (*command == 0x1f) || (*command == 0x20) || (*command == 0x21)) || *operand < 0 || *operand > 127 )
    {
		sc_regSet(COMMAND_ERROR, 1);
        errorHandler(6);
    }
	else
	{
		*operand = (int) (value & 0x7F);
   		*command = (int) (value >> 7);
	}
    return 0;
}