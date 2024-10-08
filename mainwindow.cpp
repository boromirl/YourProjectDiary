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

  // список имен файлов
  QStringList xmlFileInfo;
  foreach (const QString &filename, xmlFiles) {
    QFileInfo fileInfo(dir, filename);
    xmlFileInfo.append(fileInfo.baseName());
  }

  // добавление имен файлов в модель
  QStandardItemModel *model = new QStandardItemModel;
  foreach (const QString &file, xmlFileInfo) {
    QStandardItem *item = new QStandardItem(file);
    model->appendRow(item);
  }

  // вывод модели в виде списка
  ui->projectListView->setModel(model);
}

void MainWindow::onSelectionChanged(const QItemSelection &selected,
                                    const QItemSelection &deselected) {
  if (!selected.indexes().isEmpty()) {
    QString selectedItem = selected.indexes().first().data().toString();
    displayProjectInfo(selectedItem);
  }
}

void MainWindow::displayProjectInfo(QString projectName) {
  // FIX  (сделать переменную с папкой проектов?)
  // создаем объект с именем файла проекта
  QFile file("projects/" + projectName + ".xml");

  // FIX (сделать окно с ошибкой)
  // открываем файл для чтения с проверкой
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file" << file.errorString();
    return;
  }

  QXmlStreamReader reader(&file);
}
