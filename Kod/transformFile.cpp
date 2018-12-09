#include "transformFile.h"
#include <locale>
#include <codecvt>

transformFile::transformFile()
{
}


transformFile::~transformFile()
{
}

/// Metoda z pliku HTML wyodrebnia tutyl danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allTitle.txt. 
QString transformFile::getTitle(string nazwa) // pobieranie tytulow
{
	fstream plik(nazwa); // otwiera plik z html
	ofstream NowyPlik; // tworzy nowe uchwyty do plikow
	string tekst, tekst2; // stringi pomocnicze
	string titleOnlyPage;
	string nameXML;
	string word;
	const string quote = "\""; // znak, ktory umozliwia dodanie slasha 
	bool warunek = true;
	int licznik = 0;
	while (!plik.eof()) // sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst); // pobranie danej linii kodu
		if (!(std::string::npos == tekst.find("<title>"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt"); // otwarcie pliku
			NowyPlik << tekst; // zapis do pliku
			NowyPlik.close(); // zamkniecie pliku
			NowyPlik.clear(); // wyczyszczenie obiektu
			ifstream file("..//assistantFile//testowyprodukt.txt");
			warunek = true;
			if (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				while (word != "content=" + quote + "pl" + quote && warunek) // wyszukanie odpowiedniej frazy zwiazanej z linkiem
				{
					file >> word; // pobranie slowa od spacji do spacji
					if (word == "content=" + quote + "pl" + quote) // sprawdzenie czy slowo jest z podanego przedzialu
					{
						file >> tekst2;
						int dlugosc = tekst2.length(); // okreslenie ilosci znakow w stirngu
						for (int i = 0; i < dlugosc; i++) // pobieranie wartosci
						{
							if (i > 8 && i < dlugosc)
								titleOnlyPage += tekst2[i];
						}
						while (tekst2 != "|")
						{
							file >> tekst2;
							if (tekst2 != "|")
								titleOnlyPage += " " + tekst2; // dodanie wszystkiego 
						}
						nameXML = titleOnlyPage;
						titleOnlyPage += "\n";
						warunek = false;
						file.close();
						file.clear();
					}
				}
			}
			word = "a";
		}
	}
	plik.close();
	ofstream allTitle("..//data//allTitle.txt", ios::app);
	allTitle << titleOnlyPage;
	allTitle.close();
	return nameXML.c_str();
}

/// Metoda z pliku HTML wyodrebnia kod danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allCode.txt. 
QString transformFile::getCode(string nazwa) // pobieranie kodu produktu
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	bool warunek = true;
	int licznik = 0;
	while (!plik.eof())// sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("Kod produktu:"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			NowyPlik.clear();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			warunek = true;
			if (!file.eof())// sprawdzenie czy jestesmy na koncu pliku
			{
				while (word != "</span><div"  && warunek) // wyszukanie odpowiedniej frazy zwiazanej z linkiem
				{
					file >> word;
					if (word == "</span><div")
					{
						file >> tekst2;
						int dlugosc = tekst2.length();
						int x = 0;
						int granica = 21;
						while (tekst2[x] != '<' && x < dlugosc) // petla wyciagajaca dany kod produktu
						{
							if (x > granica)
							{
								nazwa22 += tekst2[x];
							}
							x++;
							if (x == dlugosc)
							{
								nazwa22 += " ";
								file >> tekst2;
								dlugosc = tekst2.length();
								x = 0;
								granica = -1;
							}
						}
						nameXML = nazwa22;
						nazwa22 += "\n";
						warunek = false;
						file.close();
						file.clear();
					}
				}
			}
		}
	}
	plik.close();
	nazwa22 = this->correctCode(nazwa22);
	ofstream allCode("..//data//allCode.txt", ios::app);
	allCode << nazwa22;
	allCode.close();
	return nameXML.c_str();
}

/// Metoda z pliku HTML wyodrebnia serie danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allSeries.txt. 
QString transformFile::getSeries(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	bool warunek = true;
	while (!plik.eof())// sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("Seria:"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			warunek = true;
			if (!file.eof())// sprawdzenie czy jestesmy na koncu pliku
			{
				while (word != "class=" + quote + "series_proj" + quote + ">Seria:"  && warunek) // wyszukanie odpowiedniej frazy zwiazanej z linkiem
				{
					file >> word;
					if (word == "class=" + quote + "series_proj" + quote + ">Seria:")
					{
						file >> tekst2;
						file >> tekst2;
						int dlugosc = tekst2.length();
						int x = 0;
						int granica = 23;
						while (tekst2[x] != '<' && x < dlugosc)
						{
							if (x > granica)
							{
								nazwa22 += tekst2[x];
							}
							x++;
							if (x == dlugosc)
							{
								nazwa22 += " ";
								file >> tekst2;
								dlugosc = tekst2.length();
								x = 0;
								granica = -1;
							}
						}
						nameXML = nazwa22;
						nazwa22 += "\n";
						warunek = false;
						file.close();
					}
				}
			}
		}
	}
	plik.close();
	ofstream allSeries("..//data//allSeries.txt", ios::app);
	allSeries << nazwa22;
	allSeries.close();
	return nameXML.c_str();
}

