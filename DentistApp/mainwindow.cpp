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
#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QRectF>
#include <QHash>





#define sheetWhite "background:rgb(255, 255, 255)"
#define sheetNavy "background:rgb(32, 56, 100)"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), newScene(nullptr)
{    
    ui->setupUi(this);

    styleColor();                                   // ui 색상 조절 및 크기 조절 함수
    loadImages();                                   // listWidget에 이미지 로드
    patientLoad();                                  // 환자 정보 DB 함수

    ui->listWidget->setIconSize(QSize(130, 80));
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    ui->listWidget->setFlow(QListWidget::LeftToRight);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));

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

void MainWindow::selectItem(QListWidgetItem *item)
{
//    if(customLayout->g == false) {
//        if(cnt == 0) {
//            newScene1 = new QGraphicsScene;
//            newScene1->setBackgroundBrush(Qt::black);
//            customLayout->grid1->setScene(newScene1);
//            QSize size = customLayout->grid1->viewport()->size();
//            newScene1->addPixmap(QPixmap(item->statusTip()).scaled(size, Qt::KeepAspectRatio));
//            customLayout->grid1->setAlignment(Qt::AlignCenter);

//            cnt++;
//            qDebug() << "click : 1";
//        }

//    else if(customLayout->g == true) {
//        //----------------------------------------------------------------------

//        newScene = new QGraphicsScene;
//        newScene->setBackgroundBrush(Qt::black);
//        customLayout->grid->setScene(newScene);
//        newScene->update();
//        QSize size = customLayout->grid->viewport()->size();
//        newScene->addPixmap(QPixmap(item->statusTip()).scaled(size, Qt::KeepAspectRatio));
//        customLayout->grid->setAlignment(Qt::AlignCenter);

//        //----------------------------------------------------------------------
//}

// 다시 시도

    qDebug() << "Test";

    if(customLayout->g == false) {
        if(cnt == 0) {
            customLayout->grid = customLayout->grid1;
            customLayout->scene = customLayout->scene1;
            cnt ++;
            qDebug() << "click : 1";
        }
        else if(cnt == 1) {
            customLayout->grid = customLayout->grid2;
            customLayout->scene = customLayout->scene2;
            cnt ++;
            qDebug() << "click : 2";
        }
        else if(cnt == 2) {
            customLayout->grid = customLayout->grid3;
            customLayout->scene = customLayout->scene3;
            cnt ++;
            qDebug() << "click : 3";
        }
        else if(cnt == 3) {
            customLayout->grid = customLayout->grid4;
            customLayout->scene = customLayout->scene4;
            cnt ++;
            qDebug() << "click : 3";
        }

        qDebug() << "foreach";
        foreach(auto item, customLayout->scene->items()) {
            customLayout->scene->removeItem(item);
            delete item;
        }
        //customLayout->scene->clear();
        customLayout->scene->setBackgroundBrush(Qt::black);
        QSize size = customLayout->grid->viewport()->size();
        QGraphicsPixmapItem *pixItem = customLayout->scene->addPixmap(QPixmap(item->statusTip()).scaled(size, Qt::KeepAspectRatio));
        customLayout->grid->setAlignment(Qt::AlignCenter);
        customLayout->scene->setSceneRect(pixItem->sceneBoundingRect());
        customLayout->grid->update();
        itemHash[pixItem] = item->statusTip();
    }

    else if(customLayout->g == true) {

        //----------------------------------------------------------------------
//            newScene = new QGraphicsScene;
//            newScene->setBackgroundBrush(Qt::black);
//            //customLayout->grid->setFixedSize(customLayout->grid->width(), customLayout->grid->height());
//            //customLayout->grid->setFixedSize(customLayout->window()->size().width(), customLayout->window()->size().height());
//            customLayout->grid->setScene(newScene);
//            newScene->update();
//            QSize size = customLayout->grid->viewport()->size();
//            newScene->addPixmap(QPixmap(item->statusTip()).scaled(size, Qt::KeepAspectRatio));
//            customLayout->grid->setAlignment(Qt::AlignCenter);
//            //newScene->clear();
//            //customLayout->grid->scene()->clear();

        //----------------------------------------------------------------------

        foreach(auto item, customLayout->scene->items()) {
            customLayout->scene->removeItem(item);
            delete item;
        }
        //customLayout->scene->clear();
        customLayout->scene->setBackgroundBrush(Qt::black);
        QSize size = customLayout->grid->viewport()->size();
        QGraphicsPixmapItem *pixItem = customLayout->scene->addPixmap(QPixmap(item->statusTip()).scaled(size, Qt::KeepAspectRatio));
        customLayout->grid->setAlignment(Qt::AlignCenter);
        customLayout->scene->setSceneRect(pixItem->sceneBoundingRect());
        customLayout->grid->update();
        itemHash[pixItem] = item->statusTip();
    }
}


