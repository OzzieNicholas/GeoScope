# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.16)

# 定义项目名称、版本和使用的编程语言
project(GeoScope VERSION 0.1 LANGUAGES CXX)

# 自动处理UI、MOC和资源文件
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置C++标准为C++17，并且强制要求
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 引入Opencascade和VTK
file(GLOB OCC_LIBS "D:/Opencascade/Opencascade7.7.0/OCCT/win64/vc14/lib/*.lib")
file(GLOB VTK_LIBS "D:/VTK/VTK8.2.0/lib/*.lib")
file(GLOB FFMPEG_LIBS "D:/Opencascade/Opencascade7.7.0/build/ffmpeg-3.3.4-64/lib/*.lib")
file(GLOB TK_LIBS "D:/Opencascade/Opencascade7.7.0/build/tcltk-86-64/lib/*.lib")
file(GLOB FREETYPE_LIBS "D:/Opencascade/Opencascade7.7.0/build/freetype-2.5.5-vc14-64/lib/*.lib")
file(GLOB FREEIMAGE_LIBS "D:/Opencascade/Opencascade7.7.0/build/freeimage-3.17.0-vc14-64/lib/*.lib")

link_libraries(${OCC_LIBS} ${VTK_LIBS} ${FFMPEG_LIBS} ${TK_LIBS} ${FREETYPE_LIBS} ${FREEIMAGE_LIBS})

include_directories(
    D:/Opencascade/Opencascade7.7.0/OCCT/inc
    D:/VTK/VTK8.2.0/include/vtk-8.2
)

# 查找Qt库，这里需要Widgets和LinguistTools模块
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

# 定义翻译文件
set(TS_FILES GeoScope_zh_CN.ts)

# 添加项目的源文件
set(PROJECT_SOURCES
        Src/main.cpp
        Src/MainWindow/MainWindow.cpp
        Src/MainWindow/MainWindow.h
        Src/MainWindow/MainWindow.ui
        ${TS_FILES}
)

# 根据Qt的版本设置不同的编译选项
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    # 如果Qt版本是6或更高，使用qt_add_executable添加可执行文件
    qt_add_executable(GeoScope
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    # 如果使用Qt5，区分是否为安卓平台
    if(ANDROID)
        # 安卓平台需要构建为共享库
        add_library(GeoScope SHARED
            ${PROJECT_SOURCES}
        )
    else()
        # 非安卓平台添加可执行文件
        add_executable(GeoScope
            ${PROJECT_SOURCES}
            Src/Geometry/Geometry.h
            Src/Geometry/Geometry.cpp
            Src/Geometry/FileParser.h Src/Geometry/FileParser.cpp
            Src/Geometry/IGESParser.h Src/Geometry/IGESParser.cpp
            Src/Geometry/STEPParser.h Src/Geometry/STEPParser.cpp
            Src/Geometry/OBJParser.h Src/Geometry/OBJParser.cpp
            Src/Algorithms/ConvexHull/ConvexHull.h Src/Algorithms/ConvexHull/ConvexHull.cpp
            Src/Algorithms/Delaunay/Delaunay.h Src/Algorithms/Delaunay/Delaunay.cpp
            Src/Algorithms/Voronoi/Voronoi.h Src/Algorithms/Voronoi/Voronoi.cpp
            Src/NURBS/NURBSCurve.h Src/NURBS/NURBSCurve.cpp
            Src/NURBS/NURBSSurface.h Src/NURBS/NURBSSurface.cpp
            Src/NURBS/SurfaceFitting.h Src/NURBS/SurfaceFitting.cpp
            Src/Mesh/MeshGenerator.h Src/Mesh/MeshGenerator.cpp
            Src/Mesh/MeshOptimizer.h Src/Mesh/MeshOptimizer.cpp
            Src/Mesh/MeshQuality.h Src/Mesh/MeshQuality.cpp
            Src/Render/RayTracer.h Src/Render/RayTracer.cpp
            Src/Render/BVH.h Src/Render/BVH.cpp
            Src/Render/ShaderManager.h Src/Render/ShaderManager.cpp
            Src/Interaction/Canvas.h Src/Interaction/Canvas.cpp
            Src/Interaction/ControlsPanel.h Src/Interaction/ControlsPanel.cpp
            Src/Utils/Logger.h Src/Utils/Logger.cpp
            Src/Utils/MathHelpers.h Src/Utils/MathHelpers.cpp
            Src/Utils/ConfigLoader.h Src/Utils/ConfigLoader.cpp
            Tests/TestMain.cpp
            Tests/TestGeometry.cpp
            Tests/TestAlgorithms.cpp
            Tests/TestRender.cpp
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# 链接 Qt 的 Widgets 模块
target_link_libraries(GeoScope PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# 设置 Eigen
target_include_directories(GeoScope PRIVATE D:/Eigen/eigen-3.4.0)

# 设置应用程序属性（适用于 macOS 和 Windows）
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GeoScope)
endif()
set_target_properties(GeoScope PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 安装目标设置
include(GNUInstallDirs)
install(TARGETS GeoScope
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 如果是 Qt 6，调用 `qt_finalize_executable`
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GeoScope)
endif()
