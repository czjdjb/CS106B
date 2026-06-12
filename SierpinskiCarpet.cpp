#include <fstream>
#include <iostream>
using namespace std;
ofstream svg("output.svg"); // 全局变量 保证只有绘画步骤在函数里
// 大小 3^5 *2 = 486 画布800*800
int flag = 0;
void PaintSquare(int row, int column, int width, int height)
{
    svg << "<rect x=\"" << row << "\" y=\"" << -column << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"red\"/>\n";
}
void ChangeWH(int &width, int &height)
{
    width += 243;
    height -= 243;
    flag = 1;
}
void SierpinskCarpet(int iteration, int sideLength, int width, int height) // 此处代指x，y 变量标记错误
{
    if (iteration == 0)
    {
        PaintSquare(width, height, sideLength, sideLength);
        return;
    }
    iteration--;
    sideLength /= 3;
    if (flag == 0)
        ChangeWH(width, height);
    for (int i = 0; i < 8; i++)
    {
        if (i == 0)
            SierpinskCarpet(iteration, sideLength, width + sideLength * 1.5, height + sideLength * 1.5); // 1 象限
        if (i == 1)
            SierpinskCarpet(iteration, sideLength, width - sideLength * 1.5, height + sideLength * 1.5); // 2
        if (i == 2)
            SierpinskCarpet(iteration, sideLength, width - sideLength * 1.5, height - sideLength * 1.5); // 3
        if (i == 3)
            SierpinskCarpet(iteration, sideLength, width + sideLength * 1.5, height - sideLength * 1.5); // 4
        if (i == 4)
            SierpinskCarpet(iteration, sideLength, width + sideLength * 1.5, height); // x+
        if (i == 5)
            SierpinskCarpet(iteration, sideLength, width - sideLength * 1.5, height); // x-
        if (i == 6)
            SierpinskCarpet(iteration, sideLength, width, height + sideLength * 1.5); // y+
        if (i == 7)
            SierpinskCarpet(iteration, sideLength, width, height - sideLength * 1.5); // y-
    }
}
int main()
{
    int sideLength = 486;
    int iteration = 5;
    svg << R"(<svg xmlns="http://www.w3.org/2000/svg" viewBox="-400 -400 2000 2000">)" << "\n";
    // PaintPicture();
    SierpinskCarpet(iteration, sideLength, -243, 243);
    svg << "</svg>\n";
    svg.close();
    return 0;
}