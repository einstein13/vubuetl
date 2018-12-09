/********************************************************************************
** Form generated from reading UI file 'VubuEtlProject.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUBUETLPROJECT_H
#define UI_VUBUETLPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VubuEtlProjectClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QComboBox *comboBox;
    QPushButton *downloadButton;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QPushButton *transformButton;
    QGroupBox *groupBox_3;
    QPushButton *baseButton;
    QPushButton *clearBaseButton;
    QPushButton *showBaseButton;
    QPushButton *CSVButton;
    QGroupBox *groupBox_4;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QFrame *line_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VubuEtlProjectClass)
    {
        if (VubuEtlProjectClass->objectName().isEmpty())
            VubuEtlProjectClass->setObjectName(QStringLiteral("VubuEtlProjectClass"));
        VubuEtlProjectClass->resize(847, 589);
        centralWidget = new QWidget(VubuEtlProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(191, 141));
        groupBox->setMaximumSize(QSize(200, 200));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 169, 120));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        downloadButton = new QPushButton(verticalLayoutWidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setCheckable(true);
        downloadButton->setChecked(false);

        verticalLayout->addWidget(downloadButton);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 200));
        groupBox_2->setMaximumSize(QSize(230, 200));
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 198, 113));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setEnabled(false);
        checkBox_2->setAcceptDrops(false);
        checkBox_2->setCheckable(true);
        checkBox_2->setChecked(true);
        checkBox_2->setTristate(false);

        verticalLayout_4->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(horizontalLayoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout_4->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(horizontalLayoutWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout_4->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(horizontalLayoutWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        verticalLayout_4->addWidget(checkBox_5);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        checkBox_6 = new QCheckBox(horizontalLayoutWidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        verticalLayout_5->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(horizontalLayoutWidget);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        verticalLayout_5->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(horizontalLayoutWidget);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        verticalLayout_5->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(horizontalLayoutWidget);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        verticalLayout_5->addWidget(checkBox_9);


        horizontalLayout_4->addLayout(verticalLayout_5);

        transformButton = new QPushButton(groupBox_2);
        transformButton->setObjectName(QStringLiteral("transformButton"));
        transformButton->setGeometry(QRect(30, 140, 151, 23));
        transformButton->setCheckable(false);

        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(230, 16777215));
        baseButton = new QPushButton(groupBox_3);
        baseButton->setObjectName(QStringLiteral("baseButton"));
        baseButton->setGeometry(QRect(20, 20, 171, 23));
        baseButton->setCheckable(false);
        clearBaseButton = new QPushButton(groupBox_3);
        clearBaseButton->setObjectName(QStringLiteral("clearBaseButton"));
        clearBaseButton->setGeometry(QRect(130, 100, 61, 23));
        showBaseButton = new QPushButton(groupBox_3);
        showBaseButton->setObjectName(QStringLiteral("showBaseButton"));
        showBaseButton->setGeometry(QRect(20, 60, 171, 23));
        CSVButton = new QPushButton(groupBox_3);
        CSVButton->setObjectName(QStringLiteral("CSVButton"));
        CSVButton->setGeometry(QRect(20, 100, 91, 23));

        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(230, 16777215));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 171, 23));

        gridLayout->addWidget(groupBox_4, 0, 3, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(700, 150));
        tableWidget->setMaximumSize(QSize(2000, 300));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(tableWidget, 2, 0, 1, 4);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 4);

        VubuEtlProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VubuEtlProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 21));
        VubuEtlProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VubuEtlProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VubuEtlProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VubuEtlProjectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VubuEtlProjectClass->setStatusBar(statusBar);

        retranslateUi(VubuEtlProjectClass);

        QMetaObject::connectSlotsByName(VubuEtlProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *VubuEtlProjectClass)
    {
        VubuEtlProjectClass->setWindowTitle(QApplication::translate("VubuEtlProjectClass", "VubuEtlProject", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("VubuEtlProjectClass", "Pobierz", Q_NULLPTR));
        radioButton->setText(QApplication::translate("VubuEtlProjectClass", "Odzie\305\274 damska", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("VubuEtlProjectClass", "Odzie\305\274 damska przedsprzeda\305\274", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("VubuEtlProjectClass", "Czyszczenie magazynu", Q_NULLPTR));
        downloadButton->setText(QApplication::translate("VubuEtlProjectClass", "ROZPOCZNIJ", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("VubuEtlProjectClass", "Transformuj", Q_NULLPTR));
        checkBox->setText(QApplication::translate("VubuEtlProjectClass", "Tytu\305\202 produktu", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("VubuEtlProjectClass", "Kod produktu", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("VubuEtlProjectClass", "Seria produktu", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("VubuEtlProjectClass", "Stara cena", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("VubuEtlProjectClass", "Nowa cena", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("VubuEtlProjectClass", "Rozmiar", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("VubuEtlProjectClass", "Zdj\304\231cia", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("VubuEtlProjectClass", "Kategoria", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("VubuEtlProjectClass", "Podkategoria", Q_NULLPTR));
        transformButton->setText(QApplication::translate("VubuEtlProjectClass", "ROZPOCZNIJ", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("VubuEtlProjectClass", "Baza danych", Q_NULLPTR));
        baseButton->setText(QApplication::translate("VubuEtlProjectClass", "ZASILENIE", Q_NULLPTR));
        clearBaseButton->setText(QApplication::translate("VubuEtlProjectClass", "WYCZY\305\232\304\206", Q_NULLPTR));
        showBaseButton->setText(QApplication::translate("VubuEtlProjectClass", "WY\305\232WIETL BAZE DANYCH", Q_NULLPTR));
        CSVButton->setText(QApplication::translate("VubuEtlProjectClass", "ZAPISZ DO CSV", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("VubuEtlProjectClass", "Proces ETL", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VubuEtlProjectClass", "ROZPOCZNIJ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VubuEtlProjectClass: public Ui_VubuEtlProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VUBUETLPROJECT_H
