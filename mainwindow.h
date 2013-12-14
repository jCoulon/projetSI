#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDropEvent>
#include <QDragEnterEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


private slots:
    void dropEvent(QDropEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void doubleClick(QModelIndex)  ;
private:
    Ui::MainWindow *ui;
    QFileSystemModel *fileList;
    const QString PARAM_DROPBOX_PATH ="/Users/jo/Dropbox/";

};

#endif // MAINWINDOW_H
