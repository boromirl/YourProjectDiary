#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  loadProjects();

  // соединяем модель (1), сигнал модели (2), классЮ которому принадлежит сигнал
  // (3), и метод-триггер (4)
  connect(ui->projectListView->selectionModel(),
          &QItemSelectionModel::selectionChanged, this,
          &MainWindow::onSelectionChanged);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::loadProjects() {
  // путь до папки с файлами проектов
  QString relativePath = "projects";
  QString projectsDirPath =
      QCoreApplication::applicationDirPath() + "/" + relativePath;

  QDir dir(projectsDirPath);
  QStringList xmlFiles =
      dir.entryList(QStringList() << "*.xml",
                    QDir::Files); // список файлов формата xml, Qdir::files
                                  // указывает, что нужны только файлы

  // // список имен файлов
  // QStringList xmlFileInfo;
  // foreach (const QString &filename, xmlFiles) {
  //   QFileInfo fileInfo(dir, filename);
  //   xmlFileInfo.append(fileInfo.baseName());
  // }

  foreach (const QString &filename, xmlFiles) {
    ProjectInfo info = ProjectInfo();
    info.loadFromXml(projectsDirPath + "/" + filename);
    projectInfoList.append(info);
  }

  // добавление имен файлов в модель
  QStandardItemModel *model = new QStandardItemModel;
  foreach (const ProjectInfo &projectInfo, projectInfoList) {
    QStandardItem *item = new QStandardItem(projectInfo.title());
    model->appendRow(item);
  }

  // вывод модели в виде списка
  ui->projectListView->setModel(model);
}

void MainWindow::onSelectionChanged(const QItemSelection &selected,
                                    const QItemSelection &deselected) {
  if (!selected.indexes().isEmpty()) {
    QString selectedItem = selected.indexes().first().data().toString();
    int projectIndex = findProjectIndexByTitle(projectInfoList, selectedItem);
    displayProjectInfo(projectInfoList[projectIndex]);
  }
}

void MainWindow::displayProjectInfo(ProjectInfo info) {
  ui->projectTitleLineEdit->setText(info.title());
  ui->projectDescriptionLineEdit->setText(info.description());
  ui->projectStatusLineEdit->setText(info.status());
}

// FIX (what if the same title?)
int findProjectIndexByTitle(QList<ProjectInfo> projectList, QString title) {
  int ind = -1;
  for (int i = 0; i < projectList.size(); i++) {
    if (projectList[i].title() == title) {
      ind = i;
      break;
    }
  }

  return ind;
}
