#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadProjects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadProjects()
{
    // путь до папки с файлами проектов
    QString relativePath = "projects";
    QString projectsDirPath = QCoreApplication::applicationDirPath() + "/" + relativePath;

    QDir dir(projectsDirPath);
    QStringList xmlFiles = dir.entryList(QStringList() << "*.xml", QDir::Files); // список файлов формата xml, Qdir::files указывает, что нужны только файлы

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

    ui->projectListView->setModel(model);
}
