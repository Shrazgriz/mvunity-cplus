#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

class V3
{
public:
	/// <summary>
	/// X component
	/// </summary>
	double X;
	/// <summary>
	/// Y component
	/// </summary>
	double Y;
	/// <summary>
	/// Z component
	/// </summary>
	double Z;
	/// <summary>
	/// Create V3 with x y z
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	V3(double x, double y, double z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	/// <summary>
	/// Duplicate V3
	/// </summary>
	/// <param name="point"></param>
	V3(const V3& point)
	{
		X = point.X;
		Y = point.Y;
		Z = point.Z;
	}
	/// <summary>
	/// Create V3 from string "x,y,z"
	/// </summary>
	/// <param name="ValueString"></param>
	/// <param name="spliter"></param>
	V3(string ValueString, char spliter = ',')
	{
		std::stringstream ss(ValueString);
		std::vector<std::string> results; // 用来存储结果
		std::string str; //用来接收每个分割的字符串
		// 开始分隔
		while (getline(ss, str, spliter)) {
			results.push_back(str);
		}
		if (results.size() != 3)
		{
			X = 0;
			Y = 0;
			Z = 0;
		}
		else
		{
			X = std::stod(results[0]);
			Y = std::stod(results[1]);
			Z = std::stod(results[2]);
		}
	}

	/// <summary>
	/// Create V3 from double array
	/// </summary>
	/// <param name="value"></param>
	V3(double value[])
	{
		X = value[0];
		Y = value[1];
		Z = value[2];
	}
	/// <summary>
	/// mod of vector3
	/// </summary>
	double Mod() { return sqrt(X * X + Y * Y + Z * Z); }

	/// <summary>
	/// 向量加法
	/// </summary>
	/// <param name="vector2"></param>
	/// <returns></returns>
	V3 operator +(const V3& vector2)
	{
		V3 result = V3(X + vector2.X, Y + vector2.Y, Z + vector2.Z);
		return result;
	}
	/// <summary>
	/// 向量减法
	/// </summary>
	/// <param name="vector2"></param>
	/// <returns></returns>
	V3 operator -(const V3& vector2)
	{
		return V3(X - vector2.X, Y - vector2.Y, Z - vector2.Z);
	}
	/// <summary>
	/// 标量相乘
	/// </summary>
	/// <param name="vector"></param>
	/// <param name="factor"></param>
	/// <returns></returns>
	V3 operator *(const double factor)
	{
		return V3(factor * X, factor * Y, factor * Z);
	}
	/// <summary>
	/// 逐分量相乘
	/// </summary>
	/// <param name="vector1"></param>
	/// <param name="vector2"></param>
	/// <returns></returns>
	V3 operator *(const V3& vector2)
	{
		return V3(X * vector2.X, Y * vector2.Y, Z * vector2.Z);
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="vector1"></param>
	/// <param name="vector2"></param>
	/// <returns></returns>
	bool operator ==(const V3& vector2)
	{
		return (X == vector2.X) && (Y == vector2.Y) && (Z == vector2.Z);
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="vector1"></param>
	/// <param name="vector2"></param>
	/// <returns></returns>
	bool operator !=(const V3& vector2)
	{
		return (X != vector2.X) || (Y != vector2.Y) || (Z == vector2.Z);
	}
	/// <summary>
	/// Distance to another V3
	/// </summary>
	/// <param name="Destiny"></param>
	/// <returns></returns>
	double Distance(const V3& Destiny)
	{
		return sqrt(((Destiny.X - X) * (Destiny.X - X)) + ((Destiny.Y - Y) * (Destiny.Y - Y)) + ((Destiny.Z - Z) * (Destiny.Z - Z)));
	}

	/// <summary>
	/// Dot product
	/// </summary>
	/// <param name="vector2"></param>
	/// <returns></returns>
	double Dot(const V3& vector2)
	{
		return X * vector2.X + Y * vector2.Y + Z * vector2.Z;
	}
	/// <summary>
	/// Cross product
	/// </summary>
	/// <param name="vector2"></param>
	/// <returns></returns>
	V3 Cross(const V3& vector2)
	{
		double compx = vector2.Z * Y - vector2.Y * Z;
		double compy = vector2.X * Z - vector2.Z * X;
		double compz = vector2.Y * X - vector2.X * Y;
		return V3(compx, compy, compz);
	}
	/// <summary>
	/// Get normalized V3
	/// </summary>
	V3 Normalized() {
		return V3(X / Mod(), Y / Mod(), Z / Mod());
	}

	/// <summary>
	/// Convert to string, format is defined by V3.format, default format is "F4"
	/// </summary>
	/// <returns></returns>
	/// <summary>
	/// Express V2 to string
	/// </summary>
	virtual std::string ToString()
	{
		std::stringstream ss;
		std::string exp;
		ss << X << "," << Y << "," << Z;
		ss >> exp;
		return exp;
	}
};
/// <summary>
	/// (0,0,1)
	/// </summary>
static const V3 Up = V3(0, 0, 1);
/// <summary>
/// (1,0,0)
/// </summary>
static V3 Forward = V3(1, 0, 0);
/// <summary>
/// (0,1,0)
/// </summary>
static V3 Right = V3(0, 1, 0);
/// <summary>
/// (0,0,0)
/// </summary>
static V3 Zero = V3(0, 0, 0);
/// <summary>
/// (1,1,1)
/// </summary>
static V3 Identity = V3(1, 1, 1);

