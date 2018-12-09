#pragma once
#include "VubuEtlProject.h"
using namespace std;

class downloadProduct
{
	QString odziezDamskaWszystko = "/pol_m_DLA-NIEJ_Odziez-damska-604.html";
	QString odziezDamskaBluzki = "/pol_m_DLA-NIEJ_Odziez-damska_Bluzki-613.html";
	QString odziezDamskaBluzy = "/pol_m_DLA-NIEJ_Odziez-damska_Bluzy-638.html";
	QString odziezDamskaKoszule = "/pol_m_DLA-NIEJ_Odziez-damska_Koszule-616.html";
	QString odziezDamskaKurtkiIZakiety = "/pol_m_DLA-NIEJ_Odziez-damska_Kurtki-i-zakiety-640.html";
	QString odziezDamskaSukienki = "/pol_m_DLA-NIEJ_Odziez-damska_Sukienki-614.html";
	QString odziezDamskaSwetry = "/pol_m_DLA-NIEJ_Odziez-damska_Swetry-615.html";
	QString odziezDamskaSpodnie = "/pol_m_DLA-NIEJ_Odziez-damska_Spodnie-szorty-spodnice-617.html";
	QString odziezDamskaKostiumy = "/pol_m_DLA-NIEJ_Odziez-damska_Kostiumy-kapielowe-649.html";
	QString odziezDamskakombinezony = "/pol_m_DLA-NIEJ_Odziez-damska_Kombinezony-650.html";

	QString odziezDamskaPrzedsprzedazWszystko = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz-651.html";
	QString odziezDamskaPrzedsprzedazBluzki = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Bluzki-652.html";
	QString odziezDamskaPrzedsprzedazBluzy = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Bluzy-653.html";
	QString odziezDamskaPrzedsprzedazKoszule = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Koszule-654.html";
	QString odziezDamskaPrzedsprzedazKurtki = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Kurtki-i-zakiety-655.html";
	QString odziezDamskaPrzedsprzedazSukienki = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Sukienki-656.html";
	QString odziezDamskaPrzedsprzedazSwetry = "/pol_m_DLA-NIEJ_Odziez-damska-przedsprzedaz_Swetry-657.html";

	QString czyszczenieMagazynuWszystko = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu-663.html";
	QString czyszczenieMagazynuBluzki = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Bluzki-664.html";
	QString czyszczenieMagazynuBluzy = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Bluzy-665.html";
	QString czyszczenieMagazynuKoszule = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Koszule-666.html";
	QString czyszczenieMagazynuKurtki = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Kurtki-i-zakiety-667.html";
	QString czyszczenieMagazynuSukienki = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Sukienki-668.html";
	QString czyszczenieMagazynuSpodnie = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Spodnie-szorty-spodnice-670.html";
	QString czyszczenieMagazynuKombinezony = "/pol_m_DLA-NIEJ_Czyszczenie-magazynu_Kombinezony-673.html";

public:
	downloadProduct();
	~downloadProduct();
	string allLinks;
	void howMuchIsPages(QString linkVubu);
	void downloadCodeHTMLProduct();
	QString comboBoxCategoryClothesWomen(QString);
	QString comboBoxCategoryClothesWomenPresale(QString);
	QString comboBoxCategoryClearWarehause(QString);

private:
	void getAllLinkToProduct(string nazwa);
};

