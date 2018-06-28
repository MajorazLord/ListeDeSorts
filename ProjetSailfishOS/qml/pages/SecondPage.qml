import QtQuick 2.0
import Sailfish.Silica 1.0
import SpellModel 1.0

Page {
    id: page

    property var spellSelected;

    PageHeader {
        title: "Spell Info"
        id: header
    }

    Column {
        anchors.top: header.bottom
        width: parent.width

        TextField {
            text: spellSelected.name
            label: "SpellName"
            width: parent.width
        }
        TextField {
            text: spellSelected.characters
            label: "Characters"
            width: parent.width
        }
        TextField {
            text: spellSelected.school
            label: "School"
            width: parent.width
        }
        TextField {
            text: spellSelected.target
            label: "Target"
            width: parent.width
        }
        TextField {
            text: spellSelected.range
            label: "Range"
            width: parent.width
        }
        TextField {
            text: spellSelected.castingTime
            label: "CastingTime"
            width: parent.width
        }
        TextField {
            text: spellSelected.summary
            label: "Summary"
            width: parent.width
        }
    }
}
