﻿#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "Print.h"
#include "LT.h"
#include "LexAn.h"
#include "Polish.h"

#define EXP1 16


int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");
	Log::LOG	log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест: ", "без ошибок ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm);
		Log:WriteIn(log, in);
		Lex::LEX lex = Lex::lexAnaliz(log, in);
		IT::showTable(lex.idtable);
		PolishStart(lex);
		LT::showTable(lex.lextable, parm);
		Log::Close(log);

	
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;

}