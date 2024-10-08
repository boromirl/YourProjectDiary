#include "diaryentry.h"

// default constructor
DiaryEntry::DiaryEntry() {
  m_title = "Empty";
  m_content = "Empty";

  m_hasDate = false;
  m_date = QDate(2000, 13, 1); // invalid date with 13 months
}

// pararmeter constructor
DiaryEntry::DiaryEntry(QString title, QString content, QDate date) {
  m_title = title;
  m_content = content;

  // FIX ?    Maybe add exception on invalid date
  if (date.isValid()) {
    m_hasDate = true;
  } else {
    m_hasDate = false;
  }

  m_date = date;
}

// copy constructor
DiaryEntry::DiaryEntry(const DiaryEntry &other) {
  m_title = other.m_title;
  m_content = other.m_content;
  m_date = other.m_date;
  m_hasDate = other.m_hasDate;
}

// accessors
QString DiaryEntry::title() const { return m_title; }
QString DiaryEntry::content() const { return m_content; }
QDate DiaryEntry::date() const { return m_date; }
bool DiaryEntry::hasDate() const { return m_hasDate; }

// mutators
void DiaryEntry::setTitle(const QString &title) { m_title = title; }

void DiaryEntry::setContent(const QString &content) { m_content = content; }

void DiaryEntry::setDate(const QDate &date) {
  if (date.isValid()) {
    m_hasDate = true;
  } else {
    m_hasDate = false;
  }
  m_date = date;
}
