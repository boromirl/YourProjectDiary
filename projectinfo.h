#ifndef PROJECTINFO_H
#define PROJECTINFO_H

#include <QDate>
#include <QFile>
#include <QString>
#include <QXmlStreamReader>

class ProjectInfo {
public:
  ProjectInfo();
  ProjectInfo(QString title, QString description, QString status,
              QDate start_date, QDate end_date);
  ProjectInfo(const ProjectInfo &other);

  // accessors
  QString title() const;
  QString description() const;
  QString status() const;
  QDate startDate() const;
  QDate endDate() const;

  // mutators
  void setTitle(const QString title);
  void setDescription(const QString description);
  void setStatus(const QString status);
  void setStartDate(const QDate start_date);
  void setEndDate(const QDate end_date);

  // other methods
  void loadFromXml(QString filePath);

private:
  QString m_title;
  QString m_description;
  QString m_status;

  QDate m_start_date;
  QDate m_end_date;
};

#endif // PROJECTINFO_H
