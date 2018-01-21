#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include "Job/InspectionData.hpp"
#include "Job/Board.hpp"
#include "Job/FiducialMark.hpp"
#include "Job/Component.hpp"
#include "DataGeneratorSetting.hpp"
#include "SSDK/FormatConvertor.hpp"

namespace APP
{
/**
 *  @brief DataGenerator
 *          此类中相关函数生成项目所有数据
 *
 *  @author grace
 *  @version 1.00 2018-01-08 grace
 *                note:create it
 */
class DataGenerator
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    DataGenerator();

    virtual ~DataGenerator();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function

    DataGeneratorSetting &getDataSetting() {return m_dataSetting;}
    void setDataSetting(const DataGeneratorSetting &dataSetting) {m_dataSetting = dataSetting;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // member function

    /**
     * @brief getCurrentTime
     *          获取当前时间．格式：＂20180119103513＂
     * @return 当前时间（字符串）
     */
    static std::string getCurrentTime();

    /**
     * @brief getName 获取名字，拼接字符串和整形．结果是"字符串＿整形"
     * @param iVar　名字拼接的一部分
     * @param style　名字拼接的一部分
     * @return　生成的名字
     */
    std::string getName(int iVar,string sVar);

    /**
     * @brief check 判断元件是否交叉重叠
     * @param centralX　新元件中心点x坐标
     * @param centralY　新元件中心点y坐标
     * @param width 新元件的宽度
     * @param height　新元件的高度
     * @param pObjs　存在的元件数组
     * @return　两种返回值：false：交叉或者重叠
     *                  　ture：不交叉且不重叠
     */
    bool check(double centralX, double centralY,
               double width, double height,
               std::vector<Job::MeasuredObj*> pObjs);

    /**
     * @brief generateBoardData
     *          生成基板数据。具体信息如下：
     *              1.board（基板）：板名，原点坐标（X、Y）,长、宽
     *              2.objCnt个元件：
     *                  2.1 2个Mark（基准点）：名字、中心点坐标、长、宽、角度
     *                  2.2 objCnt-2个元件：名字、中心点坐标、长、宽、角度
     * @param board　基板
     */
    void generateBoardData(Job::Board& board);

    /**
     * @brief generateInspectionData
     *          生成检测数据。具体信息如下：
     *              １．board信息
     *              ２．版本信息
     *              ３．上次编辑时间
     * @param inspectionData　检测数据
     */
    void generateInspectionData(Job::InspectionData& inspectionData);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


private:

    DataGeneratorSetting m_dataSetting;  //加载基板所需配置数据的类变量

};
}// End of namespace APP

#endif // DATAGENERATOR_HPP
