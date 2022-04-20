#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::PrintPerson(Person obj1)
{
    return obj1.Fio+" : "+obj1.Telephone+"\n";

}

void MainWindow::PrintPersonall(std::vector<Person> book)
{
    ui->textEdit->setPlainText("");
    QString buff;
    for(int i=0;i<book.size();i++)
    {
        buff+=PrintPerson(book[i])+"\n";
    }
   ui->textEdit->setPlainText(buff);
}
void MainWindow::WritetoMedia(std::vector<Person> book)
{
    QString text;
    std::ofstream text1;
  //=====================================
        text1.open("C:/proC/text.txt");//Своё место хранения
  //=====================================
            for(int i=0;i<book.size();i++)
                {
                    text+=PrintPerson(book[i]);
                }
            text1 << text.toStdString();
        text1.close();
}

void MainWindow::on_pushButton_clicked()
{
  Person obj1;
  obj1.Fio=ui->lineEdit->text();
  obj1.Telephone=ui->lineEdit_2->text();
  MainWindow::Notebook.push_back(obj1);
  PrintPersonall(MainWindow::Notebook);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
}
void MainWindow::on_pushButton_2_clicked()
{


    WritetoMedia(MainWindow::Notebook);
    this->close();
}
