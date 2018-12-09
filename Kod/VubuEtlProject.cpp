#include "VubuEtlProject.h"
downloadProduct downloadButtonE;
transformFile transformButtonT;
table tableProject;
bdSql dataBase;

VubuEtlProject::VubuEtlProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.radioButton, SIGNAL(clicked()), this, SLOT(radioButton()));
	connect(ui.radioButton_2, SIGNAL(clicked()), this, SLOT(radioButton()));
	connect(ui.radioButton_3, SIGNAL(clicked()), this, SLOT(radioButton()));
	connect(ui.downloadButton, SIGNAL(clicked()), this, SLOT(downloadFunction()));
	connect(ui.transformButton, SIGNAL(clicked()), this, SLOT(transformHTML()));
	connect(ui.baseButton, SIGNAL(clicked()), this, SLOT(updateDatabase()));
	connect(ui.clearBaseButton, SIGNAL(clicked()), this, SLOT(clearDatabase()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ThreadButtonETL()));
	connect(ui.showBaseButton, SIGNAL(clicked()), this, SLOT(showDatabase()));
	connect(ui.CSVButton, SIGNAL(clicked()), this, SLOT(saveCSV()));

	// wysylanie sygnalu co 1500 ms majacy na celu sprawdzanie statusu
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(stateProcess()));
	timer->start(30);

	// ustawienie zmiennych na false
	this->state = false; this->stateDownload = false; this->stateButtonETL = false; this->stateDownloadStart = false;
	this->stateDatabaseconnect = false; this->stateDatabaseAdd = false; this->stateDatabaseError = false;
	this->stateTransformStart = false, this->stateTransformEnd = false, this->stateTransformError = false;

	this->radioButton();
	tableProject.ininTable(ui); // czyszczenie tabeli
	tableProject.createHeader(ui); // tworzenie Headerow tabeli 

	if (dataBase.isBaseSql()) // sprawdzenie czy jest utworzona baza danych
	{
		if (dataBase.connectBasaSql())
			ui.statusBar->showMessage("Polaczono z baza danych", 5000);
		else
			ui.statusBar->showMessage("Brak polaczenia z baza danych", 5000);
	}
	else
	{
		this->createDirectory("..//db");
		if (dataBase.createSql())
		{
			ui.statusBar->showMessage("Utworzono baze danych", 5000);
		}
		else
		{
			ui.statusBar->showMessage("Nie mozna utworzyc bazy danych", 5000);
		}
	}
}

VubuEtlProject::~VubuEtlProject()
{
}

///Metoda aktywuje przycisk do pobierania danych (pliki HTML)
/// Na wejsciu otrzymuje link z ktorego ma pobrac dane produkty.
void VubuEtlProject::getHTML(QString link)
{
	if (!this->state) {
		int retcode = system("ping -c1 vubu.pl > nul"); // sprawdzenie czy pinguje
		if (retcode == 1){
			this->state = true;
			tableProject.ininTable(ui); // czyszczenie tabeli
			tableProject.createHeader(ui);
			this->stateDownloadStart = true;
			this->vubuLink = link;
			// sprawdzenie czy pobieranie jest uruchomione przez przycisk ETL.
			if (!this->stateButtonETL) {
				QThread *thread = new QThread;
				this->moveToThread(thread);
				thread->start();
				connect(thread, SIGNAL(started()), this, SLOT(getHTMLThread()), Qt::DirectConnection);
				connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
			}
			else {
				this->getHTMLThread();
			}
		}
		else{
			ui.statusBar->showMessage("Brak dostepu do witryny www.vubu.pl", 5000);
		}
	}
	else {
		ui.downloadButton->setChecked(true);
	}
}

/// Metoda usuwa folder wraz z jej zawartoscia.
/// Metoda na wejsciu otrzymuje stringa ze sciezka.
void VubuEtlProject::deleteDirectory(string nazwa)
{
	QDir dir(nazwa.c_str());
	dir.removeRecursively();
	Sleep(500);
	dir.remove(nazwa.c_str());
}

/// Metoda tworzy folder.
/// Metoda na wejsciu otrzymuje stringa ze sciezka.
void VubuEtlProject::createDirectory(string nazwa)
{
	QDir dir;
	dir.mkdir(nazwa.c_str());
	dir.remove(nazwa.c_str());
}

