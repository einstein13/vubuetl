#pragma once
#include "VubuEtlProject.h"
using namespace std;

class transformFile
{
public:
	transformFile();
	~transformFile();

	QString getTitle(string nazwa);
	QString getCode(string nazwa);
	QString getSeries(string nazwa);
	QString getPriseOld(string nazwa);
	QString getPriseNew(string nazwa);
	QString getSize(string nazwa);
	QString getPictures(string nazwa);
	QString getCategory(string nazwa);
	QString getUnderCategory(string nazwa);
	string correctSize(string nazwa);
	string correctCode(string nazwa);
};

