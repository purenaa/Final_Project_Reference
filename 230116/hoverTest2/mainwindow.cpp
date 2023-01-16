#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
        view1_(nullptr),
        view2_(nullptr),
        selectedView_(nullptr)
{
    ui->setupUi(this);
        QGridLayout* grid = new QGridLayout(this->centralWidget());
        view1_ = new QGraphicsView(this);
        view2_ = new QGraphicsView(this);
        grid->addWidget(view1_, 0, 0);
        grid->addWidget(view2_, 0, 1);
        view1_->viewport()->installEventFilter(this);
        view2_->viewport()->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    qDebug() << event->type();
    if (event->type() == QEvent::MouseButtonPress)
    {
        if (watched == view1_->viewport()){
            selectedView_ = view1_;
            QMessageBox::information(this, "!", "First");
            return false;
        }
        else if (watched == view2_->viewport()){
            selectedView_ = view2_;
            QMessageBox::information(this, "!", "Second");
            return false;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
