#pragma once
#include "VubuEtlProject.h"
#include <QFileDialog>

using namespace std;

class table
{
public:
	table();
	~table();
	void createHeader(Ui::VubuEtlProjectClass ui);
	void fillFeild(Ui::VubuEtlProjectClass ui, int number, int quantity, string name);
	void ininTable(Ui::VubuEtlProjectClass ui);
	bool saveFileCSV(Ui::VubuEtlProjectClass ui);
};

