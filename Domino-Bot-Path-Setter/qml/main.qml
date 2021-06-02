import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

import "controls/"

Window {
    id: mainWindow
    width: 1000
    height: 580

    minimumWidth: 800
    minimumHeight: 500

    visible: true
    color: "#00000000"
    title: qsTr("mainWindow")

    // remove title bar
    flags: Qt.Window | Qt.FramelessWindowHint

    // properties
    property int windowState: 0 // 0 normal, 1 maximized
    property int windowMargin: 10 // 10 normal, 0 maximized

    // function holder
    QtObject {
        id: internal

        function resetResizer() {
            resizeTop.visible = true
            resizeBottom.visible = true
            resizeRight.visible = true
            resizeLeft.visible = true

            resizeTopRight.visible = true
            resizeTopLeft.visible = true
            resizeBottomRight.visible = true
            resizeBottomLeft.visible = true
        }

        function maximizeRestore() {
            // 0 normal
            if (windowState == 0) {
                mainWindow.showMaximized()
                windowState = 1
                windowMargin = 0

                resizeTop.visible = false
                resizeBottom.visible = false
                resizeRight.visible = false
                resizeLeft.visible = false

                resizeTopRight.visible = false
                resizeTopLeft.visible = false
                resizeBottomRight.visible = false
                resizeBottomLeft.visible = false

                resizeIndecator.visible = false

                btnMaximzie.btnIconSource = "../img/svg/restore_icon.svg"
            } else {
                mainWindow.showNormal()
                windowState = 0
                windowMargin = 10

                internal.resetResizer()

                btnMaximzie.btnIconSource = "../img/svg/maximize_icon.svg"
            }
        }

        function maximizeDrag() {
            if (windowState == 1) {
                mainWindow.showNormal()
                windowState = 0
                windowMargin = 10
                btnMaximzie.btnIconSource = "../img/svg/maximize_icon.svg"
                internal.resetResizer()
            }
        }

        function restoreMargin() {
            windowState = 0
            windowMargin = 10

            internal.resetResizer()
        }
    }

    Rectangle {
        id: bg
        color: "#2c313c"
        border.color: "#353b48"
        border.width: 1
        anchors.fill: parent
        anchors.rightMargin: windowMargin
        anchors.leftMargin: windowMargin
        anchors.bottomMargin: windowMargin
        anchors.topMargin: windowMargin
        z: 1

        Rectangle {
            id: appContainer
            color: "#00000000"
            border.color: "#00000000"
            anchors.fill: parent
            anchors.rightMargin: 1
            anchors.leftMargin: 1
            anchors.bottomMargin: 1
            anchors.topMargin: 1

            Rectangle {
                id: topBar
                height: 60
                color: "#1a1d23"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top

                ToggleBtn {
                    onClicked: animationSideBar.running = true
                }

                Rectangle {
                    id: topMenuDescription
                    y: 35
                    height: 25
                    color: bottomBar.color
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.rightMargin: 0
                    anchors.leftMargin: 70
                    anchors.bottomMargin: 0

                    Label {
                        id: labelTopinfo
                        color: "#9eaab2"
                        text: qsTr("App description")
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 300
                        anchors.leftMargin: 10
                    }

                    Label {
                        id: labelTopRightinfo
                        color: "#9eaab2"
                        text: qsTr("| Home")
                        anchors.left: labelTopinfo.right
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 10
                        anchors.leftMargin: 0
                    }
                }

                Rectangle {
                    id: titleBar
                    height: 35
                    color: "#00000000"
                    border.color: "#00000000"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.rightMargin: 105
                    anchors.leftMargin: 70
                    anchors.topMargin: 0

                    DragHandler {
                        onActiveChanged: if (active) {
                                             mainWindow.startSystemMove()
                                             internal.maximizeDrag()
                                         }
                    }

                    Image {
                        id: iconApp
                        width: 22
                        height: 22
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        source: "../img/svg/icon_app_top.svg"
                        anchors.bottomMargin: 0
                        anchors.topMargin: 0
                        anchors.leftMargin: 5
                        fillMode: Image.PreserveAspectFit
                    }

                    Label {
                        id: labelTitle
                        color: "#cad1d6"
                        text: qsTr("Domino Bot Path Setter")
                        anchors.left: iconApp.right
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 13
                        font.family: "Arial"
                        anchors.topMargin: 0
                        anchors.leftMargin: 5
                    }
                }

                Row {
                    id: rowBtns
                    x: 923
                    width: 105
                    height: 35
                    anchors.right: parent.right
                    anchors.top: parent.top

                    TopBarBtn {
                        id: btnMinimize
                        onClicked: {
                            mainWindow.showMinimized()
                            internal.restoreMargin()
                        }
                    }

                    TopBarBtn {
                        id: btnMaximzie
                        btnIconSource: "../img/svg/maximize_icon.svg"
                        onClicked: internal.maximizeRestore()
                    }

                    TopBarBtn {
                        id: btnClose
                        btnColorClicked: "#c2175e"
                        btnIconSource: "../img/svg/close_icon.svg"
                        onClicked: mainWindow.close()
                    }
                }
            }

            Rectangle {
                id: content
                color: "#00000000"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: topBar.bottom
                anchors.bottom: parent.bottom
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0

                Rectangle {
                    id: sideBar
                    width: 70
                    color: "#1a1d23"
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    clip: true

                    PropertyAnimation {
                        id: animationSideBar
                        target: sideBar
                        property: "width"
                        to: sideBar.width == 70 ? 250 : 70
                        duration: 500
                        easing.type: Easing.InOutQuint
                    }

                    Column {
                        id: column
                        width: 250
                        anchors.fill: parent
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 183
                        clip: true

                        LeftMenuBtn {
                            id: btnHome
                            width: sideBar.width
                            text: qsTr("Home")

                            onClicked: {
                                btnHome.isActiveMenu = true
                                homePageView.visible = true

                                btnSettings.isActiveMenu = false
                                settingsPageView.visible = false

                                btnEdit.isActiveMenu = false
                                edittingPageView.visible = false
                            }
                        }

                        LeftMenuBtn {
                            id: btnOpen
                            width: sideBar.width
                            text: qsTr("Open")
                            btnIconSource: "../img/svg/open_icon.svg"
                            isActiveMenu: false
                        }

                        LeftMenuBtn {
                            id: btnSave
                            width: sideBar.width
                            text: qsTr("Save")
                            isActiveMenu: false
                            btnIconSource: "../img/svg/save_icon.svg"
                        }

                        LeftMenuBtn {
                            id: btnEdit
                            width: sideBar.width
                            text: qsTr("Edit")
                            isActiveMenu: false
                            btnIconSource: "../img/svg/save_icon.svg"

                            onClicked: {
                                btnHome.isActiveMenu = false
                                homePageView.visible = false

                                btnSettings.isActiveMenu = false
                                settingsPageView.visible = false

                                btnEdit.isActiveMenu = true
                                edittingPageView.visible = true
                            }
                        }
                    }

                    LeftMenuBtn {
                        id: btnSettings
                        width: sideBar.width
                        text: qsTr("Settings")
                        anchors.bottom: parent.bottom
                        clip: false
                        anchors.bottomMargin: 25
                        isActiveMenu: false
                        btnIconSource: "../img/svg/settings_icon.svg"

                        onClicked: {
                            btnHome.isActiveMenu = false
                            btnSettings.isActiveMenu = true
                            btnEdit.isActiveMenu = false

                            //                            stackView.push(Qt.resolvedUrl(
                            //                                               "pages/SettingsPage.qml"))
                            homePageView.visible = false
                            settingsPageView.visible = true
                            edittingPageView.visible = false
                        }
                    }
                }

                Rectangle {
                    id: contentPages
                    color: "#00000000"
                    anchors.left: sideBar.right
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    clip: true
                    anchors.bottomMargin: 25
                    anchors.leftMargin: 0

                    //                    StackView {
                    //                        id: stackView
                    //                        anchors.fill: parent
                    //                        initialItem: Qt.resolvedUrl("pages/homePage.qml")
                    //                    }
                    Loader {
                        id: homePageView
                        anchors.fill: parent
                        source: Qt.resolvedUrl("pages/homePage.qml")
                        visible: true
                    }

                    Loader {
                        id: settingsPageView
                        anchors.fill: parent
                        source: Qt.resolvedUrl("pages/SettingsPage.qml")
                        visible: false
                    }

                    Loader {
                        id: edittingPageView
                        anchors.fill: parent
                        source: Qt.resolvedUrl("pages/edittingPage.qml")
                        visible: false
                    }
                }

                Rectangle {
                    id: bottomBar
                    color: "#252730"
                    anchors.left: sideBar.right
                    anchors.right: parent.right
                    anchors.top: contentPages.bottom
                    anchors.bottom: parent.bottom
                    anchors.topMargin: 0
                    anchors.leftMargin: 0

                    Label {
                        id: labelBottominfo
                        color: "#9eaab2"
                        text: qsTr("App description")
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 30
                        anchors.leftMargin: 10
                    }

                    Image {
                        id: resizeIndecator
                        x: 891
                        y: 18
                        width: 16
                        height: 16
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        source: "../img/svg/resize_icon.svg"
                        anchors.bottomMargin: 3
                        anchors.rightMargin: 3
                        sourceSize.height: 16
                        sourceSize.width: 16
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }
        }
    }

    DropShadow {
        anchors.fill: bg
        horizontalOffset: 0
        verticalOffset: 0
        radius: 10
        samples: 16
        color: "#80000000"
        source: bg
        z: 0
    }

    MouseArea {
        id: resizeLeft
        width: 10
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        cursorShape: Qt.SizeHorCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(Qt.LeftEdge)
                             }
        }
    }

    MouseArea {
        id: resizeRight
        width: 10
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        cursorShape: Qt.SizeHorCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(Qt.RightEdge)
                             }
        }
    }

    MouseArea {
        id: resizeTop
        height: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.topMargin: 0
        cursorShape: Qt.SizeVerCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(Qt.TopEdge)
                             }
        }
    }

    MouseArea {
        id: resizeBottom
        height: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.topMargin: 0
        cursorShape: Qt.SizeVerCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(Qt.BottomEdge)
                             }
        }
    }

    MouseArea {
        id: resizeBottomRight
        width: 25
        height: 25
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        cursorShape: Qt.SizeFDiagCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(
                                             Qt.BottomEdge | Qt.RightEdge)
                             }
        }
    }

    MouseArea {
        id: resizeBottomLeft
        width: 25
        height: 25
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        cursorShape: Qt.SizeBDiagCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(
                                             Qt.BottomEdge | Qt.LeftEdge)
                             }
        }
    }

    MouseArea {
        id: resizeTopRight
        width: 25
        height: 25
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 0
        anchors.topMargin: 0
        cursorShape: Qt.SizeBDiagCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(
                                             Qt.TopEdge | Qt.RightEdge)
                             }
        }
    }

    MouseArea {
        id: resizeTopLeft
        width: 25
        height: 25
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.topMargin: 0
        cursorShape: Qt.SizeFDiagCursor

        DragHandler {
            target: null
            onActiveChanged: if (active) {
                                 mainWindow.startSystemResize(
                                             Qt.TopEdge | Qt.LeftEdge)
                             }
        }
    }
}
