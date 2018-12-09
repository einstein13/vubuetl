#include "table.h"

table::table()
{
}


table::~table()
{
}

/// Metoda tworzy naglowek w tabeli.
/// Metoda na wejsciu otrzymuje uchwyt do aplikacji.
void table::createHeader(Ui::VubuEtlProjectClass ui)
{
	ui.tableWidget->setColumnCount(9);
	ui.tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Tytul produktu"));
	ui.tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Kod produktu"));
	ui.tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Seria produktu"));
	ui.tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Stara cena"));
	ui.tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Nowa cena"));
	ui.tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Rozmiar"));
	ui.tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Zdjecia"));
	ui.tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("Kategoria"));
	ui.tableWidget->setHorizontalHeaderItem(8, new QTableWidgetItem("Podkategoria"));
}

/// Metoda uzupelnia tabele danymi.
/// Na wejsciu metoda otrzymuje uchwyt do aplikacji, numery dotyczace kolumny oraz wiersza, jak rowniez nazwe pliku z ktorego czyta wartosci.
void table::fillFeild(Ui::VubuEtlProjectClass ui, int number, int quantity, string name)
{
	fstream plik("..//data//" + name + ".txt");
	string text;
	for (int i = 0; i < quantity; i++)
	{
		getline(plik, text);
		if (name == "allPictures") // zdjecia w pliku s¹ zapisywne w postaci linków, dlatego aby wyœwietliæ ile ich jest nale¿y te linki zliczyæ. To w³aœnie robi ten warunek.
		{
			int quantityWord = 1;
			if (text.length() > 2) // sprawdza czy nie jest to pusta wartoœæ
			{
				for (int y = 0; y < text.length(); y++)
				{
					if (text[y] == ' ') // zlicza puste wyst¹pienia 
						quantityWord++;
				}
				text ="Liczba zdjec: "+ to_string(quantityWord-1);
			}
			else
			{
				text = " ";
			}
		}
		else if (name == "allPriceOld" || name == "allPriceNew") { // w bazie danych pusta wartosc w starej czy to nowej cenie jest zapisywana poprzez "0.0".
			if (text == "0.0")										// dlatego przy wyœwietlaniu bazy danych nale¿y j¹ powróciæ do wartoœci pustej kolumny. 
			{
				text = " ";
			}
		}
		ui.tableWidget->setItem(i, number, new QTableWidgetItem(text.c_str()));
	}
	plik.close();
}

/// Metoda czysci baze danych.
/// Metoda na wejsciu otrzymuje uchwyt do aplikacji.
void table::ininTable(Ui::VubuEtlProjectClass ui)
{
	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0); // ustawienie liczby wierszy w tabeli na 0
}

/// Metoda zapisuje dane z tabeli do pliku produkty.CSV
/// Metoda na wejsciu otrzymuje uchwyt do aplikacji.
/// Po prawidlowym zapisaniu pliku metoda zwroci wartosc true.
bool table::saveFileCSV(Ui::VubuEtlProjectClass ui)
{
	QString textData;
	int rows = ui.tableWidget->rowCount(); // zwraca liczbê wierszy w tabeli
	int columns = ui.tableWidget->columnCount(); // zwraca liczbê kolumn
	// pêtle do pobrania wartoœci z rekordów
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			textData += ui.tableWidget->item(i, j)->text();
			textData += " ; "; // wartoœci oddzielone srednikiem
		}
		textData += "\n";   
	}
	// wskazanie œcie¿ki zapisu pliku 
	QString filename = QFileDialog::getSaveFileName(0, "Save file", "", ".csv");
	filename += ".csv";
	//zapisanie pliku
	QFile csvFile(filename);
	if (csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		QTextStream out(&csvFile);
		out << textData;
		csvFile.close();
		return true;
	}
	else {
		return false;
	}
}
