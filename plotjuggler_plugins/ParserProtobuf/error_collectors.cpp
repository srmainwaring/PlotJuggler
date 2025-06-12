#include "error_collectors.h"
#include <QMessageBox>
#include <QDebug>

void FileErrorCollector::RecordError(absl::string_view filename, int line, int,
                                  absl::string_view message)
{
  auto msg = QString("File: [%1] Line: [%2] Message: %3\n\n")
                 .arg(QString::fromStdString(filename.data()))
                 .arg(line)
                 .arg(QString::fromStdString(message.data()));

  _errors.push_back(msg);
}

void FileErrorCollector::RecordWarning(absl::string_view filename, int line, int,
                                    absl::string_view message)
{
  auto msg = QString("Warning [%1] line %2: %3")
                 .arg(QString::fromStdString(filename.data()))
                 .arg(line)
                 .arg(QString::fromStdString(message.data()));
  qDebug() << msg;
}

void IoErrorCollector::RecordError(int line, google::protobuf::io::ColumnNumber column,
                                   absl::string_view message)
{
  _errors.push_back(
      QString("Line: [%1] Message: %2\n").arg(line).arg(QString::fromStdString(message.data())));
}

void IoErrorCollector::RecordWarning(int line, google::protobuf::io::ColumnNumber column,
                                     absl::string_view message)
{
  qDebug() << QString("Line: [%1] Message: %2\n")
                  .arg(line)
                  .arg(QString::fromStdString(message.data()));
}