void MainWindow::resizeEvent(QResizeEvent* event)
{
    QSize itemIize1 = customLayout->grid1->viewport()->size();
    QSize itemIize2 = customLayout->grid1->viewport()->size();
    QSize itemIize3 = customLayout->grid1->viewport()->size();
    QSize itemIize4 = customLayout->grid1->viewport()->size();

    foreach(auto item, customLayout->scene1->items()) {
        QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        pixItem->setPixmap(QPixmap(itemHash[pixItem]).scaled(itemIize1, Qt::KeepAspectRatio));
        qDebug() << itemHash[pixItem];
//        customLayout->grid1->setAlignment(Qt::AlignCenter);
        customLayout->scene1->setSceneRect(pixItem->sceneBoundingRect());
    }

    foreach(auto item, customLayout->scene2->items()) {
        QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        pixItem->setPixmap(QPixmap(itemHash[pixItem]).scaled(itemIize2, Qt::KeepAspectRatio));
        qDebug() << itemHash[pixItem];
//        customLayout->grid1->setAlignment(Qt::AlignCenter);
        customLayout->scene2->setSceneRect(pixItem->sceneBoundingRect());
    }

    foreach(auto item, customLayout->scene3->items()) {
        QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        pixItem->setPixmap(QPixmap(itemHash[pixItem]).scaled(itemIize3, Qt::KeepAspectRatio));
        qDebug() << itemHash[pixItem];
//        customLayout->grid1->setAlignment(Qt::AlignCenter);
        customLayout->scene3->setSceneRect(pixItem->sceneBoundingRect());
    }

    foreach(auto item, customLayout->scene4->items()) {
        QGraphicsPixmapItem* pixItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        pixItem->setPixmap(QPixmap(itemHash[pixItem]).scaled(itemIize4, Qt::KeepAspectRatio));
        qDebug() << itemHash[pixItem];
//        customLayout->grid1->setAlignment(Qt::AlignCenter);
        customLayout->scene4->setSceneRect(pixItem->sceneBoundingRect());
    }
    qDebug("widget changed");
    qDebug("위젯 변화에 따른 viewport : %d", customLayout->grid1->viewport()->size());
}

void MainWindow::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    if(event->type() == QEvent::WindowStateChange) {                 // 윈도우 창 변경 (최소화, 최대화)
//        customLayout->grid1->viewport()->size();
//        qDebug("window Changed");
//        qDebug("윈도우 사이즈 변화에 따른 viewport : %d", customLayout->grid1->viewport()->size());
    }
}

void MainWindow::DoubleWidget()
{
    qDebug("Double??????");
    customLayout->w = true;
//    QWidget *widget = new QWidget(customLayout);
//    widget->show();
}


