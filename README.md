# GeoScope

## 项目简介

计算几何学习与演示的软件工具，集成了丰富的几何算法、NURBS 曲线与曲面建模、网格优化以及光线追踪功能，通过动态可视化来深入掌握计算几何与三维建模

## 工具

| 库/工具     | 推荐版本     | 备注                          |
| ----------- | ------------ | ----------------------------- |
| OpenCASCADE | 7.7.0        | 用于几何解析、NURBS、布尔运算 |
| CGAL        | 5.5          | 高效几何算法库，依赖 Boost    |
| OpenMesh    | 8.1          | 网格生成与优化                |
| Eigen       | 3.4          | 矩阵运算、线性代数支持        |
| Embree      | 4.0          | 加速光线追踪性能              |
| OpenMP      | 随编译器版本 | 多线程并行计算                |
| OpenGL      | QT 提供      | 实时渲染框架                  |
| VTK         | 8.2.0        | 用于高级可视化                |
| CMake       | 3.22+        | 项目构建与依赖管理            |
| CUDA        | 11.8         | NVIDIA GPU 加速计算           |

## 目录

```
GeoScope/
├── CMakeLists.txt              # 主 CMake 配置文件
├── README.md                   # 项目简介与使用说明
├── LICENSE                     # 项目许可证文件
├── Docs/                       # 文档目录
│   ├── Guides/                 # 学习和用户指南
│   ├── References/             # 几何算法参考资料
│   └── API/                    # 自动生成的 API 文档（如 Doxygen）
├── Config/                     # 配置文件目录
│   └── DefaultConfig.json      # 默认配置文件
├── Src/                        # 源代码目录
│   ├── MainWindow/             # 主窗口模块
│   │   ├── MainWindow.h        # 主窗口类声明
│   │   ├── MainWindow.cpp      # 主窗口类实现
│   │   ├── MainWindow.ui       # Qt Designer 文件
│   ├── Geometry/               # 几何核心模块
│   │   ├── Geometry.h          # 几何类声明
│   │   ├── Geometry.cpp        # 几何类实现
│   │   ├── FileParser.h        # 几何文件解析基类声明
│   │   ├── FileParser.cpp      # 几何文件解析基类实现
│   │   ├── IGESParser.h        # IGES 文件解析声明
│   │   ├── IGESParser.cpp      # IGES 文件解析实现
│   │   ├── STEPParser.h        # STEP 文件解析声明
│   │   ├── STEPParser.cpp      # STEP 文件解析实现
│   │   ├── OBJParser.h         # OBJ 文件解析声明
│   │   ├── OBJParser.cpp       # OBJ 文件解析实现
│   ├── Algorithms/             # 几何算法模块
│   │   ├── ConvexHull/         # 凸包算法模块
│   │   │   ├── ConvexHull.h
│   │   │   ├── ConvexHull.cpp
│   │   ├── Delaunay/           # Delaunay 三角剖分模块
│   │   │   ├── Delaunay.h
│   │   │   ├── Delaunay.cpp
│   │   ├── Voronoi/            # Voronoi 图生成模块
│   │       ├── Voronoi.h
│   │       ├── Voronoi.cpp
│   ├── NURBS/                  # NURBS 曲线与曲面模块
│   │   ├── NURBSCurve.h        # NURBS 曲线类
│   │   ├── NURBSCurve.cpp
│   │   ├── NURBSSurface.h      # NURBS 曲面类
│   │   ├── NURBSSurface.cpp
│   │   ├── SurfaceFitting.h    # 点云拟合曲面类
│   │   ├── SurfaceFitting.cpp
│   ├── Mesh/                   # 网格生成与优化模块
│   │   ├── MeshGenerator.h     # 网格生成类
│   │   ├── MeshGenerator.cpp
│   │   ├── MeshOptimizer.h     # 网格优化类
│   │   ├── MeshOptimizer.cpp
│   │   ├── MeshQuality.h       # 网格质量分析类
│   │   ├── MeshQuality.cpp
│   ├── Render/                 # 渲染模块
│   │   ├── RayTracer.h         # 光线追踪类
│   │   ├── RayTracer.cpp
│   │   ├── BVH.h               # BVH 加速结构类
│   │   ├── BVH.cpp
│   │   ├── ShaderManager.h     # GLSL 着色器管理类
│   │   ├── ShaderManager.cpp
│   ├── Interaction/            # 用户交互模块
│   │   ├── Canvas.h            # 负责渲染几何体的主画布
│   │   ├── Canvas.cpp
│   │   ├── ControlsPanel.h     # 控制面板类
│   │   ├── ControlsPanel.cpp
│   ├── Utils/                  # 工具模块
│       ├── Logger.h            # 日志工具类
│       ├── Logger.cpp
│       ├── MathHelpers.h       # 数学辅助函数
│       ├── MathHelpers.cpp
│       ├── ConfigLoader.h      # 配置加载类
│       ├── ConfigLoader.cpp
├── Tests/                      # 测试代码目录
│   ├── TestMain.cpp            # 测试入口
│   ├── TestGeometry.cpp        # 几何模块测试
│   ├── TestAlgorithms.cpp      # 算法模块测试
│   ├── TestRender.cpp          # 渲染模块测试
├── Assets/                     # 静态资源目录
│   ├── Models/                 # 示例几何模型（如 STEP, OBJ 文件）
│   ├── Textures/               # 渲染纹理
│   ├── Shaders/                # 着色器代码
│   └── Icons/                  # UI 图标
├── ThirdParty/                 # 第三方库目录
│   ├── README.md               # 第三方库管理说明
│   ├── OpenCASCADE/            # OpenCASCADE 源码（或链接路径）
│   ├── CGAL/                   # CGAL 库
│   ├── Eigen/                  # Eigen 库
│   └── OpenMesh/               # OpenMesh 库
└── Plugins/                    # 插件目录（用于未来扩展）
    ├── ExamplePlugin/          # 示例插件模块
    └── README.md               # 插件开发指南

```

