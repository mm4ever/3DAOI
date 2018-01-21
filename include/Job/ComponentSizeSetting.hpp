#ifndef COMPONENTSIZESETTING_HPP
#define COMPONENTSIZESETTING_HPP


#include <iostream>
#include <fstream>
#include <QSettings>
#include <QFile>

namespace Job
{
struct ComponentStyle
{
    QString componentName;
    double width;
    double height;
};

class ComponentSizeSetting
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    ComponentSizeSetting();
    virtual ~ComponentSizeSetting();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function

    int componentIndex() const {return m_componentIndex;}
    void setComponentIndex(int componentIndex) {m_componentIndex = componentIndex;}

    int componentHeight() const {return m_componentHeight;}
    void setComponentHeight(int componentHeight) {m_componentHeight = componentHeight;}

    int componentWidth() const {return m_componentWidth;}
    void setComponentWidth(int componentWidth) {m_componentWidth = componentWidth;}

    QList<QList<ComponentStyle> *> &componentsLst() {return m_componentsLst;}
    void setComponentsLst(const QList<QList<ComponentStyle> *> &componentsLst) {m_componentsLst = componentsLst;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member function

//    void load(const QString& path);
//    void write(const QString& path);
//    void read(const QString& path);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


private:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    int m_componentIndex{0};
    int m_componentWidth{0};
    int m_componentHeight{0};

    QList<QList<ComponentStyle> *> m_componentsLst;

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};

}

#endif // COMPONENTSIZESETTING_HPP