void MainWindow::on_imageClearPushButton_clicked()                  // scene 이미지 초기화
{
    customLayout->grid1->scene()->clear();
    customLayout->grid2->scene()->clear();
    customLayout->grid3->scene()->clear();
    customLayout->grid4->scene()->clear();

    cnt = 0;

//    customLayout->grid1->setStyleSheet("border: 0.5px solid rgb(129, 134, 143)");
//    customLayout->grid2->setStyleSheet("border: 0.5px solid rgb(129, 134, 143)");
//    customLayout->grid3->setStyleSheet("border: 0.5px solid rgb(129, 134, 143)");
//    customLayout->grid4->setStyleSheet("border: 0.5px solid rgb(129, 134, 143)");

//    customLayout->scene1->setBackgroundBrush(Qt::black);
//    customLayout->scene2->setBackgroundBrush(Qt::black);
//    customLayout->scene3->setBackgroundBrush(Qt::black);
//    customLayout->scene4->setBackgroundBrush(Qt::black);

    customLayout->g = false;
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
    ui->splitter4->setStyleSheet("background:rgb(32, 56, 100)");
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
    sizes << 10 << 1000;
    ui->splitter->setSizes(sizes);

    QList<int> sizes2;
    sizes2 << 700 << 100;
    ui->splitter2->setSizes(sizes2);

    QList<int> sizes3;
    sizes3 << 10 << 2000;
    ui->splitter3->setSizes(sizes3);

    QList<int> sizes4;
    sizes4 << Qt::MaximumSize << Qt::MinimumSize;
    ui->splitter4->setSizes(sizes4);


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


void MainWindow::customLayoutLocation()
{
    /* grid1(graphicsView) 의 좌표값 */
    int x1 = customLayout->grid1->pos().x();                 // grid1의 topLeft의 x 좌표값
    int y1 = customLayout->grid1->pos().y();                 // grid1의 topLeft의 y 좌표값
    int width1 = x1 + customLayout->grid1->width();          // grid1의 topLeft의 x좌표값에서 grid의 폭만큼 이동한 x의 좌표값
    int height1 = y1 + customLayout->grid1->height();        // grid1의 topLeft의 y 좌표값에서 grid의 높이만큼 이동한 y의 좌표값

    /* grid2(graphicsView) 의 좌표값 */
    int x2 = customLayout->grid2->pos().x();
    int y2 = customLayout->grid2->pos().y();
    int width2 = x2 + customLayout->grid2->width();
    int height2 = y2 + customLayout->grid2->height();

    /* grid3(graphicsView) 의 좌표값 */
    int x3 = customLayout->grid3->pos().x();
    int y3 = customLayout->grid3->pos().y();
    int width3 = x3 + customLayout->grid3->width();
    int height3 = y3 + customLayout->grid3->height();

    /* grid4(graphicsView) 의 좌표값 */
    int x4 = customLayout->grid4->pos().x();
    int y4 = customLayout->grid4->pos().y();
    int width4 = x4 + customLayout->grid4->width();
    int height4 = y4 + customLayout->grid4->height();

    qDebug("grid1의 TopLeft : (%d, %d)", x1, y1);
    qDebug("grid1의 TopRight : (%d, %d)", width1, y1);
    qDebug("grid1의 ButtomLeft : (%d, %d)", x1, height1);
    qDebug("grid1의 ButtomRight : (%d, %d)\n", width1, height1);

    qDebug("grid2의 TopLeft : (%d, %d)", x2, y2);
    qDebug("grid2의 TopRight : (%d, %d)", width2, y2);
    qDebug("grid2의 ButtomLeft : (%d, %d)", x2, height2);
    qDebug("grid2의 ButtomRight : (%d, %d)\n", width2, height2);

    qDebug("grid3의 TopLeft : (%d, %d)", x3, y3);
    qDebug("grid3의 TopRight : (%d, %d)", width3, y3);
    qDebug("grid3의 ButtomLeft : (%d, %d)", x3, height3);
    qDebug("grid3의 ButtomRight : (%d, %d)\n", width3, height3);

    qDebug("grid4의 TopLeft : (%d, %d)", x4, y4);
    qDebug("grid4의 TopRight : (%d, %d)", width4, y4);
    qDebug("grid4의 ButtomLeft : (%d, %d)", x4, height4);
    qDebug("grid4의 ButtomRight : (%d, %d)\n", width4, height4);
}


