#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layout.h"
#include "fmx.h"
//#include "listalbum.h"

/* 환자 정보 DB */
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>


#include <QSplitter>
#include <QListWidget>
#include <QDir>
#include <QFileInfo>
#include <QPalette>
#include <QMdiSubWindow>



#include <QGraphicsScene>
#include <QGraphicsView>

#define sheetWhite "background:rgb(255, 255, 255)"
#define sheetNavy "background:rgb(32, 56, 100)"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    styleColor();                                   // ui 색상 조절 및 크기 조절 함수

    ui->listWidget->setIconSize(QSize(130, 80));
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    ui->listWidget->setFlow(QListWidget::LeftToRight);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));

//    connect(customLayout->grid1, SIGNAL(clicked()), SLOT(selectGrid(QGraphicsView*)));
//    connect(customLayout->grid2, SIGNAL(clicked()), SLOT(selectGrid(QGraphicsView*)));
//    connect(customLayout->grid3, SIGNAL(clicked()), SLOT(selectGrid(QGraphicsView*)));
//    connect(customLayout->grid4, SIGNAL(clicked()), SLOT(selectGrid(QGraphicsView*)));

    //connect(customLayout->grid2, SIGNAL(sigMouseClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));


    loadImages();                                   // listWidget에 이미지 로드
    patientLoad();                                  // 환자 정보 DB 함수

    /* WindowTitle 지정 */
    customLayout = new Layout(this);
    customLayout->setWindowTitle(tr("2 X 2 Grid"));
    connect(customLayout, SIGNAL(destroyed()), customLayout, SLOT(deleteLater()));

    fmx = new FMX(this);
    fmx->setWindowTitle(tr("14 FMX"));
    connect(fmx, SIGNAL(destroyed()), fmx, SLOT(deleteLater()));


    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(customLayout);
    ui->mdiArea->addSubWindow(fmx);
    //cw->setStyleSheet("background:rgb(32, 56, 100)");
    cw->setStyleSheet("background:rgb(0, 0, 0)");
    ui->mdiArea->setActiveSubWindow(cw);



}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase clDB = QSqlDatabase::database("patientDB");            // 데이터베이스 닫기
    if(clDB.isOpen()){                                                  // 만약 파일이 열리면
        patientQueryModel->submitAll();
        delete patientQueryModel;
        clDB.close();
    }
}

void MainWindow::selectGrid(QGraphicsView *gridLayout)
{
    qDebug("Select1");


}


void MainWindow::loadImages()
{
    QDir dir(".");
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    QFileInfoList fileInfoList = dir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot);
    //gridLayout->scene->clear();

    ui->listWidget->clear();
    for(int i=0; i<fileInfoList.count(); i++){
        QListWidgetItem* item = new QListWidgetItem(QIcon(fileInfoList.at(i).fileName()), NULL, ui->listWidget);
        item->setStatusTip(fileInfoList.at(i).fileName());
        ui->listWidget->addItem(item);
    };
}





void MainWindow::selectItem(QListWidgetItem *item){
//    //qDebug("%d %d", customLayout->grid1->scene()->width(), customLayout->grid1->scene()->height());
//    customLayout->grid1->resetTransform();
////    customLayout->scene1->sceneRect().isEmpty();
////    customLayout->scene1->clear();
////    customLayout->scene2->clear();
////    customLayout->scene3->clear();
////    customLayout->scene4->clear();
//    //gridLayout->scene->addPixmap(QPixmap(item->statusTip()).scaled(300, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//    customLayout->scene1->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid1->height()-2));
//    customLayout->scene2->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid2->height()-2));
//    customLayout->scene3->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid3->height()-2));
//    customLayout->scene4->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid4->height()-2));
//    customLayout->grid1->setAlignment(Qt::AlignCenter);
//    customLayout->grid2->setAlignment(Qt::AlignCenter);
//    customLayout->grid3->setAlignment(Qt::AlignCenter);
//    customLayout->grid4->setAlignment(Qt::AlignCenter);

////    qDebug("%d", customLayout->scene->height());

///* 성공 */
    static QGraphicsScene *beforeScene = NULL;              // static이 붙으면 지역변수여도 클래스 안에서 모두 쓸 수 있음.
    if(beforeScene != NULL)
        delete beforeScene;

    QGraphicsScene *newScene = new QGraphicsScene;
    beforeScene = newScene;
    newScene->setBackgroundBrush(Qt::black);

    customLayout->grid1->setScene(newScene);
    newScene->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid1->height()-2));
    customLayout->grid1->setAlignment(Qt::AlignCenter);


