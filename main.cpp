#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include <work.h>

#include "MyLib/moc_mycalc.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Work* work = new Work();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("work", work);


    MyCalc* myCalc = new MyCalc();


    qDebug () << myCalc->sum(2,2);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
