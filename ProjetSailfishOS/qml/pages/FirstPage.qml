import QtQuick 2.0
import Sailfish.Silica 1.0
import SpellModel 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Add Spell")
                onClicked: listView.model.newElement()
            }
        }

        header: PageHeader { title: qsTr("All Spells")   }

        model: SpellModel { spell: spellListFromXml }
        delegate:
            ListItem {
                width: listView.width
                Label{
                    text: name
                }
                onClicked: pageStack.push(spellPage, {spellSelected: spell})
                Component{
                    id: spellPage
                    SecondPage{}
                }
            }


        VerticalScrollDecorator {}
    }
}
