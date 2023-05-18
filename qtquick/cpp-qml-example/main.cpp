#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "backend.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    /*
     * Expose BackEnd class to the qml
     * import name: custom.backend
     * import version: 1.0
     * Module name to use in .qml: BackEnd
     *
     * QML will be responsible for creating the instance
     * of BackEnd class and operate on it.
     *
     * @see 'Integrating QML and C++' in the Help section
     * for more info.
    */
    qmlRegisterType<BackEnd>("custom.backend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    
    /*
     * Another way of exposing the C++ functionality to the QML
     * would be to expose the instance of a class created here
     * at the C++ side, instead of just a class.
     *
     * Let's say you create an instance of BackEnd here:
     * BackEnd backend_inst;
     *
     * Then you can pass it to the selected qml:
     * #include <QQmlContext> // to setContextProperty to be recognized properly
     * engine.rootContext()->setContextProperty("main", &backend_inst);
     *
     * And use it from QML by referencing backend_inst:
     * TextField {
     *      text: backend_inst.carName
     * }
     *
     * @see 'Exposing attributes of C++ types to QML' in the Help section
     * for more info.
    */

    // the app would probably work without this connect()
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
