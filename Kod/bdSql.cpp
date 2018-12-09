#include "bdSql.h"
sqlite3 *dbsql;
bdSql::bdSql()
{
	this->state = false;
}


bdSql::~bdSql()
{
	sqlite3_close(dbsql);
}

/// Metoda tworzy baze Sql o nazwie "base" w folderze "db".
/// Prawidlowe utworzenie bazy danych zwraca wartosc true.
bool bdSql::createSql()
{
	int rc = sqlite3_open("..//db//base.db", &dbsql);
	if (rc)
	{
		cout << "Database is not ok" << endl;
		return false;
	}
	else
	{
		cout << "Database is ok" << endl;
		if (this->createTable())
		{
			cout << "Add table product" << endl;
			this->state = true;
			return true;
		}
		else {
			cout << "Not add table product" << endl;
			sqlite3_close(dbsql);
			return false;
		}
	}
}


/// Metoda sprawdza czy istnieje juz baza danych.
/// Jezeli baza danych istnieje to metoda zwroci wartosc true.
bool bdSql::isBaseSql()
{
	QFileInfo fileInfo(QFile("..//db//base.db"));
	if (fileInfo.isFile())
		return true;
	else
		return false;
}

/// Metoda zamyka dostep do bazy danych.
void bdSql::closeBasaSql()
{
	sqlite3_close(dbsql);
}

/// Metoda tworzy polaczenie z baza danych.
/// Prawidlowe polaczenie zwraca wartosc true.
bool bdSql::connectBasaSql()
{
	int rc = sqlite3_open("..//db//base.db", &dbsql);
	if (rc)
	{
		return false;
	}
	else
	{
		this->state = true;
		return true;
	}
}

/// Metoda sprawdza czy jestesmy polaczeni z baza danych.
/// Metoda zwraca zmienna "state".
bool bdSql::isConnect()
{
	return this->state;
}

/// Metoda tworzy tabele "product".
/// Prawidlowe utworzenie tabeli zwraca wartosc true.
bool bdSql::createTable()
{
	char *sql;
	sql = "CREATE TABLE product ("\
		"id integer,"\
		"title TEXT NOT NULL,"\
		"code TEXT NOT NULL,"\
		"series TEXT NOT NULL,"\
		"oldPrice DOUBLE(7),"\
		"newPrice DOUBLE(7),"\
		"size varchar(50),"\
		"pictures varchar(18),"\
		"category varchar(50),"\
		"underCategory varchar(50));";

	int rc = sqlite3_exec(dbsql, sql, NULL, 0, &this->zErrMsg);
	if (rc){
		return false;
	}
	else {
		return true;
	}
}

/// Metoda zwraca ostatni wiersz  w bazie danych.
int bdSql::lastRowid()
{
	string liczba;
	sqlite3_stmt *res;
	string select = "SELECT * FROM product ORDER BY id DESC LIMIT 1";
	int rc = sqlite3_prepare_v2(dbsql, select.c_str(), -1, &res, 0);
	rc = sqlite3_step(res);
	if (rc == 101) 
	{
		liczba = "0";
	}
	else
	{
		liczba = (char*)sqlite3_column_text(res, 0);
	}
	sqlite3_finalize(res);
	return atoi(liczba.c_str());
}

/// Metoda czysci baze danych.
bool bdSql::clearDB()
{
	this->closeBasaSql();
	// usuwanie folderu
	QDir dir("..//db");
	dir.removeRecursively();
	Sleep(500);
	dir.mkdir("..//db");
	dir.remove("..//db");
	if (this->createSql())
		return true;
	else
		return false;
}

/// Metoda sprawdza czy w bazie danych jest jakis dubel.
/// Na wejsciu metoda otrzymuje stringa z unikalnym dla produktu kodem.
bool bdSql::idDouble(string code)
{
	sqlite3_stmt *res;
	const string quote = "\"";
	string select = "SELECT * FROM product WHERE code ==" + quote + code + quote;
	int rc = sqlite3_prepare_v2(dbsql, select.c_str(), -1, &res, 0);
	rc = sqlite3_step(res);
	sqlite3_finalize(res);
	if (rc == 101)
	{
		return false; // brak dubla
	}
	else
	{
		return true; // dubel
	}
	
}

/// Metoda pobiera dana kolumne w tabeli a nastepnie zapisuje ja do pliku tymczasowego.
/// Na wejsciu metoda otrzymuje nazwe pliku oraz numer kolumny z ktorej pobiera wartosci.
void bdSql::getText(string name, int column)
{
	string text = "";
	sqlite3_stmt *res;
	string znak = "\n";
	string select;
	int counter = this->lastRowid();
	int rc;
	for (int i = 1; i <= counter; i++)
	{
		select = "SELECT * FROM product WHERE id == " + to_string(i);
		rc = sqlite3_prepare_v2(dbsql, select.c_str(), -1, &res, 0);
		rc = sqlite3_step(res);
		if (rc == 101)
		{
			text = "0";
		}
		else
		{
			if (i != counter)
				text += (char*)sqlite3_column_text(res, column) + znak;
			else
				text += (char*)sqlite3_column_text(res, column);
		}
	}
	sqlite3_finalize(res);
	ofstream allCode("..//data//"+name+".txt");
	allCode << text;
	allCode.close();
}

/// Metoda dodaje wartosci do bazy danych.
/// Na wejsciu otrzymuje wszystkie dane z tabeli.
/// W przypadku prawidlowego dodania do bazy inkrementuje licznki.
/// Licznik wykorzystywany jest przy wyswietlaniu komunikatu dotyczacego liczby dodanych rekordow.
void bdSql::addValues(int id, QString title, QString code, QString series, double oldPrice, double newPrice, QString sizeProduct, QString picture,
			QString category, QString underCategory)
{
	if (!this->idDouble(code.toStdString()))
	{
		string dataSql = "INSERT INTO product (id,title,code,series,oldPrice,newPrice,size,pictures,category,underCategory) VALUES ("
			+ to_string(id) + ","
			+ string("'") + title.toUtf8().toStdString() + string("'") + ","
			+ string("'") + code.toStdString() + string("'") + ","
			+ string("'") + series.toStdString() + string("'") + ","
			+ to_string(oldPrice) + ","
			+ to_string(newPrice) + ","
			+ string("'") + sizeProduct.toStdString() + string("'") + ","
			+ string("'") + picture.toStdString() + string("'") + ","
			+ string("'") + category.toStdString() + string("'") + ","
			+ string("'") + underCategory.toStdString() + string("'") + ");";

		int rc = sqlite3_exec(dbsql, dataSql.c_str(), NULL, 0, &this->zErrMsg); 
		this->counter++;
	}
}