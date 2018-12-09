#include "downloadProduct.h"

downloadProduct::downloadProduct()
{
}


downloadProduct::~downloadProduct()
{
}

/// Metoda sprawdza ile stron z produktami zostalo utworzonych przez serwis Vubu.pl a nastepnie pobiera kazdy link do danego produktu.
/// Metoda na wejsciu otrzymuje QStringa z linkiem do glownej strony, z ktorej pobiera linki produktow.
void downloadProduct::howMuchIsPages(QString linkVubu)
{
	this->allLinks.clear(); // czyszczenie zmiennej ze wszystkimi linkami
	string adressWebsite = linkVubu.toStdString();
	wstring stemp = wstring(adressWebsite.begin(), adressWebsite.end()); // konwertowanie stringa na wstring
	int licznik = 0;
	if (URLDownloadToFile(NULL, stemp.c_str(), L"..//assistantFile//linki.txt", 0, NULL) == S_OK)
	{
		licznik++;
		bool warunek = true;
		this->getAllLinkToProduct("linki"); // pobieramy wszystkie linki ze strony
		while (warunek)
		{
			QString nazwaLinku = linkVubu + "?counter=" + to_string(licznik).c_str();
			adressWebsite = nazwaLinku.toStdString();
			stemp = wstring(adressWebsite.begin(), adressWebsite.end());
			if (URLDownloadToFile(NULL, stemp.c_str(), L"..//assistantFile//linki.txt", 0, NULL) == S_OK)
			{
				licznik++;
				this->getAllLinkToProduct("linki"); // pobieramy wszystkie linki ze strony
			}
			else
			{
				warunek = false;
			}
			Sleep(700);
		}
		if (licznik > 1) // redukcja spowodowana implementacja ostatniej zmiennej
			licznik--;
	}
}

/// Metoda pobiera ze strony wszystkie linki HTML wygenerowane przez wyszukiwarke vubu.pl.
void downloadProduct::getAllLinkToProduct(string nazwa)
{
	fstream plik("..//assistantFile//" + nazwa + ".txt");
	ofstream NowyPlik;
	string tekst, word;
	const string quote = "\"";
	while (!plik.eof())
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("class=" + quote + "product_icon show_size_table" + quote + " " + "href=" + quote))) // wyszukanie odpowiedniej frazy w pliku
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowy.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowy.txt");
			string nazwa22; // string z linkiem
			while (!file.eof()) // wyszukanie odpowiedniej frazy zwiazanej z linkiem
			{
				file >> word;
				if (!(std::string::npos == word.find("product_name")))
				{
					file >> word;
					int dlugosc = word.length();
					for (int i = 0; i < dlugosc; i++)
					{
						if (i > 5 && i < dlugosc - 1)
							nazwa22 += word[i];
					}
					this->allLinks += nazwa22 + "\n";
					nazwa22.clear();
				}
			}
		}
	}
	ofstream saveLinksHTML;
	saveLinksHTML.open("..//assistantFile//linkiHTML.txt");
	saveLinksHTML << this->allLinks;
	saveLinksHTML.close();
	plik.close();
}

/// Metoda bazuje na pliku "linkiHTML.txt", w ktorej znajduja sie wszystkie odnosniki do produktow wybrane przez uzytkownika
/// Metoda pobiera kod HTML produktu i zapisuje go do folderu pliki a nazwa pliku sklada sie z: "plik + int(i)"
/// Metoda zapisuje ilosc pobranych produktow (int) do pliku howMuchPages.txt
void downloadProduct::downloadCodeHTMLProduct()
{
	string line;
	int licznik = -1;
	ifstream file("..//assistantFile//linkiHTML.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			licznik++;
		}
	}
	file.close();
	file.open("..//assistantFile//linkiHTML.txt");
	if (file.is_open())
	{
		int x = 0;
		while (x < licznik)
		{
			getline(file, line);
			string strona = "https://vubu.pl" + line;
			wstring stemp = wstring(strona.begin(), strona.end());
			string plik = "..//files//plik" + to_string(x) + ".txt";
			wstring plikZapisz = wstring(plik.begin(), plik.end());
			URLDownloadToFile(NULL, stemp.c_str(), plikZapisz.c_str(), 0, NULL);
			x++;
			Sleep(1500);
		}
	}
	ofstream howMuchPages("..//assistantFile//howMuchPages.txt");
	howMuchPages << to_string(licznik);
	howMuchPages.close();
}

