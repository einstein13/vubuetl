#pragma once

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QtXml>
#include <thread>
#include "ui_VubuEtlProject.h"
#include "downloadProduct.h"
#include "transformFile.h"
#include "bdSql.h"
#include "table.h"
#include <iostream>
#include <conio.h>
#include <urlmon.h>
#include <string>
#include <iostream>
#include <fstream>
#include <winsqlite/winsqlite3.h>

#pragma comment(lib, "urlmon.lib")

using namespace std;

class VubuEtlProject : public QMainWindow
{
	Q_OBJECT
	string wszystkieLinki;

public slots:
	void getHTML(QString);
	void transformHTML();
	void radioButton();
	void downloadFunction();
	void updateDatabase();
	void clearDatabase();
	void getHTMLThread();
	void buttonETL();
	void ThreadButtonETL();
	void stateProcess();
	void showDatabase();
	void saveCSV();

public:
	VubuEtlProject(QWidget *parent = Q_NULLPTR);
	~VubuEtlProject();
	QString getValueFile(string, int);
	QString title, code, series, oldPrice, newPrice, size, category, underCategory, picture;
	bool state, stateButtonETL;
	bool stateDownload, stateDownloadStart;
	bool stateTransformStart, stateTransformEnd, stateTransformError;
	bool stateDatabaseconnect, stateDatabaseAdd, stateDatabaseError;
	QString vubuLink;

private:
	Ui::VubuEtlProjectClass ui;
	void deleteDirectory(string nazwa);
	void createDirectory(string nazwa);
	bool isFile(QString nazwa);
	void createTable(bool);
	QTimer *timer;
};