/// Metoda sprawdza czy dany plik istnieje.
/// Metoda na wejsciu otrzymuje stringa ze sciezka.
bool VubuEtlProject::isFile(QString nazwa)
{
	QFile file(nazwa);
	QFileInfo fileInfo(file);
	if (fileInfo.isFile())
		return true;
	else
		return false;
}

/// Metoda transformuje z pobranych plikow html informacje podane przez uzytkownika
void VubuEtlProject::transformHTML()
{
	if (!this->state){
		fstream plik("..//assistantFile//howMuchPages.txt");
		string ileStron;
		plik >> ileStron;
		plik.close();
		string nazwa;
		int liczba = atoi(ileStron.c_str());
		if (liczba != 0){
			this->state = true;
			this->stateTransformStart = true;
			this->deleteDirectory("..//data");
			this->createDirectory("..//data");
			this->title.clear(); this->code.clear(); this->series.clear(); this->oldPrice.clear(); this->newPrice.clear();
			this->size.clear(); this->category.clear(); this->underCategory.clear(); this->picture.clear();
			for (int i = 0; i < liczba; i++){
				nazwa = "..//files//plik" + to_string(i) + ".txt";
				if (ui.checkBox->isChecked())
					this->title = transformButtonT.getTitle(nazwa);
				if (ui.checkBox_2->isChecked())
					this->code = transformButtonT.getCode(nazwa);
				if (ui.checkBox_3->isChecked())
					this->series = transformButtonT.getSeries(nazwa);
				if (ui.checkBox_4->isChecked())
					this->oldPrice = transformButtonT.getPriseOld(nazwa);
				if (ui.checkBox_5->isChecked())
					this->newPrice = transformButtonT.getPriseNew(nazwa);
				if (ui.checkBox_6->isChecked())
					this->size = transformButtonT.getSize(nazwa);
				if (ui.checkBox_7->isChecked())
					this->picture = transformButtonT.getPictures(nazwa);
				if (ui.checkBox_8->isChecked())
					this->category = transformButtonT.getCategory(nazwa);
				if (ui.checkBox_9->isChecked())
					this->underCategory = transformButtonT.getUnderCategory(nazwa);
			}
			this->stateTransformStart = false;
			this->stateTransformEnd = true;
			this->state = false;
		}
		else{
			this->stateTransformError = true;
		}
		this->createTable(false);
	}
}

/// Metoda generuje rozwijane combo boxy.
void VubuEtlProject::radioButton()
{
	if (ui.radioButton->isChecked()){
		ui.comboBox->clear();
		QStringList list = (QStringList() << "Wszystko" << "Bluzki" << "Bluzy" << "Koszule" << "Kurtki i zakiety"
			<< "Sukienki" << "Swetry" << "Spodnie, szorty, spodnice" << "Kostiumy kapielowe" << "Kombinezony");
		ui.comboBox->addItems(list);
	}
	if (ui.radioButton_2->isChecked()){
		ui.comboBox->clear();
		QStringList list = (QStringList() << "Wszystko" << "Bluzki" << "Bluzy" << "Koszule" << "Kurtki i zakiety"
			<< "Sukienki" << "Swetry");
		ui.comboBox->addItems(list);
	}
	if (ui.radioButton_3->isChecked()){
		ui.comboBox->clear();
		QStringList list = (QStringList() << "Wszystko" << "Bluzki" << "Bluzy" << "Koszule" << "Kurtki i zakiety"
			<< "Sukienki" << "Spodnie, szorty, spodnice" << "Kombinezony");
		ui.comboBox->addItems(list);
	}
}

/// Metoda sprawdza jaki aktualnie chackbox jest wcisniety i odpowiednio przekazuje link do rozpoczecia pobierania
void VubuEtlProject::downloadFunction()
{
	QString textFromCombobox = ui.comboBox->currentText();
	if (ui.radioButton->isChecked()){
		getHTML(downloadButtonE.comboBoxCategoryClothesWomen(textFromCombobox));
	}
	if (ui.radioButton_2->isChecked()){
		getHTML(downloadButtonE.comboBoxCategoryClothesWomenPresale(textFromCombobox));
	}
	if (ui.radioButton_3->isChecked()){
		getHTML(downloadButtonE.comboBoxCategoryClearWarehause(textFromCombobox));
	}
}

