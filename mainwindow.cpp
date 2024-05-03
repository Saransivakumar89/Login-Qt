#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/saran/Downloads/codeicon.jpg");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username=="admin"&&password=="admin")
    {
        QMessageBox::information(this,"Login","Correct Credientials");
        hide();
        SecDialog *sec = new SecDialog(this);
        sec->show();
    }
    else
    {
         QMessageBox::warning(this,"Login","InCorrect Credientials");
    }
}

