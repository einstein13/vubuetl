#pragma once
#include "VubuEtlProject.h"

class bdSql
{
public:
	char *zErrMsg = 0;
	int counter;
	bool state;
	bdSql();
	~bdSql();
	bool createSql();
	bool isBaseSql();
	void closeBasaSql();
	bool connectBasaSql();
	bool isConnect();
	bool createTable();
	int lastRowid();
	bool clearDB();
	bool idDouble(string code);
	void getText(string id, int column);
	void addValues(int, QString, QString, QString, double, double, QString, QString, QString, QString);
};

