#include "projectdiary.h"

// default constructor
ProjectDiary::ProjectDiary() {
  m_title = "No title";
  m_description = "No description";
  m_status = "No status";

  // FIX (Think about dates and checking them)
  // maybe add default dates?
  m_start_date = QDate(2000, 01, 01);
  m_end_date = QDate(2000, 01, 01);
}

// parameter constructor
ProjectDiary::ProjectDiary(QString title, QString description, QString status,
                           QDate start_date, QDate end_date) {
  m_title = title;
  m_description = description;
  m_status = status;
  m_start_date = start_date;
  m_end_date = end_date;
}

// copy constructor
ProjectDiary::ProjectDiary(const ProjectDiary &other) {
  // FIX (maybe add copyData() method?
  m_title = other.m_title;
  m_description = other.m_description;
  m_status = other.m_status;
  m_start_date = other.m_start_date;
  m_end_date = other.m_end_date;
}

// accessors
QString ProjectDiary::title() const { return m_title; }
QString ProjectDiary::description() const { return m_description; }
QString ProjectDiary::status() const { return m_status; }
QDate ProjectDiary::start_date() const { return m_start_date; }
QDate ProjectDiary::end_date() const { return m_end_date; }

// mutators
void ProjectDiary::setTitle(const QString title) { m_title = title; }
void ProjectDiary::setDescription(const QString description) {
  m_description = description;
}
void ProjectDiary::setStatus(const QString status) { m_status = status; }
void ProjectDiary::setStartDate(const QDate start_date) {
  m_start_date = start_date;
}
void ProjectDiary::setEndDate(const QDate end_date) { m_end_date = end_date; }