/* 시도 */
//    static QGraphicsScene *beforeScene = NULL;              // static이 붙으면 지역변수여도 클래스 안에서 모두 쓸 수 있음.
//    if(beforeScene != NULL)
//        delete beforeScene;

//    QGraphicsScene *newScene = new QGraphicsScene;
//    beforeScene = newScene;
//    newScene->setBackgroundBrush(Qt::black);

//    customLayout->grid1->setScene(newScene);
//    customLayout->grid2->setScene(newScene);
//    customLayout->grid3->setScene(newScene);
//    customLayout->grid4->setScene(newScene);

//    newScene->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid1->height()-2));
//    newScene->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid2->height()-2));
//    newScene->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid3->height()-2));
//    newScene->addPixmap(QPixmap(item->statusTip()).scaledToHeight(customLayout->grid4->height()-2));

//    customLayout->grid1->setAlignment(Qt::AlignCenter);
//    customLayout->grid2->setAlignment(Qt::AlignCenter);
//    customLayout->grid3->setAlignment(Qt::AlignCenter);
//    customLayout->grid4->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_imageClearPushButton_clicked()
{
    customLayout->grid1->scene()->clear();
//    customLayout->grid2->scene()->clear();
//    customLayout->grid3->scene()->clear();
//    customLayout->grid4->scene()->clear();

    customLayout->grid1->scene()->setBackgroundBrush(Qt::white);
//    customLayout->grid2->scene()->setBackgroundBrush(Qt::white);
//    customLayout->grid3->scene()->setBackgroundBrush(Qt::white);
//    customLayout->grid4->scene()->setBackgroundBrush(Qt::white);
}







/* 환자 정보 DB */
void MainWindow::patientLoad()
{
    //QSQLITE 파일로 데이터 베이스 생성                  //데이터베이스가 2개 이상 사용으로 이름 설정
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("patientDB.db");                             //데이터베이스 이름설정

    if(DB.open()){                                                 //조건문
        patientQuery = new QSqlQuery(DB);
        //query 문을 이용하여 테이블 생성 및 PK 키 설정
        patientQuery->exec("CREATE TABLE IF NOT EXISTS patient(chartNum INTEGER Primary Key,"
                           "name VARCHAR(20) NOT NULL, age INTEGER,imagePath VARCHAR(20));");

        patientQueryModel = new QSqlTableModel(this, DB);
        patientQueryModel->setTable("patient");
        patientQueryModel->select();

        /*테이블 헤더 설정*/
        patientQueryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ChartNum"));
        patientQueryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        patientQueryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
        patientQueryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("ImagePath"));

        ui->patientTableView->setModel(patientQueryModel);

        ui->patientTableView->hideColumn(3);

        patientQuery->exec("INSERT INTO patient VALUES (1000,'JaeYeong','28','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1001,'Yuna','26','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1002,'Jaehyun','27','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1003,'eunji','29','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1004,'chelly','28','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1005,'brian','26','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1006,'dessery','27','..')");
        patientQuery->exec("INSERT INTO patient VALUES (1007,'eclipse','29','..')");
        patientQueryModel->select();
        ui->patientTableView->resizeColumnsToContents();
    }
}

