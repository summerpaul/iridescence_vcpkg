@REM @Author: Xia Yunkai
@REM @Author: Xia Yunkai
@REM @Date:   2023-12-26 17:59:59
@REM @Last Modified by:   Xia Yunkai
@REM Modified time: 2023-12-26 18:00:13


cd build
cmake  -G "Visual Studio 17 2022" .. -A x64
cmake --build . --config Release