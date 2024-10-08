#ifndef DIARYENTRY_H
#define DIARYENTRY_H

#include <QDate>
#include <QString>
#include <qcontainerfwd.h>

class DiaryEntry {
public:
  DiaryEntry();
  DiaryEntry(QString title, QString content, QDate date);
  DiaryEntry(const DiaryEntry &other);

  // accessors
  QString title() const;
  QString content() const;
  QDate date() const;
  bool hasDate() const;

  // mutators
  void setTitle(const QString &title);
  void setContent(const QString &content);
  void setDate(const QDate &date);

private:
  QString m_title;
  QString m_content;

  QDate m_date;
  bool m_hasDate;
};

#endif // DIARYENTRY_H