/// Metoda uzupelnia tabele danymi pobranymi z plikow. 
void VubuEtlProject::createTable(bool warrning)
{
	fstream plik_2("..//assistantFile//howMuchPages.txt");
	string ileStron, nazwa;
	plik_2 >> ileStron;
	plik_2.close();
	int quantity = atoi(ileStron.c_str());
	if (warrning) {
		quantity = dataBase.lastRowid();
	}
	tableProject.ininTable(ui);
	tableProject.createHeader(ui);
	for (int i = 0; i < quantity; i++)
	{
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	}
	tableProject.fillFeild(ui, 0, quantity, "allTitle");
	tableProject.fillFeild(ui, 1, quantity, "allCode");
	tableProject.fillFeild(ui, 2, quantity, "allSeries");	
	tableProject.fillFeild(ui, 3, quantity, "allPriceOld");	
	tableProject.fillFeild(ui, 4, quantity, "allPriceNew");	
	tableProject.fillFeild(ui, 5, quantity, "allSize");	
	tableProject.fillFeild(ui, 6, quantity, "allPictures");	
	tableProject.fillFeild(ui, 7, quantity, "allCategory");	
	tableProject.fillFeild(ui, 8, quantity, "allUnderCategory");	
}

/// Metoda zasila baze danych
void VubuEtlProject::updateDatabase()
{
	if (!this->state)
	{
		this->state = true;
		if (!dataBase.isConnect())
		{
			this->stateDatabaseconnect = true;
		}
		else
		{
			fstream plik_2("..//assistantFile//howMuchPages.txt");
			string ileStron, nazwa;
			plik_2 >> ileStron;
			plik_2.close();
			int quantity = atoi(ileStron.c_str());
			if (this->isFile("..//data//allCode.txt")){
				dataBase.counter = 0;
				int sql = dataBase.lastRowid();
				int liczba;
				for (int i = 0; i < quantity; i++){
					QString title = this->getValueFile("allTitle", i);
					QString code = this->getValueFile("allCode", i);
					QString series = this->getValueFile("allSeries", i);
					double oldPrice = (this->getValueFile("allPriceOld", i)).toDouble();
					double newPrice = (this->getValueFile("allPriceNew", i)).toDouble();
					QString size = this->getValueFile("allSize", i);
					QString picture = this->getValueFile("allPictures", i);
					QString category = this->getValueFile("allCategory", i);
					QString underCategory = this->getValueFile("allUnderCategory", i);
					liczba = sql + i + 1;
					dataBase.addValues(liczba, title, code, series, oldPrice, newPrice, size, picture, category, underCategory);
				}
				this->stateDatabaseAdd = true; // wyswietl stosowny komunikat
				// usuwanie tymczasowych folderow 
				this->deleteDirectory("..//data");
				this->deleteDirectory("..//assistantFile");
				this->deleteDirectory("..//files");
			}
			else{
				this->stateDatabaseError = true;
			}
		}
		this->state = false;
	}	
}

/// Metoda czysci baze danych
void VubuEtlProject::clearDatabase()
{
	if (dataBase.clearDB()) {
		ui.statusBar->showMessage("Wyczyszczono baze danych", 5000);
		tableProject.ininTable(ui); // czyszczenie tabeli
		tableProject.createHeader(ui);
	}
	else
		ui.statusBar->showMessage("Blad czyszczenia bazy", 5000);
}

/// Metoda pobiera wszystkie pliki HTML. Jest ona uruchamiana w watku.
void VubuEtlProject::getHTMLThread()
{
	//usuwanie i tworzenie folderu
	this->deleteDirectory("..//assistantFile");
	this->createDirectory("..//assistantFile");
	this->deleteDirectory("..//data");
	this->createDirectory("..//data");
	this->deleteDirectory("..//files");
	this->createDirectory("..//files");

	downloadButtonE.howMuchIsPages(this->vubuLink);
	downloadButtonE.downloadCodeHTMLProduct();
	this->stateDownload = true;
	this->state = false;
	ui.downloadButton->setChecked(false);
	this->thread()->wait(0);
	//this->thread()->exit();
}

