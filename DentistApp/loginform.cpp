#include "loginform.h"
#include "mainwindow.h"
#include "ui_loginform.h"

#include <QMessageBox>
#include <QStackedWidget>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    ui->horizontalSpacer->changeSize(300, 10);
    ui->leftHorizontalSpacer->changeSize(0, 20);
    ui->rightHorizontalSpacer->changeSize(300, 50);

    ui->idLineEdit->setFixedSize(150, 20);
    ui->passwordLineEdit->setFixedSize(150, 20);
    ui->loginToolButton->setFixedSize(50, 50);
    ui->label->resize(500, 700);

    ui->stackedWidget->setStyleSheet("background:rgb(32, 56, 100)");
    ui->idLineEdit->setStyleSheet("background:rgb(255, 255, 255)");
    ui->passwordLineEdit->setStyleSheet("background:rgb(255, 255, 255)");
    ui->loginToolButton->setStyleSheet("background:rgb(255, 255, 255)");

    QList<int> sizes;
    sizes << 1000 << 500;
    ui->splitter->setSizes(sizes);

    QString imagePath(tr(":/trademark/osstem.jpg"));
    ui->label->setPixmap(imagePath);

//    m_window = new MainWindow(this);

//    ui->stackedWidget->insertWidget(1, m_window);
//    ui->stackedWidget->setCurrentWidget(this);

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginToolButton_clicked()
{
    QString DoctorID = ui->idLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    emit sig_login(DoctorID, password);

    t = true;

    qDebug() << "로그인 됩니까?";

    if(true) // 로그인 성공시
        emit sig_loginSuccess(1); // mainWidow로 이동

//    ui->stackedWidget->setCurrentWidget(m_window);













//     if(DoctorID == "osstem1" && password == "1234"){
////         QMessageBox::information(this,"Login","correct");

//     }



//         mainWindow = new MainWindow(this);
//         emit selectUserName(userName);
//         mainWindow->show();
//     }else if(userName == "osstem2" && password == "5678"){
//         QMessageBox::information(this,"Login","correct");
//         hide();
//         mainWindow = new MainWindow(this);
//         emit selectUserName(userName);
//         mainWindow->show();
//     }else{
//         QMessageBox::information(this,"Login","This is not valid. Please try again.");
//     }


}