/// Metoda z pliku HTML wyodrebnia wszystkie STARe CeNY dla danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allPriceOld.txt. 
QString transformFile::getPriseOld(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	while (!plik.eof())// sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("id=" + quote + "projector_price_value" + quote))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			bool warunek = false;
			while (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				file >> word;
				if (!(std::string::npos == word.find("id=" + quote + "projector_price_maxprice" + quote)))
				{
					int dlugosc = word.length();
					for (int i = 0; i < dlugosc; i++)
					{
						if (word[i] == '<')
						{
							warunek = false;
						}
						if (warunek)
						{
							nazwa22 += word[i];
						}
						if (word[i] == '>')
						{
							warunek = true;
						}
					}

				}
			}
			nameXML = nazwa22;
			nazwa22 += "\n";
			file.close();
		}
	}
	plik.close();
	ofstream allPriceOld("..//data//allPriceOld.txt", ios::app);
	allPriceOld << nazwa22;
	allPriceOld.close();
	return nameXML.c_str();
}

/// Metoda z pliku HTML wyodrebnia wszystkie NOWe CeNY dla danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allPriceNew.txt. 
QString transformFile::getPriseNew(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	bool warunek = true;
	while (!plik.eof())// sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("id=" + quote + "projector_price_value" + quote))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			warunek = true;
			if (!file.eof())// sprawdzenie czy jestesmy na koncu pliku
			{

				while (word != "id=" + quote + "projector_price_value" + quote + "><span"  && warunek) // wyszukanie odpowiedniej frazy zwiazanej z linkiem
				{
					file >> word;
					if (word == "id=" + quote + "projector_price_value" + quote + "><span")
					{
						file >> tekst2;
						int dlugosc = tekst2.length();
						int x = 0;
						int granica = 13;
						while (tekst2[x] != '<' && x < dlugosc)
						{
							if (x > granica)
							{
								nazwa22 += tekst2[x];
							}
							x++;
							if (x == dlugosc)
							{
								nazwa22 += " ";
								file >> tekst2;
								dlugosc = tekst2.length();
								x = 0;
								granica = -1;
							}
						}
						nameXML = nazwa22;
						nazwa22 += "\n";
						warunek = false;
						file.close();
					}
				}
			}
		}
	}
	plik.close();
	ofstream allPriceNew("..//data//allPriceNew.txt", ios::app);
	allPriceNew << nazwa22;
	allPriceNew.close();
	return nameXML.c_str();
}

/// Metoda z pliku HTML wyodrebnia wszystkie rozmiary dla danego produktu. 
/// Metoda na wejsciu otrzymuje stringa z kodem HTML. 
/// Metoda na wyjsciu zapisuje wynik do pliku allSize.txt. 
QString transformFile::getSize(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	bool warunek = true;
	while (!plik.eof())// sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("class=" + quote + "projector_status_description" + quote))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			while (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				file >> word;
				if (!(std::string::npos == word.find("projector_size_button")))
				{
					for (int i = 0; i < 2; i++) // sprawdzenie dla dwoch opcji
					{
						int dlugosc = word.length();
						int x = 0;
						bool warunek2 = false;
						while (x < dlugosc)
						{
							if (word[x] == '<')
							{
								warunek2 = false;
								nazwa22 += " ";
							}
							if (warunek2)
							{
								nazwa22 += word[x];
							}
							if (word[x] == '>')
							{
								warunek2 = true;
							}
							x++;
						}
						file >> word;
					}
				}
			}
			nazwa22 = this->correctSize(nazwa22);
			nameXML = nazwa22;
			nazwa22 += "\n";
			file.close();
		}
	}
	plik.close();
	ofstream allSize("..//data//allSize.txt", ios::app);
	allSize << nazwa22;
	allSize.close();
	return nameXML.c_str();
}

/// Metoda pobiera linki do zdjec produktu.
/// Na wejsciu metoda otrzymuje stringa z nazwa pliku.
/// Na wyjsciu metoda zwraca QStringa z wygenerowanymi danymi.
QString transformFile::getPictures(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	const string quote = "\"";
	bool warunek = true;
	while (!plik.eof()) // sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("jqzoom_big"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			while (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				file >> word;
				if (!(std::string::npos == word.find("jqzoom_big")))
				{
					file >> word;
					int dlugosc = word.length();
					for (int i = 0; i < dlugosc; i++)
					{
						if (i > 4 && i < dlugosc - 1)
						{
							nazwa22 += word[i];
						}
						else if (i == dlugosc - 1)
						{
							nazwa22 += " ";
						}
					}
				}
			}
			nameXML = nazwa22;
			nazwa22 += "\n";
			file.close();
		}
	}
	plik.close();
	ofstream allPictures("..//data//allPictures.txt", ios::app);
	allPictures << nazwa22;
	allPictures.close();
	return nameXML.c_str();
}

