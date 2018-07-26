import QtQuick 2.9

import QtQuick.Controls 2.2 as C2

Item {
    id: name
    property string result: ""

    Rectangle {
        id: resultArea
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height * 3 / 8 - 10
        border.color: "white"
        border.width: 1
        color: "#46a2da"
        Text {
            id: resultText
            anchors.leftMargin: buttons.implicitMargin
            anchors.fill: parent
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            text: "0"
            anchors.rightMargin: 5
            font.pixelSize: 30
            color: "white"
            font.family: "Open Sans Regular"
            fontSizeMode: Text.Fit
        }
    }

    Item {
        id: buttons
        anchors.top: resultArea.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom



        property real implicitMargin: {
            var ret = 0;
            for (var i = 0; i < visibleChildren.length; ++i) {
                var child = visibleChildren[i];
                ret += (child.implicitMargin || 0);
            }
            return ret / visibleChildren.length;
        }


        Repeater {
            id: operations
            model: ["÷", "×", "+", "-"]
            Button {
                y: 0
                x: index * width
                width: parent.width / 4
                height: parent.height / 5
                color: pressed ? "#5caa15" : "#80c342"
                text: modelData
                fontHeight: 0.4
                onClicked: {
                    if(resultText.text == "0")
                    {
                        resultText.text = text;
                        result = text;
                    }
                    else
                    {
                        resultText.text +=text;
                        result += "\t"+text;
                    }
                }

                property string eventName: {
                    switch (text) {
                    case "÷": return "OPER.DIV"
                    case "×": return "OPER.STAR"
                    case "+": return "OPER.PLUS"
                    case "-": return "OPER.MINUS"
                    }
                }
            }
        }

        Repeater {
            id: digits
            model: ["7", "8", "9", "4", "5", "6", "1", "2", "3", "0", ".", "C"]
            Button {
                x: (index % 3) * width
                y: Math.floor(index / 3 + 1) * height
                width: parent.width / 4
                height: parent.height / 5
                color: pressed ? "#d6d6d6" : "#eeeeee"
                text: modelData
                property string eventName: {
                    switch (text) {
                    case ".": return text
                    case "C": resultText.text = "0"; return;
                    default: return text
                    }
                }

                onClicked: {
                    switch (text) {
                        case "C": resultText.text = "0"; return;
                    }

                    if(resultText.text == "0")
                    {
                        resultText.text = text;
                        result = text;
                    }
                    else
                    {
                        resultText.text += text;
                        result +="\t"+text;
                    }
                }


            }
        }

        C2.TextField {
            id: textField
            x: 3 * width
            y: parent.height / 5
            width: parent.width / 4
            height: y
            text: "0"
        }

        Button {
            id: resultButton
            x: 3 * width
            y: parent.height / 2.5
            textHeight: y - 2
            fontHeight: 0.4
            width: parent.width / 4
            height: y *1.5
            color: pressed ? "#e0b91c" : "#face20"
            text: "="
            onClicked: work.qmlAppendQueueRequests(result,textField.text);
        }
    }

}
