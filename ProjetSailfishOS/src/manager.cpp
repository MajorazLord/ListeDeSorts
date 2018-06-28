#include "manager.h"
#include <QtXml>
#include <QFile>
#include <iostream>
#include "spell.h"


bool checkXML(QDomDocument dom){

    QFile xml_doc(":/spells.xml");
    if(!xml_doc.open(QIODevice::ReadOnly))
    {
        cout<< "The document can't be opened. Check the name." << endl;
        return false;

    }
    if (!dom.setContent(&xml_doc)){
            xml_doc.close();
            cout<<"Le document XML n'a pas pu être attribué à l'objet QDomDocument."<<endl;
            return false;
    }
    xml_doc.close();
    return true;
}

QList<Spell*> parserXML(QDomDocument dom){

    QDomElement dom_element = dom.documentElement();
    QDomElement child=dom_element.firstChild().toElement();
    QString name="";
    QString school="";
    QList<QString> listPerso;
    QString range="";
    QString target="";
    QString castingTime="";
    QString summary="";
    QList<Spell*> listSort;
    QString level="";
    QString category="";

    while(!child.isNull())
        if (child.tagName() == "spell")
            {
                school=child.attributeNode("school").value();
              QDomElement grandChild=child.firstChild().toElement();
              while(!grandChild.isNull())
              {
                if (grandChild.tagName() == "name")
                {
                  name=grandChild.text();

                  //cout<<nom.toStdString()<<endl;
                  //cout<<ecole.toStdString()<<endl;
                }
                else if(grandChild.tagName() == "levels"){
                    QDomElement grandgrandChild=grandChild.firstChild().toElement();

                    while(!grandgrandChild.isNull())
                    {
                      if (grandgrandChild.tagName() == "level")
                      {
                        level=grandgrandChild.attributeNode("level").value();
                        category=grandgrandChild.attributeNode("list").value();
                        //cout<<niveau.toStdString()<<endl;
                        //cout<<classe.toStdString()<<endl;
                      }
                      QString valT;
                      valT.append(level);
                      valT.append(":");
                      valT.append(category);
                      listPerso.push_back(valT);
                      grandgrandChild = grandgrandChild.nextSibling().toElement();
                    }
                }
                else if(grandChild.tagName() == "range"){
                    range=grandChild.text();
                    range.append(" ");
                    range.append(grandChild.attributeNode("unit").value());
                    //cout<<portee.toStdString()<<endl;
                }
                else if(grandChild.tagName() == "target"){
                    target=grandChild.text();
                    //cout<<effet.toStdString()<<endl;
                }
                else if(grandChild.tagName() == "castingTime"){
                    castingTime=grandChild.attributeNode("value").value();
                    castingTime.append(" ");
                    castingTime.append(grandChild.attributeNode("unit").value());
                    //cout<<tpsIncantation.toStdString()<<endl;
                }
                else if(grandChild.tagName() == "summary"){
                    summary=grandChild.text();
                    //cout<<resume.toStdString()<<endl;
                }

                grandChild = grandChild.nextSibling().toElement();
              }
              listSort.push_back(new Spell(name, listPerso, school, target, range, castingTime, summary));
              listPerso.clear();
              child = child.nextSibling().toElement();
            }
    return listSort;
}
