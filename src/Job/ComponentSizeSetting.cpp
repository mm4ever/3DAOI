#include "ComponentSizeSetting.hpp"

using namespace Job;
using namespace std;

ComponentSizeSetting::ComponentSizeSetting()
{

}

ComponentSizeSetting::~ComponentSizeSetting()
{

}

//void ComponentSizeSetting::load(const QString &path)
//{
////    if(!QFile::exists(path))
////    {
////        cout << "元件尺寸配置文件不存在，写入默认配置文件" << endl;
////        write(path);
////    }
//    QSettings settings(path, QSettings::IniFormat);
//    QList<QString> componentType; //6种类型
//    QList<ComponentStyle> *pComponentType;

//    //６种类型名存到QList中
//    int componentTypeCnt = settings.beginReadArray("COMPONENT_TYPE");
//    QString str;
//    for (int i = 0; i < componentTypeCnt; ++i)
//    {
//        settings.setArrayIndex(i);
//        str = settings.value("componentType").toString();
//        componentType.append(str);
//    }
//    settings.endArray();

//    //为每个类型的元件创建一个QList
//    ComponentStyle ic;
//    int compCnt=0;
//    for (int i = 0; i < componentTypeCnt; ++i)
//    {
//        cout << componentType[i].toStdString() << endl;
//        compCnt = settings.beginReadArray(componentType[i]);
//        cout << compCnt << endl;
//        pComponentType = new QList<ComponentStyle>;
//        for (int i = 0; i < compCnt; ++i)
//        {
//            settings.setArrayIndex(i);
//            ic.componentName = settings.value("componentName").toString();
//            ic.width = settings.value("width").toDouble();
//            ic.height = settings.value("height").toDouble();
//            pComponentType->append(ic);
//        }
//        m_componentsLst.append(pComponentType);
//        settings.endArray();
//    }
//}

//void ComponentSizeSetting::write(const QString &path)
//{
//    QList<ComponentStyle> CHIP,IC;
//    ComponentStyle chip01005,chip0201,chip0402,chip0603,chip0805,chip1206,
//            SOP8,SOP14,SOP16,SOP18,SOP20,SOP24,SOP28,SOP30,
//            SOT363,SOT353,SOT23,SOT323,SOT552,SOT663,SOT666,
//            QFN24,QFN32,QFN28,QFN48,
//            QFP44,QFP52,QFP64,LQFP32,LQFP44,LQFP48,LQFP64,LQFP80,LQFP100,LQFP128,
//            BGA40,BGA56,BGA84,BGA96,BGA132,BGA484;

//    //chip
//    chip01005.componentName = "chip01005";
//    chip01005.width = 0.4;
//    chip01005.height = 0.2;
//    CHIP.push_back(chip01005);

//    chip0201.componentName = "chip0201";
//    chip0201.width = 0.6;
//    chip0201.height = 0.3;
//    CHIP.push_back(chip0201);

//    chip0402.componentName = "chip0402";
//    chip0402.width = 1.0;
//    chip0402.height = 0.5;
//    CHIP.push_back(chip0402);

//    chip0603.componentName = "chip0603";
//    chip0603.width = 1.6;
//    chip0603.height = 0.8;
//    CHIP.push_back(chip0603);

//    chip0805.componentName = "chip0805";
//    chip0805.width = 2.0;
//    chip0805.height = 1.25;
//    CHIP.push_back(chip0805);

//    chip1206.componentName = "chip1206";
//    chip1206.width = 3.2;
//    chip1206.height = 1.6;
//    CHIP.push_back(chip1206);

//    //ic
//    SOP8.componentName = "SOP8";
//    SOP8.width = 6.0;
//    SOP8.height = 5.0;
//    IC.push_back(SOP8);

//    SOP14.componentName = "SOP14";
//    SOP14.width = 6.0;
//    SOP14.height = 8.5;
//    IC.push_back(SOP14);

//    SOP16.componentName = "SOP16";
//    SOP16.width = 6.0;
//    SOP16.height = 10.0;
//    IC.push_back(SOP16);

//    SOP18.componentName = "SOP18";
//    SOP18.width = 10.3;
//    SOP18.height = 11.5;
//    IC.push_back(SOP18);

//    SOP20.componentName = "SOP20";
//    SOP20.width = 10.3;
//    SOP20.height = 12.7;
//    IC.push_back(SOP20);

//    SOP24.componentName = "SOP24";
//    SOP24.width = 10.3;
//    SOP24.height = 15.4;
//    IC.push_back(SOP24);

//    SOP28.componentName = "SOP28";
//    SOP28.width = 10.3;
//    SOP28.height = 17.7;
//    IC.push_back(SOP28);

//    SOP30.componentName = "SOP30";
//    SOP30.width = 10.3;
//    SOP30.height = 19.0;
//    IC.push_back(SOP30);

//    SOT363.componentName = "SOT363";
//    SOT363.width = 2.1;
//    SOT363.height = 2.3;
//    IC.push_back(SOT363);

//    SOT353.componentName = "SOT353";
//    SOT353.width = 2.1;
//    SOT353.height = 2.3;
//    IC.push_back(SOT353);

//    SOT23.componentName = "SOT23";
//    SOT23.width = 2.1;
//    SOT23.height = 2.9;
//    IC.push_back(SOT23);

//    SOT323.componentName = "SOT323";
//    SOT323.width = 2.1;
//    SOT323.height = 2.1;
//    IC.push_back(SOT323);

//    SOT552.componentName = "SOT552";
//    SOT552.width = 5.0;
//    SOT552.height = 3.0;
//    IC.push_back(SOT552);

//    SOT663.componentName = "SOT663";
//    SOT663.width = 1.6;
//    SOT663.height = 1.6;
//    IC.push_back(SOT663);

