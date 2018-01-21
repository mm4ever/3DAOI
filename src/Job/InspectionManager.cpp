#include "InspectionManager.hpp"

using namespace Job;
using namespace SSDK;
using namespace SSDK::DB;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

InspectionManager::InspectionManager()
{

}

InspectionManager::~InspectionManager()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void InspectionManager::init()
{
    try
    {
        loadInspectionSetting(this->m_inspectionSettingPath);
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("InspectionManager init error!");
}

void InspectionManager::loadInspectionSetting(QString &path)
{
    try
    {
        this->m_inspectionSetting.load(path);
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load inspectionSetting file error");
}

void InspectionManager::loadInspectionData(QString &jobPath)
{
    SqliteDB sqlite( jobPath.toStdString() );
    try
    {
        // 打开数据库
        auto isOpened = sqlite.isOpened();
        if( isOpened )
        {
            //>>>----------------------------------------------------------------------------------------------------------
            //1 读取InspectionData表
            // 查询数据表中所有内容
            string selectedString = "select * from InspectionData";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while( true )
            {
                // 逐行读取
                sqlite.step();
                if ( sqlite.latestErrorCode() == SQLITE_DONE )
                {
                    break;
                }
                // 按列读取（第一列为版本号，第二列为上次编辑时间）
                this->m_inspectionData.version() = boost::get<string>(sqlite.columnValue(0));
                this->m_inspectionData.lastEditingTime() = boost::get<string>(sqlite.columnValue(1));
            }

            //>>>----------------------------------------------------------------------------------------------------------
            //2 读取Board表
            selectedString = "select * from Board";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while( true )
            {
                sqlite.step();
                if ( sqlite.latestErrorCode() == SQLITE_DONE )
                {
                    break;
                }
                this->m_inspectionData.board().name() = boost::get<string>(sqlite.columnValue(0));
                this->m_inspectionData.board().rectangle().setWidth( boost::get<double>(sqlite.columnValue(1)) );
                this->m_inspectionData.board().rectangle().setHeight( boost::get<double>(sqlite.columnValue(2)) );
                this->m_inspectionData.board().originPoint().setPosX( boost::get<double>(sqlite.columnValue(3)) );
                this->m_inspectionData.board().originPoint().setPosY( boost::get<double>(sqlite.columnValue(4)) );
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //3 读取Library表
            selectedString = "select * from Library";
            sqlite.prepare( selectedString );
            sqlite.begin();

            // 读取数据表中信息并存到Library容器中
            Library* pLibrary = nullptr;
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                pLibrary = new Library();
                pLibrary->setId( boost::get<int>(sqlite.columnValue(0)) );
                pLibrary->name() = boost::get<string>(sqlite.columnValue(1));
                this->m_inspectionData.board().pLibs().push_back(pLibrary);
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //4 读取MainItem表
            selectedString = "select * from MainItem";
            sqlite.prepare( selectedString );
            sqlite.begin();

            // 使用迭代器访问容器vector中的元素
            vector<Library *>::iterator it = this->m_inspectionData.board().pLibs().begin();
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                // 读取并判断数据表中的算法类型，然后在内存中设置相应的算法类型
                if ( VAR_TO_STR(Alg::AlgType::ALG3D) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    (*it)->mainItem().setPAlg( new Alg3D() );
                }
                else if ( VAR_TO_STR(Alg::AlgType::ALG2D) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    (*it)->mainItem().setPAlg( new Alg2D() );
                }
                else
                {
                    THROW_EXCEPTION("MainItem算法类型读取失败！");
                }
                (*it)->mainItem().setLibId( boost::get<int>(sqlite.columnValue(0)) );
                (*it)->mainItem().setId( boost::get<int>(sqlite.columnValue(1)) );
                (*it)->mainItem().rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                (*it)->mainItem().rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                (*it)->mainItem().rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                (*it)->mainItem().rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                (*it)->mainItem().rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );
                (*it)->mainItem().name() = boost::get<string>(sqlite.columnValue(7));
                ++it;
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //5 读取SubItem表
            selectedString = "select * from SubItem";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                for (vector<Library *>::iterator i = this->m_inspectionData.board().pLibs().begin();
                     i != this->m_inspectionData.board().pLibs().end(); ++i)
                {
                    // 在Library容器中找到与数据表中相应的库的ID号，然后将数据表中的信息存放到SubItem容器中
                    if ( (*i)->id() == boost::get<int>(sqlite.columnValue(0)) )
                    {
                        (*i)->itemList().push_back(SubItem());
                        SubItem& item = (*i)->itemList().back();
                        if ( VAR_TO_STR(Alg::AlgType::ALG2D) == boost::get<string>(sqlite.columnValue(8)) )
                        {
                            item.setPAlg( new Alg2D() );
                        }
                        else if ( VAR_TO_STR(Alg::AlgType::ALG3D) == boost::get<string>(sqlite.columnValue(8)) )
                        {
                            item.setPAlg( new Alg3D() );
                        }
                        else
                        {
                            THROW_EXCEPTION("SubItem算法类型读取失败！");
                        }
                        item.setLibId( boost::get<int>(sqlite.columnValue(0)) );
                        item.setId( boost::get<int>(sqlite.columnValue(1)) );
                        item.rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                        item.rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                        item.rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                        item.rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                        item.rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );
                        item.name() = boost::get<string>(sqlite.columnValue(7));
                        item.setOrder( boost::get<int>(sqlite.columnValue(9)) );
                        break;
                    }
                }
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //6 读取MeasuredObjs表
            selectedString = "select * from MeasuredObjs";
            sqlite.prepare( selectedString );
            sqlite.begin();

            MeasuredObj *pMeasuredObj = nullptr;
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                // 读取并判断数据表中的被测对象类型，然后创建相应的类型的对象
                if (VAR_TO_STR(MeasuredObj::MeasuredObjType::FIDUCIALMARK) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    pMeasuredObj = new FiducialMark();
                }
                else if (VAR_TO_STR(MeasuredObj::MeasuredObjType::COMPONENT) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    pMeasuredObj = new Component();
                }
                else
                {
                    THROW_EXCEPTION("元件类型读取失败！");
                }
                pMeasuredObj->setId( boost::get<int>(sqlite.columnValue(0)) );
                pMeasuredObj->name() = boost::get<string>(sqlite.columnValue(1));
                pMeasuredObj->rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                pMeasuredObj->rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                pMeasuredObj->rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                pMeasuredObj->rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                pMeasuredObj->rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );

                // 在Library容器中找到与数据表中相应的库的ID号，然后设置相应的库的信息
                for (vector<Library *>::iterator i = this->m_inspectionData.board().pLibs().begin();
                     i != this->m_inspectionData.board().pLibs().end(); ++i)
                {
                    if( (*i)->id() == boost::get<int>(sqlite.columnValue(7)) )
                    {
                        pMeasuredObj->setPLib((*i));
                        break;
                    }
                }
                this->m_inspectionData.board().pObjs().push_back(pMeasuredObj);
            }

            sqlite.reset();
            sqlite.close();
        }
        else
        {
            THROW_EXCEPTION("程式加载失败！");
        }
    }
    catch( const CustomException& ex )
    {
        if( sqlite.isOpened() )
        {
            sqlite.reset();
            sqlite.close();
        }
        THROW_EXCEPTION( ex.what() );
    }
}

void InspectionManager::inspect()
{
    try
    {
        this->m_inspectionData.inspect();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("InspectionManager inspect error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
