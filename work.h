#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <QQueue>

#include <QDebug>

#include <item.h>

#include <QLibrary>




class Work : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> listQueueRequests READ listQueueRequests NOTIFY listQueueRequestsChanged)

    Q_PROPERTY(QList<QObject*> listQueueResults READ listQueueResults NOTIFY listQueueResultsChanged)



public:
    explicit Work(QObject *parent = nullptr);

    QList<QObject*> listQueueRequests();
    QList<QObject*> listQueueResults();



signals:
    void listQueueRequestsChanged(QList<QObject*>);
    void listQueueResultsChanged(QList<QObject*>);

public slots:
    void qmlAppendQueueRequests(QString _textWork , QString _time);

    void qmlAppendQueueResults(QString _textWork , QString _time);

private:
    QQueue<QObject*> queueRequests;
    QQueue<QObject*> queueResults;
};

#endif // WORK_H
