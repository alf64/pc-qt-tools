
import QtQuick 2.6
import QtQuick.Controls 2.0
import custom.backend 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    BackEnd {
        id: backend
    }

    TextField {
        // displayed text (getCarName() will be called)
        text: backend.carName

        // initial text
        placeholderText: qsTr("enter car name")
        anchors.centerIn: parent

        // WRITE the carName (setCarName() will be called)
        onTextChanged: backend.carName = text
    }
}

