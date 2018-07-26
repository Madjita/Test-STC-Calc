#ifndef ITEM_H
#define ITEM_H

#include <QObject>

#include <QDebug>

#include <QThread>
#include <QTimer>




class Item : public QObject
{
    Q_OBJECT
public:


    explicit Item(QString _textWork, int _time = 0, QObject *parent = nullptr); // ,int _typeWork, double _operandA, double _operandB, int _errorCode = 0,

    explicit Item(QString _textWork, int _time = 0, int _errorCode = 0, QObject *parent = nullptr);

    Q_PROPERTY(QString textWorkQML READ textWorkQML NOTIFY textWorkQMLChanged)
    QString  textWorkQML();

    Q_PROPERTY(int operandAQML READ operandAQML NOTIFY operandAChanged)
    double operandAQML();

    Q_PROPERTY(int operandBQML READ operandBQML NOTIFY operandBChanged)
    double operandBQML();

    Q_PROPERTY(QString errorCodeQML READ errorCodeQML NOTIFY errorCodeChanged)
    QString errorCodeQML();

    Q_PROPERTY(QString timeQML READ timeQML NOTIFY timeChanged)
    QString timeQML();

signals:
    void textWorkQMLChanged(QString);
    void operandAChanged(double);
    void operandBChanged(double);
    void errorCodeChanged(QString);
    void timeChanged(QString);

    void addQueueResult(QString,QString);

public slots:
   void process_start();

   void working();

private:
    QString textWork;
    int typeWork;
    double operandA;
    double operandB;
    int errorCode;
    int time;

    QTimer* timer;
};

#endif // ITEM_H
