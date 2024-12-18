#include<table.h>

OpcodeTables::OpcodeTables()
{
	MRI["AND"] = {"0", "8"};
	MRI["ADD"] = {"1", "9"};
	MRI["LDA"] = {"3", "A"};
	MRI["STA"] = {"4", "B"};
	MRI["BUN"] = {"5", "C"};
	MRI["BSA"] = {"6", "D"};
	MRI["ISZ"] = {"7", "F"};

	NON_MRI["CLA"] = 0x7800;
	NON_MRI["CLE"] = 0x7400;
	NON_MRI["CMA"] = 0x7200;
	NON_MRI["CMA"] = 0x7100;
	NON_MRI["CIR"] = 0x7080;
	NON_MRI["CIL"] = 0x7040;
	NON_MRI["INC"] = 0x7020;
	NON_MRI["SPA"] = 0x7010;
	NON_MRI["SNA"] = 0x7008;
	NON_MRI["SZA"] = 0x7004;
	NON_MRI["SZE"] = 0x7002;
	NON_MRI["HLT"] = 0x7001;
	NON_MRI["INP"] = 0xF800;
	NON_MRI["OUT"] = 0xF400;
	NON_MRI["SKI"] = 0xF200;
	NON_MRI["SKO"] = 0xF100;
	NON_MRI["ION"] = 0xF080;
	NON_MRI["IOF"] = 0xF040;
	
	INSTRUCTION = {"ORG", "HEX", "DEC", "END"}; 
}

std::string OpcodeTables::getMRIOperand(const std::string& opcode)
{
	if(MRI.find(opcode) != MRI.end())
	{
		return MRI[opcode][0];
	}
	return "";
}

std::string OpcodeTables::getMRIOperandI(const std::string& opcode)
{
	if(MRI.find(opcode) != MRI.end())
	{
		return MRI[opcode][1];
	}
	return "";
}

int OpcodeTables::getNON_MRIOperand(const std::string& opcode)
{
	if(NON_MRI.find(opcode) != NON_MRI.end())
	{
		return NON_MRI[opcode];
	}
	return -1;
}

std::vector<std::string> OpcodeTables::getInstruction()
{
	return INSTURCTION;
}
