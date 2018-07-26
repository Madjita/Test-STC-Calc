#include "item.h"

//, int _typeWork, double _operandA, double _operandB, int _errorCode,

Item::Item(QString _textWork, int _time, int _errorCode, QObject *parent):
    QObject(parent),
    textWork(""),
    typeWork(0),
    operandA(0),
    operandB(0),
    errorCode(0),
    time(0)
{
     textWork = _textWork;
     time = _time;
     errorCode = _errorCode;

     emit textWorkQMLChanged(textWork);
     emit timeChanged(QString::number(time));
     emit errorCodeChanged(QString::number(errorCode));
}

Item::Item(QString _textWork, int _time, QObject *parent):
    QObject(parent),
    textWork(""),
    typeWork(0),
    operandA(0),
    operandB(0),
    errorCode(0),
    time(0)
{

    textWork = _textWork;
    time = _time;

    emit textWorkQMLChanged(textWork);
    emit timeChanged(QString::number(time));

    timer = new QTimer();

    QObject::connect(timer,&QTimer::timeout,this,&Item::working);

    timer->start(1000);
}

QString Item::textWorkQML()
{
//    QString type;

//    switch (typeWork) {
//    case 1: type = "÷"; break;
//    case 2: type = "×"; break;
//    case 3: type = "+"; break;
//    case 4: type = "-"; break;
//    default: type = "";

//    }

    return textWork;
}

double Item::operandAQML()
{
    return operandA;
}

double Item::operandBQML()
{
    return operandB;
}

QString Item::errorCodeQML()
{
    return QString::number(errorCode);
}

QString Item::timeQML()
{
    return QString::number(time);
}

void Item::process_start()
{



}

void Item::working()
{
    if(time == 0 )
    {
       timer->stop();

       emit addQueueResult(textWork, QString::number(time));

       return;
    }

    qDebug () << time;

    time--;
    emit timeChanged(QString::number(time));
}

