#include "work.h"

Work::Work(QObject *parent) : QObject(parent)
{

}

QList<QObject*> Work::listQueueRequests()
{
    return queueRequests;
}

QList<QObject *> Work::listQueueResults()
{
    return queueResults;
}

void Work::qmlAppendQueueRequests(QString _textWork, QString _time)
{


    QList<QString> list = _textWork.split("\t");

    _textWork.clear();

    foreach(QString l, list)
    {
        qDebug () << "List: " << list;
        _textWork += l;
    }



    queueRequests.append(new Item(_textWork,_time.toInt(),this));

    connect(static_cast<Item*>(queueRequests.last()),&Item::addQueueResult ,this,&Work::qmlAppendQueueResults);

    emit listQueueRequestsChanged(queueRequests);
}

void Work::qmlAppendQueueResults(QString _textWork, QString _time)
{
    Item* obj = static_cast<Item*>(sender());

    disconnect(obj,&Item::addQueueResult ,this,&Work::qmlAppendQueueResults);

    if(!queueRequests.isEmpty())
    {
        queueRequests.removeOne(obj);
        emit listQueueRequestsChanged(queueRequests);
    }


    //Проверка на правильность


    QStringList listDel = _textWork.split("÷"); //÷×+-
    QStringList listMn = _textWork.split("×");
    QStringList listPl = _textWork.split("+");
    QStringList listMin = _textWork.split("-");


    foreach(QString l, listDel)
    {
        qDebug () << l;
    }

    foreach(QString l, listMn)
    {
        qDebug () << l;
    }

    foreach(QString l, listPl)
    {
        qDebug () << l;
    }

    foreach(QString l, listMin)
    {
        qDebug () << l;
    }


    queueResults.append(new Item(_textWork,_time.toInt(),-1));


    emit listQueueResultsChanged(queueResults);
}
