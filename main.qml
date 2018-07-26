import QtQuick 2.9
import QtQuick.Controls 2.2 as C2

import "content"
import QtQuick.Layouts 1.0

C2.ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")


    OperationPanel {
        id: operetionPanel

        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        anchors.right: scrollView.left
        anchors.rightMargin: 0

        width: parent.width / 3

    }


    C2.ScrollView {
        id: scrollView

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: scrollViewResult.left
        anchors.rightMargin: 0


        width: parent.width / 3


        ListView {
            id: listView
            width: parent.width
            model: work.listQueueRequests

            delegate: Component {

                Row {
                    id: row

                    Text {
                        id: text1
                        text: index + 1
                        font.pixelSize: 12
                        height: column.height
                    }


                    Column {
                        id: column

                        Rectangle
                        {
                            height: 3;
                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.left: parent.left
                            anchors.leftMargin: 0

                            color: "#52d850"

                        }



                        Text
                        {
                            id: textTimeQML
                            text: "Время: " + work.listQueueRequests[index].timeQML
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                        }


                        Text
                        {
                            text: work.listQueueRequests[index].textWorkQML;
                            font.bold: true
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                        }
                    }

                }

            }

        }
    }




    C2.ScrollView {
        id: scrollViewResult


        width: parent.width / 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0


        ListView {
            id: listViewResult
            width: parent.width
            model: work.listQueueResults

            delegate: Component {

                Row {
                    spacing: 5

                    Text {
                        id: text1
                        text: index + 1
                        font.pixelSize: 12
                        height: column.height
                    }

                    Column {
                        id: column


                        Rectangle
                        {
                            height: 3;
                            color: {
                                if(work.listQueueResults[index].errorCodeQML != "-1")
                                    "#2c4ef9"
                                else
                                    "red"
                            }

                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.left: parent.left
                            anchors.leftMargin: 0

                        }

                        Text
                        {
                            text: "Время: " + work.listQueueResults[index].timeQML
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        }
                        Text
                        {
                            text: work.listQueueResults[index].textWorkQML;
                            font.bold: true
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                        }
                    }
                }

            }
        }
    }
}

/*C2.ItemDelegate {



                text: "Item " + (index + 1)
                width: parent.width
                onClicked: console.log(work.listQueueRequests[index].typeWorkQML)
            }*/
