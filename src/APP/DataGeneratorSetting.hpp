#ifndef DATAGENERATORSETTING_HPP
#define DATAGENERATORSETTING_HPP

#include <iostream>
#include <fstream>
#include <QSettings>
#include <QFile>

#include "MeasuredObj.hpp"

namespace APP
{
/**
 * @brief The ComponentStyle struct
 *          定义了元件组成方式
 */
struct ComponentStyle
{
    QString componentName; //元件名
    double width; //元件宽
    double height; //元件长
};
/**
 * @brief The ComponentMainItemStyle struct
 *          定义了mainItem的组成方式
 */
struct ComponentMainItemStyle
{
    int id; //序号
    double shiftX; //在x轴上的偏移
    double shiftY; //在y轴上的偏移
    double width; //mainItem宽
    double height; //mainItem长
    double angle; //mainItem角度
};
/**
 *  @brief DataGeneratorSetting
 *          数据生成相关配置信息
 *
 *  @author grace
 *  @version 1.00 2018-01-19 grace
 *                note:create it
 */
class DataGeneratorSetting
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // constructor & destructor

    DataGeneratorSetting();

    virtual ~DataGeneratorSetting();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function

    std::vector<std::vector<ComponentStyle> *> &componentTypesVector() {return m_componentTypesVector;}

    std::vector<QString>& componentTypes() {return m_componentTypes;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member function

    /**
     * @brief load
     *          加载配置文件，如果没有，生成默认配置文件并加载
     * @param path　配置文件所在路径
     */
    void load(const QString& path);

    /**
     * @brief writeDefaultSettingFile
     *          写默认配置文件
     * @param path　配置文件路径
     */
    void writeDefaultSettingFile(const QString& path);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


private:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    std::vector<std::vector<ComponentStyle> *> m_componentTypesVector;//所有元件类型
    std::vector<QString> m_componentTypes; //元件类型大类，例如CHIP,SOP,QFN等

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};
}
#endif // DATAGENERATORSETTING_HPP