/// Metoda pobiera kategorie produktu.
/// Na wejsciu metoda otrzymuje stringa z nazwa pliku.
/// Na wyjsciu metoda zwraca QStringa z wygenerowanymi danymi.
QString transformFile::getCategory(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	bool warunek = true;
	while (!plik.eof()) // sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("category bc-item-2"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			while (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				file >> word;
				if (!(std::string::npos == word.find("bc-item-2")))
				{
					file >> word;
					file >> word;
					bool warunek2 = false;
					int i = 0;
					while (warunek)
					{
						if (word[i] == '<')
						{
							warunek = false;
							warunek2 = false;
						}
						if (warunek2)
						{
							nazwa22 += word[i];
						}
						if (word[i] == '>')
						{
							warunek2 = true;
						}
						else if (i == (word.length()-1))
						{
							file >> word;
							i = -1;
							nazwa22 += ' ';
						}
						i++;
					}
				}
			}
			nameXML = nazwa22;
			nazwa22 += "\n";
			file.close();
		}
	}
	plik.close();
	ofstream allPictures("..//data//allCategory.txt", ios::app);
	allPictures << nazwa22;
	allPictures.close();
	return nameXML.c_str();
}

/// Metoda pobiera podkategorie produktu.
/// Na wejsciu metoda otrzymuje stringa z nazwa pliku.
/// Na wyjsciu metoda zwraca QStringa z wygenerowanymi danymi.
QString transformFile::getUnderCategory(string nazwa)
{
	fstream plik(nazwa);
	ofstream NowyPlik;
	string tekst, tekst2;
	string word;
	string nameXML;
	string nazwa22; // string z linkiem
	bool warunek = true;
	while (!plik.eof()) // sprawdzenie czy jestesmy na koncu pliku
	{
		getline(plik, tekst);
		if (!(std::string::npos == tekst.find("bc-active bc-item-3"))) // wyszukanie odpowiedniej frazy w pliku (tytul)
		{
			// zapis odpowiedniej tabelki z danymi do pliku
			NowyPlik.open("..//assistantFile//testowyprodukt.txt");
			NowyPlik << tekst;
			NowyPlik.close();
			ifstream file("..//assistantFile//testowyprodukt.txt");
			while (!file.eof()) // sprawdzenie czy jestesmy na koncu pliku
			{
				file >> word;
				if (!(std::string::npos == word.find("bc-item-3")))
				{
					file >> word;
					file >> word;
					warunek = true;
					bool warunek2 = false;
					int i = 0;
					while (warunek)
					{
						if (word[i] == '<')
						{
							warunek = false;
							warunek2 = false;
						}
						if (warunek2)
						{
							nazwa22 += word[i];
						}
						if (word[i] == '>')
						{
							warunek2 = true;
						}
						else if (i == word.length())
						{
							file >> word;
							i = -1;
							nazwa22 += " ";
						}
						i++;
					}
				}
			}
			nameXML = nazwa22;
			nazwa22 += "\n";
			file.close();
		}
	}
	plik.close();
	ofstream allPictures("..//data//allUnderCategory.txt", ios::app);
	allPictures << nazwa22;
	allPictures.close();
	return nameXML.c_str();
}

/// Metoda usuwa powtorzenia w rozmiarach produktu. 
/// Metoda na wejsciu przyjmuje stringa z szeregiem rozmiarow.
/// Metoda oddaje stringa bez powtorzen rozmiarow. 
string transformFile::correctSize(string file)
{
	ofstream allPictures("..//assistantFile//Categ.txt");
	allPictures << file;
	allPictures.close();
	fstream plik("..//assistantFile//Categ.txt");
	string tabSize[20];
	string wyraz;
	int i = 0;
	bool warunek = true;
	while (!plik.eof()) // sprawdzenie czy jestesmy na koncu pliku
	{
		plik >> wyraz;
		if (wyraz.size() != 0)
		{
			tabSize[i] = wyraz;
			i++;
		}
	}
	int licznik = i;
	string korekta= "";
	for (int x = 0; x < licznik; x++)
	{
		if (!(x == licznik - 1))
		{
			for (int z = x + 1; z < licznik; z++)
			{
				if ((tabSize[x] == tabSize[z]))
				{
					z = licznik;
				}
				else {
					if (z == licznik - 1)
					{
						korekta += tabSize[x] + " ";
					}
				}
			}
		}
		else {
			korekta += tabSize[licznik - 1];
		}
		
	}
	plik.close();
	return korekta;
}

/// Metoda ma za zadanie poprawic kod produktu. Chodzi o usunieciu specjalnych znakow.
/// Metoda na wejsciu otrzymuje stringa z danym kodem.
/// Metoda na wyjsciu oddaje poprawiony wynik.
string transformFile::correctCode(string file)
{
	string korekta = "";
	for (int i = 0; i < file.length(); i++)
	{
		if (file.at(i) != '\'')
		{
			korekta += file.at(i);
		}
	}
	return korekta;
}
