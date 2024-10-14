#ifndef PROJECTDIARY_H
#define PROJECTDIARY_H

#include "diaryentry.h"
#include "projectinfo.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class ProjectDiary {
public:
  ProjectDiary();
  ProjectDiary(ProjectInfo project_info);
  ProjectDiary(const ProjectDiary &other);

  // accessors
  ProjectInfo projectInfo();

  // mutators
  void setProjectInfo(ProjectInfo project_info);

  void loadFromXml(QFile &file);

private:
  ProjectInfo m_project_info;
  QList<DiaryEntry> m_entries;
};

#endif // PROJECTDIARY_H
