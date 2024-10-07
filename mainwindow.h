#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDir>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadProjects(); // find XML project files directory and add them to listView



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