//    SOT666.componentName = "SOT666";
//    SOT666.width = 1.6;
//    SOT666.height = 1.6;
//    IC.push_back(SOT666);

//    QFN24.componentName = "QFN24";
//    QFN24.width = 4.0;
//    QFN24.height = 4.0;
//    IC.push_back(QFN24);

//    QFN32.componentName = "QFN32";
//    QFN32.width = 5.0;
//    QFN32.height = 5.0;
//    IC.push_back(QFN32);

//    QFN28.componentName = "QFN28";
//    QFN28.width = 5.0;
//    QFN28.height = 5.0;
//    IC.push_back(QFN28);

//    QFN48.componentName = "QFN48";
//    QFN48.width = 5.0;
//    QFN48.height = 5.0;
//    IC.push_back(QFN48);

//    QFP44.componentName = "QFP44";
//    QFP44.width = 13.5;
//    QFP44.height = 13.5;
//    IC.push_back(QFP44);

//    QFP52.componentName = "QFP52";
//    QFP52.width = 17.2;
//    QFP52.height = 17.2;
//    IC.push_back(QFP52);

//    QFP64.componentName = "QFP64";
//    QFP64.width = 17.2;
//    QFP64.height = 17.2;
//    IC.push_back(QFP64);

//    LQFP32.componentName = "LQFP32";
//    LQFP32.width = 9.0;
//    LQFP32.height = 9.0;
//    IC.push_back(LQFP32);

//    LQFP44.componentName = "LQFP44";
//    LQFP44.width = 12.0;
//    LQFP44.height = 12.0;
//    IC.push_back(LQFP44);

//    LQFP48.componentName = "LQFP48";
//    LQFP48.width = 9.0;
//    LQFP48.height = 9.0;
//    IC.push_back(LQFP48);

//    LQFP64.componentName = "LQFP64";
//    LQFP64.width = 9.0;
//    LQFP64.height = 9.0;
//    IC.push_back(LQFP64);

//    LQFP80.componentName = "LQFP80";
//    LQFP80.width = 14.0;
//    LQFP80.height = 14.0;
//    IC.push_back(LQFP80);

//    LQFP100.componentName = "LQFP100";
//    LQFP100.width = 16.0;
//    LQFP100.height = 16.0;
//    IC.push_back(LQFP100);

//    LQFP128.componentName = "LQFP128";
//    LQFP128.width = 16.0;
//    LQFP128.height = 16.0;
//    IC.push_back(LQFP128);

//    BGA40.componentName = "BGA40";
//    BGA40.width = 5.0;
//    BGA40.height = 5.0;
//    IC.push_back(BGA40);

//    BGA56.componentName = "BGA56";
//    BGA56.width = 6.0;
//    BGA56.height = 6.0;
//    IC.push_back(BGA56);

//    BGA84.componentName = "BGA84";
//    BGA84.width = 7.0;
//    BGA84.height = 7.0;
//    IC.push_back(BGA84);

//    BGA96.componentName = "BGA96";
//    BGA96.width = 8.0;
//    BGA96.height = 8.0;
//    IC.push_back(BGA96);

//    BGA132.componentName = "BGA132";
//    BGA132.width = 8.0;
//    BGA132.height = 8.0;
//    IC.push_back(BGA132);

//    BGA484.componentName = "BGA484";
//    BGA484.width = 12.0;
//    BGA484.height = 12.0;
//    IC.push_back(BGA484);

//    //    QString path = "./ini/component.ini";
//    QSettings settings(path, QSettings::IniFormat);

//    settings.beginWriteArray("CHIP");
//    for (int i = 0; i < CHIP.size(); ++i)
//    {
//        settings.setArrayIndex(i);
//        settings.setValue("componentName", CHIP.at(i).componentName);
//        settings.setValue("width", CHIP.at(i).width);
//        settings.setValue("height", CHIP.at(i).height);
//    }
//    settings.endArray();
//    settings.beginWriteArray("IC");
//    for (int i = 0; i < IC.size(); ++i)
//    {
//        settings.setArrayIndex(i);
//        settings.setValue("componentName", IC.at(i).componentName);
//        settings.setValue("width", IC.at(i).width);
//        settings.setValue("height", IC.at(i).height);
//    }
//    settings.endArray();
//}

////void ComponentSizeSetting::read(const QString &path)
////{
////    QList<ComponentStyle> Chip,Ic;
////    QSettings settings(path, QSettings::IniFormat);
////    int chipTypeCnt = settings.beginReadArray("CHIP");
////    for (int i = 0; i < chipTypeCnt; ++i)
////    {
////        settings.setArrayIndex(i);
////        ComponentStyle chip;
////        chip.componentName = settings.value("componentName").toString();
////        chip.width = settings.value("width").toDouble();
////        chip.height = settings.value("height").toDouble();
////        Chip.append(chip);
////    }
////    settings.endArray();
////    int icTypeCnt = settings.beginReadArray("IC");
////    for (int i = 0; i < icTypeCnt; ++i)
////    {
////        settings.setArrayIndex(i);
////        ComponentStyle ic;
////        ic.componentName = settings.value("componentName").toString();
////        ic.width = settings.value("width").toDouble();
////        ic.height = settings.value("height").toDouble();
////        Ic.append(ic);
////    }
////    settings.endArray();

////    for (int i = 0; i < Chip.size(); ++i)
////    {
////        cout << Chip[i].componentName.toStdString() << endl;
////        cout << Chip[i].width << endl;
////        cout << Chip[i].height << endl;

////        cout << Ic[i].componentName.toStdString() << endl;
////        cout << Ic[i].width << endl;
////        cout << Ic[i].height << endl;
////    }
////}