### 项目根目录

| 路径           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| CMakeLists.txt | 主 CMake 配置文件，用于定义项目构建规则和依赖管理。          |
| README.md      | 项目简介与使用说明，包含项目目标、功能列表、构建和运行方法等内容。 |
| LICENSE        | 项目许可证文件，用于定义代码的使用、分发和修改权限（例如 MIT）。 |

### 文档目录 (Docs/)

| 路径             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Docs/Guides/     | 学习和用户指南，例如操作手册、开发文档等。                   |
| Docs/References/ | 几何算法相关的参考资料，可能包含 PDF、数学公式等。           |
| Docs/API/        | 自动生成的 API 文档（如 Doxygen 输出），包含代码接口的详细说明。 |

### 配置目录 (Config/)

| 路径                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| Config/DefaultConfig.json | 默认配置文件，存储应用程序的初始配置（如界面布局、算法参数等）。 |

### 源代码目录 (Src/)

#### 1. MainWindow/

| 路径                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| MainWindow/MainWindow.h   | 主窗口类的声明，负责管理整个应用程序的主流程、模块协调和用户交互。 |
| MainWindow/MainWindow.cpp | 主窗口类的实现，包含菜单栏、工具栏、状态栏以及模块初始化等功能。 |
| MainWindow/MainWindow.ui  | Qt Designer 文件，用于定义主窗口的界面布局（XML 格式）。     |

#### 2. Geometry/

| 路径                | 说明                                                   |
| ------------------- | ------------------------------------------------------ |
| Geometry.h / .cpp   | 几何类，用于表示几何体的核心数据结构（点、线、面等）。 |
| FileParser.h / .cpp | 几何文件解析的基类，定义通用接口（如 parse() 方法）。  |
| IGESParser.h / .cpp | 专门处理 IGES 格式的几何文件解析实现。                 |
| STEPParser.h / .cpp | 专门处理 STEP 格式的几何文件解析实现。                 |
| OBJParser.h / .cpp  | 专门处理 OBJ 格式的几何文件解析实现。                  |

#### 3. Algorithms/

