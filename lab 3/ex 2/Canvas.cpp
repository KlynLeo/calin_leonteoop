#include <iostream>
#include "Canvas.h"
using namespace std;

Canvas::Canvas(int width, int height){
	this->width = width;
	this->height = height;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			canv[i][j] = ' ';
}

void Canvas::Clear() {
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			canv[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int cx = x + ray;
	int cy = y + ray;
	int dist;

	for (int i = x; i <= x + 2 * ray; ++i) {
		for (int j = y; j <= y + 2 * ray; ++j) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				dist = (i - cx) * (i - cx) + (j - cy) * (j - cy);
				if (dist >= ray * ray - ray / 4 && dist <= ray * ray + ray / 4) {
					canv[j][i] = ch;
				}
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	int cx = x + ray;
	int cy = y + ray;
	int dist;

	for (int i = x; i <= x + 2 * ray; ++i) {
		for (int j = y; j <= y + 2 * ray; ++j) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				dist = (i - cx) * (i - cx) + (j - cy) * (j - cy);
				if (dist < ray * ray + ray/4) {
					canv[j][i] = ch;
				}
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++){
		canv[i][left] = ch;
		canv[i][right] = ch;
	}
	for (int i = left; i <= right; i++){
		canv[top][i] = ch;
		canv[bottom][i] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch){
	for (int i = top+1; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			canv[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	canv[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int sx;
	if (x2 > x1)
		sx = 1;
	else
		sx = -1;
	int sy;
	if (y2 > y1)
		sy = 1;
	else
		sy = -1;
	int error = dx + dy;
	int e2;

	while (true)
	{
		canv[y1][x1] = ch;
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			error = error + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2)
				break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++)
			cout << canv[i][j] << " ";
		cout << endl;
	}
}
