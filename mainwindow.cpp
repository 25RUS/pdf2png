#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QStringList>
#include <QPushButton>
#include <QProcess>
#include <QFile>
#include <QDir>
#include <QFileInfoList>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClose, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QProcess *cut = new QProcess();
QProcess *convert = new QProcess();
QProcess *clear = new QProcess();

//PDF selection
void MainWindow::on_pushButton_clicked()
{
    QString pdf;
    pdf = QFileDialog::getOpenFileName(0, "Select PDF", "", "*.pdf");
    ui->lineEdit->setText(pdf);
}


//out dir selection
void MainWindow::on_pushButton_2_clicked()
{
    QString outdir;
    outdir = QFileDialog::getExistingDirectory(
                           this,
                           tr("Select a Directory"),
                           QDir::currentPath() );

               ui->lineEdit_2->setText(outdir);
}


//pdf splitting
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="")
    {
        cut->setWorkingDirectory(ui->lineEdit_2->text());
        cut->start("pdf2svg " + ui->lineEdit->text() + " %d.svg all");
        if(!cut->waitForStarted() || !cut->waitForFinished())
            return;

        QDir sourcedir(ui->lineEdit_2->text());
        QStringList svgs = sourcedir.entryList(QStringList() << "*.svg", QDir::Files);

        for(int i=0; i<svgs.count(); i++)
        {
            QString outfile = QString::number(i+1);
            convert->setWorkingDirectory(ui->lineEdit_2->text());
            convert->start("inkscape " + svgs[i] + " --export-png=" + outfile + ".png");
            if(!convert->waitForStarted() || !convert->waitForFinished())
                return;
            QFile(ui->lineEdit_2->text() + '/' + svgs[i]).remove();
        }
        QMessageBox::information(this, "pdf2png", "converting done!");
    }
    else
       QMessageBox::critical(this, "ERROR!", "Выберете PDF и куда складывать результат!");
}