| 路径        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| ConvexHull/ | 包含凸包算法的实现，支持 2D 和 3D 凸包计算，并支持动态可视化演示。 |
| Delaunay/   | 包含 Delaunay 三角剖分算法，支持动态点添加与实时更新。       |
| Voronoi/    | 包含 Voronoi 图生成算法，支持动态点集更新与实时演示。        |

#### 4. NURBS/

| 路径                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| NURBSCurve.h / .cpp     | 定义并实现 NURBS 曲线操作，包括控制点、节点向量、曲率分析等功能。 |
| NURBSSurface.h / .cpp   | 定义并实现 NURBS 曲面操作，包括点云拟合、曲面细分等功能。    |
| SurfaceFitting.h / .cpp | 实现点云拟合曲面的方法，适用于建模应用场景。                 |

#### 5. Mesh/

| 路径                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| MeshGenerator.h / .cpp | 网格生成类，支持曲面离散化（三角网格、四面体网格）。         |
| MeshOptimizer.h / .cpp | 网格优化类，提供 Laplacian 平滑、边折叠简化等算法。          |
| MeshQuality.h / .cpp   | 网格质量分析类，用于评估网格的角度分布、边长分布等质量指标。 |

#### 6. Render/

| 路径                   | 说明                                               |
| ---------------------- | -------------------------------------------------- |
| RayTracer.h / .cpp     | 光线追踪算法的实现，支持阴影、反射、折射的模拟。   |
| BVH.h / .cpp           | BVH 加速结构，用于提高光线追踪性能。               |
| ShaderManager.h / .cpp | 着色器管理类，处理 GLSL 着色器的编译、加载和绑定。 |

#### 7. Interaction/

| 路径                   | 说明                                         |
| ---------------------- | -------------------------------------------- |
| Canvas.h / .cpp        | 主画布类，用于 OpenGL 渲染几何体和算法演示。 |
| ControlsPanel.h / .cpp | 控制面板类，提供参数调节滑块、按钮等控件。   |

#### 8. Utils/

| 路径                  | 说明                                           |
| --------------------- | ---------------------------------------------- |
| Logger.h / .cpp       | 日志工具类，用于记录调试信息、错误信息等。     |
| MathHelpers.h / .cpp  | 数学辅助函数类，用于矩阵运算、向量操作等。     |
| ConfigLoader.h / .cpp | 配置加载工具类，用于解析和读取 JSON 配置文件。 |

### 测试目录 (Tests/)

| 路径               | 说明                                                      |
| ------------------ | --------------------------------------------------------- |
| TestMain.cpp       | 测试入口文件，初始化并运行所有测试用例。                  |
| TestGeometry.cpp   | 几何模块单元测试，验证几何操作的正确性。                  |
| TestAlgorithms.cpp | 算法模块单元测试，验证凸包、Delaunay 等算法实现的正确性。 |
| TestRender.cpp     | 渲染模块测试，验证光线追踪、BVH 等功能。                  |

#### 静态资源目录 (Assets/)

| 路径      | 说明                                |
| --------- | ----------------------------------- |
| Models/   | 示例几何模型（STEP、OBJ 等格式）。  |
| Textures/ | 渲染纹理文件（如 PNG、JPEG 格式）。 |
| Shaders/  | GLSL 着色器代码，用于 OpenGL 渲染。 |
| Icons/    | UI 图标文件（如 PNG、SVG 格式）。   |

#### 第三方库目录 (ThirdParty/)

| 路径         | 说明                         |
| ------------ | ---------------------------- |
| OpenCASCADE/ | OpenCASCADE 源码或编译路径。 |
| CGAL/        | CGAL 几何算法库。            |
| Eigen/       | Eigen 线性代数库。           |
| OpenMesh/    | OpenMesh 网格操作库。        |

#### 插件目录 (Plugins/)

| 路径           | 说明                                   |
| -------------- | -------------------------------------- |
| ExamplePlugin/ | 示例插件模块，用于演示如何扩展功能。   |
| README.md      | 插件开发指南，包含插件接口和实现规范。 |