/* ui 색상 및 크기 조절 */
void MainWindow::styleColor()
{
    ui->mdiArea->setStyleSheet("background:rgb(32, 56, 100)");
    ui->splitter->setStyleSheet("background:rgb(32, 56, 100)");
    ui->splitter2->setStyleSheet("background:rgb(32, 56, 100)");
    ui->splitter3->setStyleSheet("background:rgb(32, 56, 100)");
    ui->treeWidget1->setStyleSheet("background:rgb(255, 255, 255)");
    ui->treeWidget2->setStyleSheet("background:rgb(255, 255, 255)");
    ui->listWidget->setStyleSheet("background:rgb(255, 255, 255)");
    ui->patientTableView->setStyleSheet("background:rgb(255, 255, 255)");
    ui->doctorNameLineEdit->setStyleSheet("background:rgb(180, 199, 231)");
    //ui->line->setStyleSheet("background:rgb(255, 255, 255)");
    ui->line->setStyleSheet(sheetWhite);


    /* Painter */
    ui->tabWidget->setStyleSheet(sheetNavy);
    ui->brushToolButton->setStyleSheet(sheetWhite);
    ui->spinBox->setStyleSheet(sheetWhite);;
    ui->circleToolButton->setStyleSheet(sheetWhite);
    ui->triangleToolButton->setStyleSheet(sheetWhite);
    ui->rectangleToolButton->setStyleSheet(sheetWhite);
    ui->arrowToolButton->setStyleSheet(sheetWhite);
    ui->colorToolButton->setStyleSheet(sheetWhite);

    /* Processing */
    ui->brightToolButton->setStyleSheet(sheetWhite);
    ui->brightnessToolButton->setStyleSheet(sheetWhite);
    ui->sharpenToolButton->setStyleSheet(sheetWhite);
    ui->contrastToolButton->setStyleSheet(sheetWhite);
    ui->horizontalFlipToolButton->setStyleSheet(sheetWhite);
    ui->verticalFlipToolButton->setStyleSheet(sheetWhite);
    ui->zoomInToolButton->setStyleSheet(sheetWhite);
    ui->zoomOutToolButton->setStyleSheet(sheetWhite);
    ui->panningToolButton->setStyleSheet(sheetWhite);
    ui->leftRotateToolButton->setStyleSheet(sheetWhite);
    ui->rightRotateToolButton->setStyleSheet(sheetWhite);

    /* Measure */
    ui->rulerToolButton->setStyleSheet(sheetWhite);
    ui->measureToolButton->setStyleSheet(sheetWhite);
    ui->protractorToolButton->setStyleSheet(sheetWhite);
    ui->implantToolButton->setStyleSheet(sheetWhite);
    ui->implantToolButton_2->setStyleSheet(sheetWhite);

   // ui->toolBar->setToolButtonStyle(Qt::ToolBarArea));

    QList<int> sizes;
    sizes << 1000 << 50;
    ui->splitter->setSizes(sizes);

    QList<int> sizes2;
    sizes2 << 500 << 130;
    ui->splitter2->setSizes(sizes2);

    QList<int> sizes3;
    sizes3 << 10 << 2000;
    ui->splitter3->setSizes(sizes3);

    ui->verticalSpacer->changeSize(20, 15);
    ui->verticalSpacer_2->changeSize(20, 40);
    ui->verticalSpacer_3->changeSize(20, 20);
    ui->verticalSpacer_4->changeSize(20, 20);
    ui->horizontalSpacer_8->changeSize(20, 12);
    ui->horizontalSpacer_9->changeSize(10,10);
    ui->horizontalSpacer_10->changeSize(10,10);
    ui->verticalSpacer_5->changeSize(12, 30);

    /* toolButton 크기 조절 */
    ui->brushToolButton->setIconSize(QSize(50,40));
    ui->brushToolButton->setText("Brush");
    ui->brushToolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->colorToolButton->setIconSize(QSize(100,30));
    ui->colorToolButton->setText("Color");
    ui->colorToolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
}





