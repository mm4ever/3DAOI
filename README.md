
## 项目概述
1.项目名称	:3DAOI
2.创建时间	: 20180105
3.创建人	：peter

## 项目根目录结构：
./
├── debug 推荐的调试目录
├── release 推荐的正式版本目录
├── lib   每个子项目编译后的动态库目录
├── include 所有子项目的头文件目录
├── src 存放整个项目的代码文件目录
└── READ.ME 当前阅读文档

#### 创建文件夹
根目录下创建以下文件夹
/release
/debug
/debug/config
/include
/include/Job
/include/SSDK
/lib
/lib/debug
/lib/release

## 配置说明:
#### App
1. 打开qtCreator软件
2. 打开项目:
- 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/APP/APP.pro
- 将 Build directory 设置为: ../../debug
3. 配置完成

#### job
1. 打开项目:
- 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/Job/Job.pro
- 将 Build directory 设置为: ./build/linux/debug
2. 设置Build Steps:
- 依次点击Projects->BuildSteps->AddBuildStep->CustomProcessStep
- 将Command修改为:./debug_build.sh
3. 配置完成

#### sdk
1. 打开项目:
- 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/SSDK/SSDK.pro
- 将 Build directory 设置为: ./build/linux/debug
2. 设置Build Steps:
- 依次点击Projects->BuildSteps->AddBuildStep->CustomProcessStep
- 将Command修改为:./debug_build.sh
3. 配置完成