/// Metoda na wejsciu otrzymuje QStringa z danymi wybrania poszczegolnej wartosci w comboBoxie dotyczacym odziezy damskiej.
/// Metoda zwraca gotowy link do pobrania danych z danej strony.
QString downloadProduct::comboBoxCategoryClothesWomen(QString textFromCombobox)
{
	if (textFromCombobox == "Wszystko")
	{
		return "https://vubu.pl" + this->odziezDamskaWszystko;
	}
	else if (textFromCombobox == "Bluzki")
	{
		return ("https://vubu.pl" + this->odziezDamskaBluzki);
	}
	else if (textFromCombobox == "Bluzy")
	{
		return ("https://vubu.pl" + this->odziezDamskaBluzy);
	}
	else if (textFromCombobox == "Koszule")
	{
		return ("https://vubu.pl" + this->odziezDamskaKoszule);
	}
	else if (textFromCombobox == "Kurtki i zakiety")
	{
		return ("https://vubu.pl" + this->odziezDamskaKurtkiIZakiety);
	}
	else if (textFromCombobox == "Sukienki")
	{
		return ("https://vubu.pl" + this->odziezDamskaSukienki);
	}
	else if (textFromCombobox == "Swetry")
	{
		return ("https://vubu.pl" + this->odziezDamskaSwetry);
	}
	else if (textFromCombobox == "Spodnie, szorty, spodnice")
	{
		return ("https://vubu.pl" + this->odziezDamskaSpodnie);
	}
	else if (textFromCombobox == "Kostiumy kapielowe")
	{
		return ("https://vubu.pl" + this->odziezDamskaKostiumy);
	}
	else if (textFromCombobox == "Kombinezony")
	{
		return ("https://vubu.pl" + this->odziezDamskakombinezony);
	}
	return "";
}

/// Metoda na wejsciu otrzymuje QStringa z danymi wybrania poszczegolnej wartosci w comboBoxie dotyczacym odziezy damskiej - przedsprzedaz.
/// Metoda zwraca gotowy link do pobrania danych z danej strony.
QString downloadProduct::comboBoxCategoryClothesWomenPresale(QString textFromCombobox)
{
	if (textFromCombobox == "Wszystko")
	{
		return "https://vubu.pl" + this->odziezDamskaPrzedsprzedazWszystko;
	}
	else if (textFromCombobox == "Bluzki")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazBluzki);
	}
	else if (textFromCombobox == "Bluzy")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazBluzy);
	}
	else if (textFromCombobox == "Koszule")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazKoszule);
	}
	else if (textFromCombobox == "Kurtki i zakiety")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazKurtki);
	}
	else if (textFromCombobox == "Sukienki")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazSukienki);
	}
	else if (textFromCombobox == "Swetry")
	{
		return ("https://vubu.pl" + this->odziezDamskaPrzedsprzedazSwetry);
	}
	return "";
}

/// Metoda na wejsciu otrzymuje QStringa z danymi wybrania poszczegolnej wartosci w comboBoxie dotyczacym czyszczenia magazynow.
/// Metoda zwraca gotowy link do pobrania danych z danej strony.
QString downloadProduct::comboBoxCategoryClearWarehause(QString textFromCombobox)
{
	if (textFromCombobox == "Wszystko")
	{
		return "https://vubu.pl" + this->czyszczenieMagazynuWszystko;
	}
	else if (textFromCombobox == "Bluzki")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuBluzki);
	}
	else if (textFromCombobox == "Bluzy")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuBluzy);
	}
	else if (textFromCombobox == "Koszule")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuKoszule);
	}
	else if (textFromCombobox == "Kurtki i zakiety")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuKurtki);
	}
	else if (textFromCombobox == "Sukienki")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuSukienki);
	}
	else if (textFromCombobox == "Spodnie")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuSpodnie);
	}
	else if (textFromCombobox == "Kombinezony")
	{
		return ("https://vubu.pl" + this->czyszczenieMagazynuKombinezony);
	}
	return "";
}
