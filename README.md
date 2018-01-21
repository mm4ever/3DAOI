[TOC]
## 项目概述
1.项目名称	: 3DAOI<br>
2.创建时间	: 20180118<br>
3.创建人    : peter<br>

## 项目根目录结构：
./
├── release 发布的正式版项目目录<br>
├── lib   每个子项目编译后的动态库目录<br>
├── include 所有子项目的头文件目录<br>
├── src 存放整个项目的代码文件目录<br>
└── README.md 当前阅读文档<br>

#### 创建文件夹
根目录下创建以下文件夹<br>
/release<br>
/release/config<br>
/data/job<br>
/data/xml<br>
/include<br>
/include/Job<br>
/include/SSDK<br>
/lib<br>
/lib/release<br>
>LinuxTerminal中使用以下命令直接创建:<br>
mkdir -p release/config include/Job include/SSDK lib/release data/job data/xml

## 配置说明:
#### APP
1. 打开qtCreator软件
2. 打开项目:
    - 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/APP/APP.pro
    - 将BuildSettings中Edit build configuration:设置为Release
    - 将 Build directory 设置为: ../../release
3. 配置完成

#### Job
1. 打开项目:
    - 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/Job/Job.pro
    - 将BuildSettings中Edit build configuration:设置为Release
    - 将 Build directory 设置为: ./build/linux/release
2. 设置Build Steps:
    - 依次点击Projects->BuildSteps->AddBuildStep->CustomProcessStep
    - 将Command修改为:./release_build.sh
3. 配置完成

#### SSDK
1. 打开项目:
    - 依次点击Welcome->OpenProject->(3DAOI项目路径) 3DAOI/src/SSDK/SSDK.pro
    - 将BuildSettings中Edit build configuration:设置为Release
    - 将 Build directory 设置为: ./build/linux/release
2. 设置Build Steps:
    - 依次点击Projects->BuildSteps->AddBuildStep->CustomProcessStep
    - 将Command修改为:./release_build.sh
3. 配置完成
