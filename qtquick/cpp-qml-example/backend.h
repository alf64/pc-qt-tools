#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT

    // (private) m_car_name will be exposed in QML as a carName
    Q_PROPERTY(QString carName READ getCarName WRITE setCarName NOTIFY carNameChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);
    QString getCarName() const;
    void setCarName(const QString &name);

private:
    QString m_car_name;

signals:
    void carNameChanged();

};

#endif // BACKEND_H
