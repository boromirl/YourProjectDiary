#include "projectinfo.h"

// default constructor
ProjectInfo::ProjectInfo() {
  m_title = "No title";
  m_description = "No description";
  m_status = "No status";

  // FIX (Think about dates and checking them)
  // maybe add default dates?
  m_start_date = QDate(2000, 01, 01);
  m_end_date = QDate(2000, 01, 01);
}

// parameter constructor
ProjectInfo::ProjectInfo(QString title, QString description, QString status,
                         QDate start_date, QDate end_date) {
  m_title = title;
  m_description = description;
  m_status = status;
  m_start_date = start_date;
  m_end_date = end_date;
}

// copy constructor
ProjectInfo::ProjectInfo(const ProjectInfo &other) {
  m_title = other.m_title;
  m_description = other.m_description;
  m_status = other.m_status;
  m_start_date = other.m_start_date;
  m_end_date = other.m_end_date;
}

// accessors
QString ProjectInfo::title() const { return m_title; }
QString ProjectInfo::description() const { return m_description; }
QString ProjectInfo::status() const { return m_status; }
QDate ProjectInfo::startDate() const { return m_start_date; }
QDate ProjectInfo::endDate() const { return m_end_date; }

// mutators
void ProjectInfo::setTitle(QString title) { m_title = title; }
void ProjectInfo::setDescription(QString description) {
  m_description = description;
}
void ProjectInfo::setStatus(QString status) { m_status = status; }
void ProjectInfo::setStartDate(QDate start_date) { m_start_date = start_date; }
void ProjectInfo::setEndDate(QDate end_date) { m_end_date = end_date; }

// other methods
void ProjectInfo::loadFromXml(QString filePath) {
  QFile xmlFile(filePath);

  // open a file
  if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Could not open file:" << filePath;
    return;
  }

  QXmlStreamReader xmlReader(&xmlFile);

  // read the xml document
  while (!xmlReader.atEnd() && !xmlReader.hasError()) {
    xmlReader.readNext();

    // process elements
    if (xmlReader.isStartElement()) {
      QString elementName = xmlReader.name().toString();

      if (elementName == "title") {
        m_title = xmlReader.readElementText();
      } else if (elementName == "description") {
        m_description = xmlReader.readElementText();
      } else if (elementName == "status") {
        m_status = xmlReader.readElementText();
      }
    }
  }

  // Check for errors
  if (xmlReader.hasError()) {
    qWarning() << "XML error:" << xmlReader.errorString();
  }

  // Always close the file
  xmlFile.close();
}
