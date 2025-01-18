cmake_minimum_required(VERSION 3.16)

project(GeoScope VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES GeoScope_zh_CN.ts)

# 添加项目的源文件
set(PROJECT_SOURCES
        Src/main.cpp
        Src/MainWindow/MainWindow.cpp
        Src/MainWindow/MainWindow.h
        Src/MainWindow/MainWindow.ui
        Src/Geometry/Geometry.h
        Src/Geometry/Geometry.cpp
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GeoScope
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(GeoScope SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(GeoScope
            ${PROJECT_SOURCES}
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
