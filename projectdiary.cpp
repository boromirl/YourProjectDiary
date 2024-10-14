#include "projectdiary.h"

// default constructor
ProjectDiary::ProjectDiary() { m_project_info = ProjectInfo(); }

// parameter constructor
ProjectDiary::ProjectDiary(ProjectInfo info) { m_project_info = info; }

// copy constructor
ProjectDiary::ProjectDiary(const ProjectDiary &other) {
  m_project_info = other.m_project_info;
}

// void ProjectDiary::loadFromXml(QFile &file) {
//   QXmlStreamReader xmlReader;
//   xmlReader.setDevice(&file);

//   // read the XML document
//   while (!xmlReader.atEnd() && !xmlReader.hasError()) {
//     xmlReader.readNext();

//     // process elements
//     if (xmlReader.isStartElement()) {
//       QString element_name = xmlReader.name().toString();

//       if (element_name == "title") {
//         m_title = xmlReader.text().toString();
//       } else if (element_name == "description") {
//         m_description = xmlReader.text().toString();
//       } else if (element_name == "status") {
//         m_status = xmlReader.text().toString();
//       }
//     }
//   }
// }
