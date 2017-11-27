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
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClose, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionLicense, &QAction::triggered, this, &MainWindow::license);
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
        cut->start("pdf2svg \"" + ui->lineEdit->text() + "\" %d.svg all");
        if(!cut->waitForStarted() || !cut->waitForFinished())
            return;

        QDir sourcedir(ui->lineEdit_2->text());
        QStringList svgs = sourcedir.entryList(QStringList() << "*.svg", QDir::Files);

        QProgressDialog* pprd = new QProgressDialog("Progressing the data...", "&Cancel", 0, svgs.count());
        pprd->setMinimumDuration(0);
        pprd->setWindowTitle("Please Wait");

        for(int i=0; i<svgs.count(); i++)
        {
            pprd->setValue(i);
            qApp->processEvents();
            if (pprd->wasCanceled())
            {
                 break;
            }
            QString outfile = QString::number(i+1);
            convert->setWorkingDirectory(ui->lineEdit_2->text());
            convert->start("inkscape \"" + svgs[i] + "\" --export-png=" + outfile + ".png");
            if(!convert->waitForStarted() || !convert->waitForFinished())
                return;
            QFile(ui->lineEdit_2->text() + '/' + svgs[i]).remove(); 
        }
        pprd->setValue(svgs.count()) ;
        delete pprd;
        QMessageBox::information(this, "pdf2png", "converting done!");
    }
    else
       QMessageBox::critical(this, "ERROR!", "Выберете PDF и куда складывать результат!");
}

//about
void MainWindow::about()
{
    QFile readme("/usr/share/doc/pdf2png/README.md");
    QString txt;
    if(readme.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        txt=readme.readAll();
    }
    QMessageBox::information(this, "About", txt);
}

//license
void MainWindow::license()
{
    QFile lic("/usr/share/doc/pdf2png/LICENSE");
    QString txt;
    if(lic.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        txt=lic.readAll();
    }
    QMessageBox::information(this, "License", txt);
}
