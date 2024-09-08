# (C++) => .exe
## 介绍
本文介绍了如何从 ```.cpp```  文件生成对应的可执行文件 ```.exe``` 

⚠️ **注意替换 `[path to vcpkg]` 成本地路径** ⚠️

⚠️ **注意构建失败的时候删除构建文件清理缓存，不然还会一样报错** ⚠️


## CMake
CMake是因为程序员们觉得MakeFile太难写了，所以用CMake创建MakeFile

## MakeFile
这是人干的事情？
如果想看的话,需要加上参数 ```-G "MinGW Makefiles"```
```
cmake -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]\scripts\buildsystems\vcpkg.cmake -B .\hasMakeFiles -S . -G "MinGW Makefiles"
```
## Vcpkg
是一款C++包管理工具,导入第三方库需要安装vcpkg工具.
几种使用方式:


1.命令行中使用cmake的时候指定vcpkg路径

``` 
 cmake -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]\scripts\buildsystems\vcpkg.cmake -B .\build -S .
```

2.设置VisualStudio的CMakePresets.json

下面的这个例子中,设置了一个默认的设置用于build和一个debug配置用于调试
``` 
{
  "version": 2,
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/Debug",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "[path to vcpkg]/scripts/buildsystems/vcpkg.cmake"
      }
    },
    {
      "name": "Debug",
      "inherits": "default",
      "description": "Debug build with debug symbols",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug"
      }
    }
  ]
}
``` 

同理vscode也支持配置,参考:https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-cmd


## 总结
写这篇文档的目的是总结自己在尝试从github上clone一些cpp项目的时候遇到的难处,可能会有各种匪夷所思的坑.

所以我想总结一下,不论使用任意的ide,处理器架构和系统环境打开开源项目.
永远记住先了解并解决以下几个点:
1. 你使用的ide和对应的cpp构建/编译配置文件要如何设置
2. 项目的默认运行环境(通常是有支持windows系统的)
3. 系统的架构是否支持? x64虽然很普及,但是构建的时候是不是使用了默认的x86?
