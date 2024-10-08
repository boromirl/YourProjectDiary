#ifndef PROJECTDIARY_H
#define PROJECTDIARY_H

#include "diaryentry.h"

class ProjectDiary {
public:
  ProjectDiary();
  ProjectDiary(QString title, QString description, QString status,
               QDate start_date, QDate end_date);
  ProjectDiary(const ProjectDiary &other);

  // accessors
  QString title() const;
  QString description() const;
  QString status() const;
  QDate start_date() const;
  QDate end_date() const;

  // mutators
  void setTitle(const QString title);
  void setDescription(const QString description);
  void setStatus(const QString status);
  void setStartDate(const QDate start_date);
  void setEndDate(const QDate end_date);

private:
  QList<DiaryEntry> m_entries;

  QString m_title;
  QString m_description;
  QString m_status;

  QDate m_start_date;
  QDate m_end_date;
};

#endif // PROJECTDIARY_H
