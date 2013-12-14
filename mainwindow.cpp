#include "mainwindow.h"
#include <QList>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMimeData>
#include <QFile>
#include <QString>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{





    ui->setupUi(this);
    fileList = new QFileSystemModel(this);
    fileList->setRootPath("/");
    this->setAcceptDrops(true);
 //   ui->groupBox->setFixedHeight(this->height());
   // ui->groupBox_2->setFixedHeight(this->height());
    ui->listView->setModel(fileList);
    ui->listView->setRootIndex(fileList->index(this->PARAM_DROPBOX_PATH));
    connect(ui->listView,SIGNAL(clicked(const QModelIndex)),this,SLOT(doubleClick(QModelIndex)));


}

void MainWindow::doubleClick(QModelIndex index){


    QMessageBox msg;

    QUrl youhome1("http://www.qtcentre.org/forum/");  /* running open browser*/
    QUrl urlFile(index.data().toString());
    //QFileInfo fileInfo (fileList->mimeData(index)->urls().at(0).toLocalFile());//File info
    msg.setText(index.data().toString());
    msg.exec();
  //  QDesktopServices::openUrl(fileList->mimeData(index)->urls().at(0));
    QDesktopServices::openUrl(QUrl("file://"+this->PARAM_DROPBOX_PATH+index.data().toString()));
   //  QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/Aymerick/Dr", QUrl::TolerantMode));
}

void MainWindow::dropEvent(QDropEvent *event){
    QMessageBox msg;
    QString filePath;
    const  QMimeData *data = event->mimeData();
    QList<QUrl> list = data->urls();
    for(int i=0;i<list.length();i++){

         QFileInfo fileInfo(list.at(i).toLocalFile());

        filePath = fileInfo.absoluteFilePath();
        QFile::copy(filePath, "/Users/jo/Dropbox/"+fileInfo.fileName()); //Copy the dropped file to Dropbox Folder

        msg.setText(filePath);
        msg.exec();
        update();
        }


    event->acceptProposedAction();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){

    event->acceptProposedAction();

}



