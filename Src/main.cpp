/* Opencascade 测试*/
#include <iostream>
#include <gp_Pnt.hxx>                     // 基本点类
#include <BRepPrimAPI_MakeBox.hxx>        // 创建立方体
#include <BRepTools.hxx>                  // 输出几何体到文件

int main() {
    // 创建一个OpenCASCADE的点
    gp_Pnt origin(0.0, 0.0, 0.0);
    std::cout << "Origin Point: ("
              << origin.X() << ", "
              << origin.Y() << ", "
              << origin.Z() << ")" << std::endl;

    // 创建一个长方体 (100 x 50 x 30)
    TopoDS_Shape box = BRepPrimAPI_MakeBox(100.0, 50.0, 30.0);

    // 将几何体导出到文件，验证生成的3D形状
    std::string filename = "box.brep";
    if (BRepTools::Write(box, filename.c_str())) {
        std::cout << "Box shape written to " << filename << std::endl;
    } else {
        std::cerr << "Failed to write box shape to " << filename << std::endl;
    }

    return 0;
}


/* VTK 测试
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int, char *[])
{
    // Create a sphere
    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetCenter(0.0, 0.0, 0.0);
    sphereSource->SetRadius(5.0);

    //mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(sphereSource->GetOutputPort());

    //actor
    vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    //renderer ,renderWindow, renderWindowInteractor.
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    renderer->AddActor(actor);
    renderer->SetBackground(.3, .6, .3); // Background color green
    renderWindow->Render();
    renderWindowInteractor->Start();
    return EXIT_SUCCESS;
}
*/