/// Metoda jest wywolywana poprzez wcisniecie przycisku ETL
/// Metoda ma za zadanie wykonac caly proces ETL
void VubuEtlProject::buttonETL()
{
	if (!this->state){
		this->stateButtonETL = true;
		this->downloadFunction();
		this->transformHTML();
		this->updateDatabase();
		this->stateButtonETL = false;
		this->thread()->wait(0);
		//this->thread()->exit();
	}
}

/// Metoda tworzy watek do uruchomienia procesu ETL
void VubuEtlProject::ThreadButtonETL()
{
	QThread *thread = new QThread;
	this->moveToThread(thread);
	thread->start();
	connect(thread, SIGNAL(started()), this, SLOT(buttonETL()), Qt::DirectConnection);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
}

/// Metoda sprawdza i wyswietla odpowiednie komunikaty
void VubuEtlProject::stateProcess()
{
	if (this->stateDownloadStart) {
		ui.statusBar->showMessage("Pobieram pliki");
		this->stateDownloadStart = false;
	}
	if (this->stateDownload){
		fstream plik("..//assistantFile//howMuchPages.txt");
		string ileStron;
		plik >> ileStron;
		plik.close();
		ileStron = "Pobrano produktow: " + ileStron;
		ui.statusBar->showMessage(ileStron.c_str(), 5000);
		this->stateDownload = false;
	}
	else if (this->stateTransformStart){
		ui.statusBar->showMessage("Transformuje");
		this->stateTransformStart = false;
	}
	else if (this->stateTransformEnd)
	{
		ui.statusBar->showMessage("Transformacja przebiegla pomyslnie", 5000);
		this->stateTransformEnd = false;
	}
	else if (this->stateTransformError){
		ui.statusBar->showMessage("Najpierw pobierz dane!", 5000);
		this->stateTransformError = false;
	}
	else if (this->stateDatabaseconnect){
		ui.statusBar->showMessage("Brak polaczenia z baza!", 5000);
		this->stateDatabaseconnect = false;
	}
	else if (this->stateDatabaseAdd){
		string text = "Liczba dodanych produktow " + to_string(dataBase.counter);
		ui.statusBar->showMessage(text.c_str(), 5000);
		this->stateDatabaseAdd = false;
	}
	else if (this->stateDatabaseError) {
		ui.statusBar->showMessage("Brak plikow do zasilenia", 5000);
		this->stateDatabaseError = false;
	}

}

/// Metoda pobiera dane z bazy a nastepnie wyswietla je w tabeli
void VubuEtlProject::showDatabase()
{
	if (dataBase.lastRowid() != 0){
		this->createDirectory("..//data");
		dataBase.getText("allTitle", 1);
		dataBase.getText("allCode", 2);
		dataBase.getText("allSeries", 3);
		dataBase.getText("allPriceOld", 4);
		dataBase.getText("allPriceNew", 5);
		dataBase.getText("allSize", 6);
		dataBase.getText("allPictures", 7);
		dataBase.getText("allCategory", 8);
		dataBase.getText("allUnderCategory", 9);
		this->createTable(true);
		this->deleteDirectory("..//data");
		ui.statusBar->showMessage("Baza danych wyswietlona poprawnie", 5000);
	}
	else {
		ui.statusBar->showMessage("Baza danych jest pusta", 5000);
	}
	
}

/// Metoda zapisuje tabele do pliku CSV
void VubuEtlProject::saveCSV()
{ 
	if(tableProject.saveFileCSV(ui))
		ui.statusBar->showMessage("Zapisano plik CSV", 5000);
	else
		ui.statusBar->showMessage("Blad zapisu pliku CSV", 5000);
}

/// Metoda zwraca dany wiersz w pliku txt
QString VubuEtlProject::getValueFile(string name, int row)
{
	fstream plik("..//data//" + name + ".txt");
	string text;
	for (int i = 0; i < row+1; i++){
		getline(plik, text);
		if (name == "allPictures"){
			int quantityWord = 1;
			if (text.length() > 2) // sprawdza czy nie jest to pusta wartosc
			{
				for (int y = 0; y < text.length(); y++){
					if (text[y] == ' ')
						quantityWord++;
				}
				text = "Liczba zdjec: " + to_string(quantityWord - 1);
			}
			else{
				text = " ";
			}
		}
	}
	plik.close();
	return text.c_str();
}