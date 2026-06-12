#include <fstream>
#include <iostream>
using namespace std;

void drawCantor(ofstream &svg, double x, double y, double width, double height, int depth)
{
    if (depth == 0)
        return;

    // 画当前矩形
    svg << "<rect x=\"" << x << "\" y=\"" << y
        << "\" width=\"" << width << "\" height=\"" << height
        << "\" fill=\"black\"/>\n";

    // 递归左右两段
    double newY = y + height * 2;
    double newWidth = width / 3;

    drawCantor(svg, x - newWidth * 2, newY, newWidth, height, depth - 1); // 左
    drawCantor(svg, x + newWidth * 2, newY, newWidth, height, depth - 1); // 右
}

int main()
{
    ofstream svg("cantor.svg");
    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"300\">\n";
    svg << "<rect width=\"800\" height=\"300\" fill=\"white\"/>\n";

    drawCantor(svg, 400, 20, 600, 15, 6);

    svg << "</svg>\n";
    svg.close();
    cout << "生成 cantor.svg，双击打开" << endl;
    return 0;
}