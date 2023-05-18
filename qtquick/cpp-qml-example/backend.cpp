#include <iostream>
#include "backend.h"

BackEnd::BackEnd(QObject *parent)
    : QObject{parent}
{

}

void BackEnd::setCarName(const QString &name)
{
    std::cout << "setCarName() called" << std::endl;

    if(m_car_name != name)
    {
        m_car_name = name;
        emit carNameChanged();
    }
}

QString BackEnd::getCarName() const
{
    std::cout << "getCarName() called" << std::endl;

    return m_car_name;
}
