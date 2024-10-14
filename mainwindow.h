#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QItemSelection>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "projectdiary.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QList<ProjectInfo> projectInfoList;

  void addProject(ProjectDiary project);

  void
  loadProjects(); // find XML project files directory and add them to listView
  void displayProjectInfo(
      ProjectInfo info); // display info about project in lineEdits

private slots:
  void onSelectionChanged(const QItemSelection &selected,
                          const QItemSelection &deselected);

private:
  Ui::MainWindow *ui;
};

int findProjectIndexByTitle(QList<ProjectInfo> projectList, QString title);
#endif // MAINWINDOW_H
